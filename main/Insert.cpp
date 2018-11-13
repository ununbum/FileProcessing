#include "program.h"


int InsertMember(Member  m)
{
	int recaddr;
	string tmp = m.get_id();
	Member min;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> MemberFile(buffer);
	MemberFile.Open("fileOfMember.dat", ios::out);
	min = m;
//	SearchMember(tmp.c_str(), &recaddr);
	if (recaddr != -1)
		return 0;
	return MemberFile.Append(m);
}
int InsertLecture(Lecture  l)
{
	int recaddr;
	Lecture lin;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Lecture> LectureFile(buffer);
	LectureFile.Open("fileOfLecture.dat", ios::out);
	lin = l;
//	SearchLecture(l.get_id(), &recaddr);
	if (recaddr != -1)
		return 0;
	return LectureFile.Append(l);
}
int InsertPurchase(Purchase  p)
{
	int recaddr;
	Purchase pin;
	DelimFieldBuffer buffer('|', 256);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::out);
	pin = p;
//	SearchLecture(p.get_id(), &recaddr);
	if (recaddr != -1)
		return 0;
	return PurchaseFile.Append(p);
}