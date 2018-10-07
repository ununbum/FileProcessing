#include "program.h"

using namespace std;
Member & getMember()
{
	Member m;
	string tmp;
	char mil[10];
	cout << "Member Insert" << endl;
	cout << "ID ? :";
	cin >> tmp;
	m.update_id(tmp);
	cout << "Password ? :";
	cin >> tmp;
	m.update_password(tmp);
	cout << "Name ? :";
	cin >> tmp;
	m.update_name(tmp);
	cout << "Phone Number ? :";
	cin >> tmp;
	m.update_number(tmp);
	cout << "Address ? :";
	cin >> tmp;
	m.update_address(tmp);
	cout << "Mileage ? :";
	cin >> mil;
	m.update_mileage(mil);
	return m;
}
Lecture & getLecture()
{
	Lecture m;
	string tmp;
	char ID[12];
	int due;
	char mil[10];
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
	cin >> tmp;
	m.update_teacher(tmp);
	cout << "Textbook ? :";
	cin >> tmp;
	m.update_textbook(tmp);
	return m;
}
Purchase & getPurchase()
{
	Purchase m;
	string tmp;
	char mil[16];
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
int main()
{

	while (1) {
		int menu;
		int data;
		int recaddr;
		Lecture l;
		Purchase p;
		string tmp;
		char ID[16];
		char mil[10];
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
			cout << "Select Data" << endl;
			cin >> data;
		}
		else
			continue;

		switch (menu) {
		case 1:		//	show test
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
			break;
		case 2:		// record test
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
			break;
		
		case 3:		//Search
	
			cout << "ID ?";
			cin >> ID;
			switch (data) {
			case 1:
				SearchMember(ID,&recaddr);
				break;
			case 2:
				SearchLecture(ID,&recaddr);
				break;
			case 3:
				SearchPurchase(ID, &recaddr);
				break;
			}
			break;
		case 4:		//Insert
			switch (data) {
			case 1:
				InsertMember(getMember());
				break;
			case 2:
				InsertLecture(getLecture());
				break;
			case 3:
				InsertPurchase(getPurchase());
				break;
			}
			break;
		case 5:		//Delete
			cout << "ID ?";
			cin >> ID;
			switch (data) {
			case 1:
				DeleteMember(ID);
				break;
			case 2:
				DeleteLecture(ID);
				break;
			case 3:
				DeletePurchase(ID);
				break;
			}
			break;
		case 6:		//Update
			cout << "ID ?";
			cin >> ID;
			switch (data) {
			case 1:
				UpdateMember(SearchMember(ID, &recaddr),recaddr);
				break;
			case 2:
				UpdateLecture(SearchLecture(ID, &recaddr), recaddr);
				break;
			case 3:
				UpdatePurchase(SearchPurchase(ID, &recaddr), recaddr);
				break;
			}
			break;
		}

	}
	return 0;
}