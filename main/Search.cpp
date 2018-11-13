#include "program.h"

template <class RecType>
RecType Search(TextIndexedFile<Member> StdIdxedFile, const char * MID, int * recaddr)
{
	RecType find;
	char tmp[10];
	strncpy(tmp, MID, 10);
	StdIdxedFile.Read(tmp, find);
	return find;
}
Lecture SearchLecture(const char * LID, int * recaddr)
{
	Lecture l;
	Lecture lfind;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Lecture> LectureFile(buffer);
	l.update_id(LID);
	LectureFile.Open("fileOfLecture.dat", ios::in);
	while ((*recaddr = LectureFile.Read(lfind)) != -1) {
		if (l == lfind)
		{
			 LectureFile.Close();
			return lfind;
		}
	}

	return lfind;
}
Purchase SearchPurchase_by_memid(const char * PID, int * recaddr)
{
	int flag=0;
	Member p;
	Purchase pfind;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	p.update_id(PID);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	while ((*recaddr = PurchaseFile.Read(pfind)) != -1) {
		if (pfind == p && pfind.get_id()[0] != '#')
		{
			flag = 1;
			cout << pfind;
		}
	}
	cout << endl;
	if(!flag)
		cout << "No result found\n" << endl;
	PurchaseFile.Close();
	return pfind;
}
Purchase SearchPurchase_by_lecid(const char * LID,int *recaddr)
{
	int flag = 0;
	Lecture p;
	Purchase pfind;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	p.update_id(LID);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	while ((*recaddr = PurchaseFile.Read(pfind)) != -1) {
		if (pfind == p && pfind.get_id()[0] != '#')
		{
			flag = 1;
			cout << pfind;
		}
	}
	cout << endl;
	if (!flag)
		cout << "No result found\n" << endl;
	PurchaseFile.Close();
	return pfind;
}
Purchase SearchPurchase(const char * PID, int * recaddr)
{
	Purchase p;
	Purchase pfind;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	p.update_id(PID);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	cout << endl;
	while ((*recaddr = PurchaseFile.Read(pfind)) != -1) {
		if (p == pfind)
		{
			PurchaseFile.Close();
			return pfind;
		}
	}

	return pfind;
}