#include "program.h"

int UpdateMember(Member  m, int recaddr,int flag)
{
	int test;
	int length;
	string dummy = m.get_id();
	Member mmod;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> MemberFile(buffer);
	MemberFile.Open("fileOfMember.dat", ios::out | ios::in);
	length = MemberFile.ReadSize(recaddr);
	if (flag == 0)
		mmod = ModifyMember(m);
	else
		mmod = m;
	SearchMember(mmod.get_id().c_str(), &test);
	if (test == -1) {
		DeleteMember(m, recaddr, 0);
		return MemberFile.Update(mmod, recaddr, length);
	}
	else
		return 0;

}
int UpdateLecture(Lecture  l, int recaddr)
{
	int test;
	int length;
	DelimFieldBuffer buffer('|', 256);
	Lecture lmod;
	RecordFile <Lecture> LectureFile(buffer);
	LectureFile.Open("fileOfLecture.dat", ios::out | ios::in);
	length = LectureFile.ReadSize(recaddr);
	lmod = ModifyLecture(l);
	SearchLecture(lmod.get_id(), &test);
	if (test == -1) {
		DeleteLecture(l, recaddr, 0);
		return LectureFile.Update(lmod, recaddr, length);
	}
	else
		return 0;

}
int UpdatePurchase(Purchase  p, int recaddr,int flag)
{
	int test;
	int length;
	Purchase pmod;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::out | ios::in);
	length = PurchaseFile.ReadSize(recaddr);
	pmod = ModifyPurchase(p,flag);
	SearchPurchase(pmod.get_id(), &test);
	if (test == -1) {
		DeletePurchase(p, recaddr);
		return PurchaseFile.Update(pmod, recaddr, length);
	}
	else
		return 0;
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
	cout << "6. Mileage"<<endl;
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
		cout << "Name ? :";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, tmp, '\n');
		m.update_name(tmp);
	case 3:
		cout << "Phone Number ? :";
		cin >> tmp;
		m.update_number(tmp);
		break;
	case 4:
		cout << "Address ? :";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, tmp, '\n');
		m.update_address(tmp);
		break;
	case 5:
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
		getline(cin, tmp, '\n');
		m.update_textbook(tmp);
		break;
	}
	return m;
}
Purchase  ModifyPurchase(Purchase m,int flag)
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