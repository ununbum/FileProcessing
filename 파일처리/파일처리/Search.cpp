#include "program.h"


Member SearchMember(const char * MID, int * recaddr)
{
	Member m;
	Member mfind;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> MemberFile(buffer);
	m.update_id(MID);
	MemberFile.Open("fileOfMember.dat", ios::in);
	while ((*recaddr = MemberFile.Read(mfind)) != -1) {
		if (m == mfind)
		{
			MemberFile.Close();
			return mfind;
		}
	}
	return mfind;
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
void SearchPurchase_by_memid(const char * PID, int * recaddr)
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

}
void SearchPurchase_by_lecid(const char * LID,int *recaddr)
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