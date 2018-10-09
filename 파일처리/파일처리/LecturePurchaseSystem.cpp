#include "program.h"

using namespace std;
int main()
{

	while (1) {
		int menu;
		int data;
		cout << "1. Show list"<<endl;
		cout << "2. Make Record File" << endl;
		cout << "3. Search Record" << endl;
		cout << "4. Insert Record" << endl;
		cout << "5. Delete Record" << endl;
		cout << "6. Update Record" << endl;
		cout << "0. EXIT"<<endl <<endl;
		cout << "Select Menu : ";
		cin >> menu;
		if (!menu)
			break;
		else if (menu >= 1 && menu <= 6)
		{
			
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
		if (InsertMember(getMember()))
			cout << "Insert Sucessfully!" << endl;
		else
			cout << "Insert fail" << endl;
		break;
	case 2:
		if (InsertLecture(getLecture()))
			cout << "Insert Sucessfully!" << endl;
		else
			cout << "Insert fail" << endl;
		break;
	case 3:
		if (InsertPurchase(getPurchase()))
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
		m = SearchMember(ID, &recaddr);
		DeleteMember(m, recaddr);
		break;
	case 2:
		l = SearchLecture(ID, &recaddr);
		DeleteLecture(l, recaddr);
		break;
	case 3:
		p = SearchPurchase(ID, &recaddr);
		DeletePurchase(p, recaddr);
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
		m = SearchMember(ID, &recaddr);
		UpdateMember(m, recaddr);
		break;
	case 2:
		l = SearchLecture(ID, &recaddr);
		UpdateLecture(l, recaddr);
		break;
	case 3:
		p = SearchPurchase(ID, &recaddr);
		UpdatePurchase(p, recaddr);
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
Purchase  getPurchase()
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
	cout << "Member ID ? :";
	cin >> tmp;
	m.update_member(tmp);
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