#include "program.h"

int DeleteMember(Member  m, int recaddr,int flag)
{
	string dummy = m.get_id();
	Member mdel;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> MemberFile(buffer);
	MemberFile.Open("fileOfMember.dat", ios::out);
	for (int i = 0; i <(int)dummy.length(); i++)
		dummy[i] = '#';
	if(flag==1)
		DeletePurchase_by_memid(m);
	mdel = m;
	mdel.update_id(dummy);
	return 	MemberFile.Write(mdel, recaddr);;
}
int DeleteLecture(Lecture  l, int recaddr,int flag)
{
	char dummy[11];
	Lecture ldel;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Lecture> LectureFile(buffer);
	LectureFile.Open("fileOfLecture.dat", ios::out);
	for (int i = 0; i < 10; i++)
		dummy[i] = '#';
	if(flag==1)
		DeletePurchase_by_lecid(l);
	ldel = l;
	ldel.update_id(dummy);
	return	LectureFile.Write(ldel, recaddr);;
}
int DeletePurchase(Purchase  p, int recaddr)
{

	char dummy[17];

	Purchase pdel;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::out);
	for (int i = 0; i < 17; i++)
		dummy[i] = '#';
	pdel = p;
	pdel.update_id(dummy);

	return PurchaseFile.Write(pdel, recaddr);
}
void DeletePurchase_by_memid(Member m)
{
	int recaddr;
	char dummy[17];
	Purchase pdel;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	for (int i = 0; i < 17; i++)
		dummy[i] = '#';

	while ((recaddr = PurchaseFile.Read(pdel)) != -1)
	{
		if (pdel == m)
			DeletePurchase(pdel, recaddr);
	}
}
void DeletePurchase_by_lecid(Lecture m)
{
	int recaddr;
	char dummy[17];
	Purchase pdel;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	for (int i = 0; i < 17; i++)
		dummy[i] = '#';

	while ((recaddr = PurchaseFile.Read(pdel)) != -1)
	{
		if (pdel == m)
			DeletePurchase(pdel, recaddr);
	}
}