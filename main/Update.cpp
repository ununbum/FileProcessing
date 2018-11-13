#include "program.h"

int UpdateMember(Member  m, int recaddr,int flag)
{

	int length;
	string dummy = m.get_id();
	Member mmod;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> MemberFile(buffer);
	MemberFile.Open("fileOfMember.dat", ios::out | ios::in);
	length = MemberFile.ReadSize(recaddr);
	mmod = m;
	return MemberFile.Update(mmod, recaddr, length);
}
int UpdateLecture(Lecture  l, int recaddr,int flag)
{
	int length;
	DelimFieldBuffer buffer('|', 256);
	Lecture lmod;
	RecordFile <Lecture> LectureFile(buffer);
	LectureFile.Open("fileOfLecture.dat", ios::out | ios::in);
	length = LectureFile.ReadSize(recaddr);
	lmod = l;
	return LectureFile.Update(lmod, recaddr, length);

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
