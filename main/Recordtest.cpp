#include "program.h"
using namespace std;

int membertest()
{
	int n;
	ifstream ifs("listOfMember.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	ifs.seekg(0, ios::beg);
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');


	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> StudentFile(buffer);
	
	// Write test
	StudentFile.Create("fileOfMember.dat", ios::in | ios::out | ios::trunc);
	Member s;
	//test user pack
	s.update_id("TestUser");
	s.update_password("T1234");
	s.update_mileage("0000000000");
	s.update_level(9);
	int recaddr;
	if ((recaddr = StudentFile.Write(s)) == -1)
		cout << "Write Error!" << endl;
	//admin pack
	s.update_id("admin");
	s.update_password("adminpass");
	s.update_level(1);
	if ((recaddr = StudentFile.Write(s)) == -1)
		cout << "Write Error!" << endl;
	for (int i = 0; i < n; i++) {
		Member s;
		ifs >> s;
		s.update_level(9);
		int recaddr;
		if ((recaddr = StudentFile.Write(s)) == -1)
			cout << "Write Error!" << endl;

	}
	

	
	StudentFile.Close();


	return 0;
}

int purchasetest()
{
	int n;
	ifstream ifs("listOfPurchase.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	ifs.seekg(0, ios::beg);
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');


	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> StudentFile(buffer);

	// Write test
	StudentFile.Create("fileOfPurchase.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Purchase s;
		ifs >> s;
		int recaddr;
		if ((recaddr = StudentFile.Write(s)) == -1)
			cout << "Write Error!" << endl;

	}
	StudentFile.Close();


	// Read test
	StudentFile.Open("fileOfPurchase.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Purchase s;
		StudentFile.Read(s);
		cout << s;
	}
	StudentFile.Close();

	return 0;
}

int lecturetest()
{
	int n;
	ifstream ifs("listOfLecture.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	ifs.seekg(0, ios::beg);
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');


	DelimFieldBuffer buffer('|', 256);
	RecordFile <Lecture> StudentFile(buffer);
	TextIndex LectureIndex(2000);
	// Write test
	StudentFile.Create("fileOfLecture.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Lecture s;
		ifs >> s;
		int recaddr;
		if ((recaddr = StudentFile.Write(s)) == -1)
			cout << "Write Error!" << endl;
;
	}
	StudentFile.Close();


	// Read test
	StudentFile.Open("fileOfLecture.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Lecture s;
		StudentFile.Read(s);
		cout << s;
	}
	StudentFile.Close();

	return 0;
}