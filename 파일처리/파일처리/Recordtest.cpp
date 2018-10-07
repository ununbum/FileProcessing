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
	StudentFile.Create("fileOfMember.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Member s;
		ifs >> s;
		int recaddr;
		if ((recaddr = StudentFile.Write(s)) == -1)
			cout << "Write Error!" << endl;

	}
	StudentFile.Close();


	// Read test
	StudentFile.Open("fileOfMember.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Member s;
		StudentFile.Read(s);
		cout << s;
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