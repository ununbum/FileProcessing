#include "program.h"

using namespace std;
int main()
{
	
	while (1) {
		int menu;
		int recaddr;
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
						m.update_id(new_ID);
						UpdateMember(m, recaddr, 1);
						break;
					case 2:

						cout << "Input New PassWord : ";
						cin >> PWD;
						m.update_password(PWD);
						UpdateMember(m, recaddr, 1);
						break;
					case 3:
						cout << "Delet your ID Succesfully! " << endl;
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
	return 0;
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
	Member m;
	Lecture l;
	Purchase p;
	char ID[17];
	int recaddr;
	int file;
	switch (data) {
	case 1:
		cout << "ID ? ";
		cin >> ID;
		m = SearchMember(ID, &recaddr);
		printMemeber(m, recaddr);
		break;
	case 2:
		cout << "ID ? ";
		cin >> ID;
		l = SearchLecture(ID, &recaddr);
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
		if (InsertMember(getMember()))
			cout << "Insert Sucessfully!" << endl;
		else
			cout << "Insert fail" << endl;
		break;
	case 2:
		cout << endl;
		if (InsertLecture(getLecture()))
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
		m = SearchMember(ID, &recaddr);
		if (DeleteMember(m, recaddr))
			cout << "Delete Sucessfully" << endl;
		else
			cout << "Delete Fail" << endl;
		break;
	case 2:
		cout << endl;
		l = SearchLecture(ID, &recaddr);
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
	int recaddr;
	Member m;
	Lecture l;
	Purchase p;
	cout << "ID ?";
	cin >> ID;
	switch (data) {
	case 1:
		cout << endl;
		m = SearchMember(ID, &recaddr);
		if(UpdateMember(m, recaddr,0))
			cout << "Update Sucessfully" << endl;
		else
			cout << "Update Fail" << endl;
		break;
	case 2:
		cout << endl;
		l = SearchLecture(ID, &recaddr);
		if(UpdateLecture(l, recaddr))
			cout << "Update Sucessfully" << endl;
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
	int menu;
	char ID[17];
	bool res;
	string PWD;
	Member m;
	
	cout << endl<<endl;
	cout << "Enter ID : ";
	cin >> ID;
	cout << "Enter PassWord : ";
	cin >> PWD;
	
	m = SearchMember(ID, recaddr);
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