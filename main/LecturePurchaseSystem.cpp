#include "program.h"

using namespace std;

Member m;
Lecture l;
DelimFieldBuffer buf('|', 256);
TextIndexBuffer idxbuf_mem(10, 2000);
TextIndexBuffer idxbuf_lec(12, 2000);
TextIndexedFile<Member> MemIdxedFile(buf, 10, 2000);
TextIndexedFile<Lecture> LecIdxedFile(buf, 12, 2000);
BufferFile MemIdxFile(idxbuf_mem);
BufferFile LecIdxFile(idxbuf_lec);
char tmp[14];

int main()
{
	make_index_member();
	make_index_lecture();

	char Memind[20] = "fileOfMember";
	char Lecind[20] = "fileOfLecture";
	MemIdxedFile.Open(Memind);
	LecIdxedFile.Open(Lecind);
	while (1) {
		int menu;
		int recaddr;
		// make index member;
		

		cout << "Welcome to LecturePurchaseSystem" << endl;
		cout << "1.login" << endl;
		cout << "2. exit" << endl;
		cin >> menu;
		if (menu == 1)
		{
			Member m = login(&recaddr);
			if (m.get_level()==1 && recaddr!=-1)
			{
				while (1) {

					int data;
					cout << endl;
					
					cout << "1. Show list" << endl;
					cout << "2. Make Record File" << endl;
					cout << "3. Search Record" << endl;
					cout << "4. Insert Record" << endl;
					cout << "5. Delete Record" << endl;
					cout << "6. Update Record" << endl;
					cout << "0. EXIT" << endl << endl;
					cout << "Select Menu : ";
					cin >> menu;

					if (!menu)
						break;
					else if (menu >= 1 && menu <= 6)
					{
						cout << endl;
						cout << "1. Member" << endl;
						cout << "2. Lecture" << endl;
						cout << "3. Purchase" << endl;
						cout << "Select Data : ";
						cin >> data;
					}
					else
						continue;

					switch (menu) {
					case 1:		//	show test
						show(data);
						break;
					case 2:		// record test
						make(data);
						make_index_member();
						make_index_lecture();
						break;

					case 3:		//Search
						search_data(data);
						break;
					case 4:		//Insert
						insert(data);
						break;
					case 5:		//Delete
						delete_data(data);
						break;

					case 6:		//Update
						update_data(data);
						break;
					default:
						cout << "InPut Error!" << endl;
						break;
					}
				}
			}
			else if (m.get_level() == 9 && recaddr != -1)
			{
				while (1)
				{
					string PWD;
					int test;
					cin.ignore();
					cout << "1.Modify ID" << endl;
					cout << "2.Modify PassWord" << endl;
					cout << "3.Delete MYID" << endl;
					cout << "4.Search Lecture" << endl;
					cout << "5.Search My Purchase Record" << endl;
					cout << "6.Logout" << endl;
					cin >> menu;
					if (menu == 6)
						break;
					switch (menu)
					{
					case 1:
						char new_ID[17];
						
						cout << "Input New ID : ";
						cin >> new_ID;
						test = MemIdxedFile.Read(new_ID, m);
						if (test > 0)
						{
							cout << "There is same ID" << endl;
							break;
						}
						DeleteMember(m, recaddr, 1);
						strncpy(tmp, m.Key(), 10);
						m.update_id(new_ID);
						recaddr = UpdateMember(m, recaddr, 1);
						MemIdxedFile.Update(tmp, new_ID,recaddr);
						break;
					case 2:

						cout << "Input New PassWord : ";
						cin >> PWD;
						DeleteMember(m, recaddr, 1);
						m.update_password(PWD);
						test = UpdateMember(m, recaddr, 1);
						if (test != recaddr)
						{
							strncpy(tmp, m.Key(), 10);
							recaddr = MemIdxedFile.Update(tmp, tmp, test);
						}
						break;
					case 3:
						cout << "Delet your ID Succesfully! " << endl;
						strncpy(tmp, m.get_id().c_str(), 10);
						MemIdxedFile.Delete(tmp);
						DeleteMember(m, recaddr, 1);
						break;
					case 4:
						search_data(2);
						break;
					case 5:
						Purchase p;
						cout << "1. Add Purchase" << endl;
						cout << "2. Search My Purchase Record" << endl;
						cout << "3. Modify My Purchase Record" << endl;
						cout << "4. Delete My Purchase Record" << endl;
						cin >> menu;
						switch (menu)
						{
						case 1:
							cout << endl;
							if (InsertPurchase(getPurchase(1)))
								cout << "Insert Sucessfully!" << endl;
							else
								cout << "Insert fail" << endl;
							break;
						case 2:
							SearchPurchase_by_memid(m.get_id().c_str(), &recaddr);
							break;
						case 3:
							
							cout << endl;
							p = SearchPurchase_by_memid(m.get_id().c_str(), &recaddr);
							if (UpdatePurchase(p, recaddr, 1))
								cout << "Update Sucessfully" << endl;
							else
								cout << "Update Fail" << endl;
						case 4:
							cout << endl;
							p = SearchPurchase(m.get_id().c_str(), &recaddr);
							if (DeletePurchase(p, recaddr))
								cout << "Delete Sucessfully" << endl;
							else
								cout << "Delete Fail" << endl;
							break;
						}

						break;
					}
					if (menu == 3)
						break;
				}
			}
			else
			{
				int out;
				cout << "login fail!!" << endl;
				cout << "press any number to continue" << endl;
				cin >> out;
				if (out >= 0 && out < 9)
				{
					cin.ignore();
					continue;
				}
				else
				{
					cout << "bye~!" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "bye~!" << endl;
			break;
		}
	}
	MemIdxedFile.Close();
	LecIdxedFile.Close();
	return 0;
}
void make_index_member()
{
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> MemberFile(buffer);
	TextIndex MemberIndex(2000);
	
	char name[17] = "fileOfMember.ind";
	if (MemIdxFile.Open(name, ios::in))
	{
		MemIdxFile.Close();
	}
	else {
		MemberFile.Open("fileOfMember.dat", ios::in);
		while (1) {
			Member m;
			int recaddr = MemberFile.Read(m);
			if (recaddr == -1) break;
			//Todo...
			MemberIndex.Insert(m.Key(), recaddr);
		}
		MemberFile.Close();


		MemIdxFile.Create("fileOfMember.ind", ios::out | ios::trunc);
		MemIdxFile.Rewind();
		idxbuf_mem.Pack(MemberIndex);
		int result = MemIdxFile.Write();
		MemIdxFile.Close();
	}
	return;
}
void make_index_lecture()
{
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Lecture> LectureFile(buffer);
	TextIndex LectureIndex(2000);
	char name[18] = "fileOfLecture.ind";
	if (LecIdxFile.Open(name,ios::in))
	{

		LecIdxFile.Close();
	}
	else {
		LectureFile.Open("fileOfLecture.dat", ios::in);
		while (1) {
			Lecture l;
			int recaddr = LectureFile.Read(l);
			if (recaddr == -1) break;
			//Todo...
			LectureIndex.Insert(l.Key(), recaddr);
		}
		LectureFile.Close();


		LecIdxFile.Create("fileOfLecture.ind", ios::out | ios::trunc);
		LecIdxFile.Rewind();
		idxbuf_lec.Pack(LectureIndex);
		int result = LecIdxFile.Write();
		LecIdxFile.Close();
	}
	return;
}
void show(int data)
{
	switch (data) {
	case 1:
		ShowMember();
		break;
	case 2:
		ShowLecture();
		break;
	case 3:
		ShowPurchase();
		break;
	}
}
void make( int data)
{
	switch (data) {
	case 1:
		membertest();
		break;
	case 2:
		lecturetest();
		break;
	case 3:
		purchasetest();
		break;
	}
}
void search_data(int data)
{
	
	Purchase p;
	char ID[17];
	int recaddr;
	int file;
	switch (data) {
	case 1:
		cout << "ID ? ";
		cin >> ID;
		strncpy(tmp,ID, 10);
		recaddr = MemIdxedFile.Read(tmp, m);
		printMemeber(m, recaddr);
		break;
	case 2:
		cout << "ID ? ";
		cin >> ID;
		strncpy(tmp, ID, 12);
		recaddr = LecIdxedFile.Read(tmp, l);
		printLecture(l, recaddr);
		break;
	case 3:
		cout << "1. MemberID" << endl;
		cout << "2. LectureID" << endl;
		cout << "3. PurchaseID" << endl;
		cout << "Select Data";
		cin >> file;
		cout << "ID ? ";
		cin >> ID;
		switch (file) {
		case 1:
			SearchPurchase_by_memid(ID, &recaddr);
			break;
		case 2:
			SearchPurchase_by_lecid(ID, &recaddr);
			break;
		case 3:
			p = SearchPurchase(ID, &recaddr);
			printPurchase(p, recaddr);
			break;
		}
		break;
	}
}
void insert(int data)
{

	switch (data) {
	case 1:
		cout << endl;
		m = getMember();
		m.update_level(9);
		if (MemIdxedFile.Append(m))
			cout << "Insert Sucessfully!" << endl;
		else
			cout << "Insert fail" << endl;
		break;
	case 2:
		cout << endl;
		l = getLecture();
		l.update_level(9);
		if (LecIdxedFile.Append(l))
			cout << "Insert Sucessfully!" << endl;
		else
			cout << "Insert fail" << endl;
		break;
	case 3:
		cout << endl;
		if (InsertPurchase(getPurchase(0)))
			cout << "Insert Sucessfully!" << endl;
		else
			cout << "Insert fail" << endl;
		break;
	}
}
void delete_data(int data)
{
	Member m;
	Lecture l;
	Purchase p;
	char ID[17];
	int recaddr;
	cout << "ID ? ";
	cin >> ID;
	switch (data) {
	case 1:
		cout << endl;
		strncpy(tmp, ID, 10);
		recaddr = MemIdxedFile.Read(tmp, m);
		strncpy(tmp, m.Key(), 10);
		MemIdxedFile.Delete(tmp);
		if (DeleteMember(m, recaddr,1))
			cout << "Delete Sucessfully" << endl;
		else
			cout << "Delete Fail" << endl;
		break;
	case 2:
		cout << endl;
		strncpy(tmp, ID, 10);
		recaddr = LecIdxedFile.Read(tmp, l);
		strncpy(tmp, l.Key(), 12);
		LecIdxedFile.Delete(tmp);
		if(DeleteLecture(l, recaddr))
			cout << "Delete Sucessfully" << endl;
		else
			cout << "Delete Fail" << endl;
		break;
	case 3:
		cout << endl;
		p = SearchPurchase(ID, &recaddr);
		if(DeletePurchase(p, recaddr))
			cout << "Delete Sucessfully" << endl;
		else
			cout << "Delete Fail" << endl;
		break;
	}
}
void update_data(int data)
{
	char ID[17];
	int test;
	int recaddr;
	Member mnew;
	Member mfind;
	Lecture lnew;
	Lecture lfind;
	Purchase p;
	cout << "ID ?";
	cin >> ID;
	switch (data) {
	case 1:
		cout << endl;
		strncpy(tmp, ID, 10);
		recaddr = MemIdxedFile.Read(tmp, m);
		if (recaddr<0)
		{
			cout << "There is no ID" << endl;
			break;
		}
		DeleteMember(m, recaddr, 1);
		mnew = ModifyMember(m);
		strncpy(tmp, mnew.Key(), 10);
		test = MemIdxedFile.Read(tmp, mfind);
		if (test > 0 && strcmp(tmp, m.Key())!=0)
		{
			cout << "There is same ID" << endl;
			break;
		}
		test = UpdateMember(mnew, recaddr, 1);
		if (test != recaddr)
		{
			//char tmp2[14];
			//strncpy(tmp2, m.Key(), 10);
			recaddr = MemIdxedFile.Update(m.Key(),mnew.Key(), test);
		}
		else 
			MemIdxedFile.Update(m.Key(), mnew.Key(), recaddr);
		if(recaddr)
		{
			cout << "Update Sucessfully" << endl;
		}
		else
			cout << "Update Fail" << endl;
		break;
	case 2:
		cout << endl;
		strncpy(tmp, ID, 12);
		recaddr = LecIdxedFile.Read(tmp, l);
		if (recaddr<0)
		{
			cout << "There is no ID" << endl;
			break;
		}
		DeleteLecture(l, recaddr, 1);
		lnew = ModifyLecture(l);
		strncpy(tmp, lnew.Key(), 12);
		test = LecIdxedFile.Read(tmp, lfind);
		if (test > 0 && strcmp(tmp, l.Key()) != 0)
		{
			cout << "There is same ID" << endl;
			break;
		}
		test = UpdateLecture(lnew, recaddr, 1);
		if (test != recaddr)
		{
			recaddr = LecIdxedFile.Update(l.Key(),lnew.Key(), test);
		}
		else
			LecIdxedFile.Update(tmp, lnew.Key(), recaddr);
		if (recaddr)
		{
			cout << "Update Sucessfully" << endl;
		}
		else
			cout << "Update Fail" << endl;
		break;
	case 3:
		cout << endl;
		p = SearchPurchase(ID, &recaddr);
		if(UpdatePurchase(p, recaddr,0))
			cout << "Update Sucessfully" << endl;
		else
			cout << "Update Fail" << endl;
		break;
	}
}
Member  getMember()
{
	Member m;
	string tmp;
	char mil[11];
	cout << "Member Insert" << endl;
	cout << "ID ? :";
	cin >> tmp;
	m.update_id(tmp);
	cout << "Password ? :";
	cin >> tmp;
	m.update_password(tmp);
	cout << "Name ? :";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,tmp,'\n');
	m.update_name(tmp);
	cout << "Phone Number ? :";
	cin >> tmp;
	m.update_number(tmp);
	cout << "Address ? :";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, tmp, '\n');
	m.update_address(tmp);
	cout << "Mileage ? :";
	cin >> mil;
	m.update_mileage(mil);
	return m;
}
Lecture  getLecture()
{
	Lecture m;
	string tmp;
	char ID[13];
	int due;
	cout << "Lecture Insert" << endl;

	cout << "ID ? :";
	cin >> ID;
	m.update_id(ID);

	cout << "Subject ? :";
	cin >> tmp;
	m.update_subject(tmp);

	cout << "Level ? :";
	cin >> ID[0];
	m.update_level(ID[0]);

	cout << "Price ? :";
	cin >> tmp;
	m.update_price(tmp);

	cout << "Extension ? :";
	cin >> ID[0];
	m.update_Ext(ID[0]);

	cout << "Due date ? :";
	cin >> due;
	m.update_due(due);

	cout << "Name of teacher ? :";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, tmp, '\n');
	m.update_teacher(tmp);

	cout << "Textbook ? :";
	getline(cin, tmp, '\n');
	m.update_textbook(tmp);

	return m;
}
Purchase  getPurchase(int flag)
{
	Purchase m;
	string tmp;
	char mil[17];
	cout << "Purchase Insert" << endl;
	cout << "ID ? :";
	cin >> mil;
	m.update_id(mil);
	cout << "Lecture ID ? :";
	cin >> mil;
	m.update_lecture(mil);
	if (flag == 0)
	{
		cout << "Member ID ? :";
		cin >> tmp;
		m.update_member(tmp);
	}
	cout << "Mileage ? :";
	cin >> mil;
	m.update_mileage(mil);
	return m;
}
void printMemeber(Member m,int recaddr)
{
	cout << endl;
	if (recaddr == -1)
		cout << "No result found\n" << endl;
	else
		cout << m;
}
void printLecture(Lecture l,int recaddr)
{
	cout << endl;
	if (recaddr == -1)
		cout << "No result found\n" << endl;
	else
		cout << l;
}
void printPurchase(Purchase p,int recaddr)
{
	cout << endl;
	if (recaddr == -1)
		cout << "No result found\n" << endl;
	else
		cout << p;
}
Member login(int * recaddr)
{
	char ID[17];
	bool res;
	string PWD;
	Member m;
	
	cout << endl<<endl;
	cout << "Enter ID : ";
	cin >> ID;
	cout << "Enter PassWord : ";
	cin >> PWD;
	
//	m = SearchMember(ID, recaddr);
	char tmp[10];
	strncpy(tmp, ID, 10);
	*recaddr = MemIdxedFile.Read(tmp, m);

	if (*recaddr == -1)
	{
		cout << "There is no ID Matched" << endl;
		return m;
	}
	res = m.check_password(PWD);
	if (!res)
	{
		cout << "Wrong Password!" << endl;
		*recaddr = -1;
		return m;
	}
	return m;
}
Member  ModifyMember(Member m)
{
	string tmp;
	char mil[11];
	int mod;
	cout << "Member Modify" << endl;
	cout << "1. ID" << endl;
	cout << "2. Password " << endl;
	cout << "3. Name " << endl;
	cout << "4. Phone Number" << endl;
	cout << "5. Address " << endl;
	cout << "6. Mileage" << endl;
	cin >> mod;
	switch (mod) {
	case 1:
		cout << "ID ? :";
		cin >> tmp;
		m.update_id(tmp);
		break;
	case 2:
		cout << "Password ? :";
		cin >> tmp;
		m.update_password(tmp);
		break;
	case 3:
		cout << "Name ? :";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, tmp, '\n');
		m.update_name(tmp);
		break;
	case 4:
		cout << "Phone Number ? :";
		cin >> tmp;
		m.update_number(tmp);
		break;
	case 5:
		cout << "Address ? :";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, tmp, '\n');
		m.update_address(tmp);
		break;
	case 6:
		cout << "Mileage ? :";
		cin >> mil;
		m.update_mileage(mil);
		break;
	}
	return m;
}
Lecture  ModifyLecture(Lecture m)
{
	string tmp;
	char ID[13];
	int due;
	int mod;
	cout << "Lecture Modify" << endl;
	cout << "1. ID" << endl;
	cout << "2. Subject " << endl;
	cout << "3. Level " << endl;
	cout << "4. Price" << endl;
	cout << "5. Extension " << endl;
	cout << "6. Due Date" << endl;
	cout << "7. Name of teacher" << endl;
	cout << "8. Textbook" << endl;
	cin >> mod;

	switch (mod) {
	case 1:
		cout << "ID ? :";
		cin >> ID;
		m.update_id(ID);
		break;
	case 2:
		cout << "Subject ? :";
		cin >> tmp;
		m.update_subject(tmp);
		break;
	case 3:
		cout << "Level ? :";
		cin >> ID[0];
		m.update_level(ID[0]);
		break;
	case 4:
		cout << "Price ? :";
		cin >> tmp;
		m.update_price(tmp);
		break;
	case 5:
		cout << "Extension ? :";
		cin >> ID[0];
		m.update_Ext(ID[0]);
		break;
	case 6:
		cout << "Due date ? :";
		cin >> due;
		m.update_due(due);
		break;
	case 7:
		cout << "Name of teacher ? :";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, tmp, '\n');
		m.update_teacher(tmp);
		break;
	case 8:
		cout << "Textbook ? :";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, tmp, '\n');
		m.update_textbook(tmp);
		break;
	}
	return m;
}
Purchase  ModifyPurchase(Purchase m, int flag)
{
	string tmp;
	char mil[17];
	int mod;
	cout << "Purchase Modify" << endl;
	cout << "1. ID" << endl;
	cout << "2. Lecture ID " << endl;
	cout << "3. Member ID " << endl;
	cout << "4. Mileage" << endl;
	cin >> mod;
	switch (mod) {
	case 1:
		if (flag == 0)
		{
			cout << "ID ? :";
			cin >> mil;
			m.update_id(mil);
		}
		else
			cout << "Access Denied" << endl;
		break;
	case 2:
		cout << "Lecture ID ? :";
		cin >> mil;
		m.update_lecture(mil);
		break;
	case 3:
		cout << "Member ID ? :";
		cin >> tmp;
		m.update_member(tmp);
		break;
	case 4:
		cout << "Mileage ? :";
		cin >> mil;
		m.update_mileage(mil);
		break;
	}
	return m;
}