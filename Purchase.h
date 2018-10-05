#include <iostream>
#include <string>
#include "delim.h"

#define LENID 16;
#define LENLEC 12;
#define LENMILE 10;

using namespace std;

class Purchase {
	char id[16];
	string member;
	char lecture[12];
	char mileage[10];

public:
	Purchase();
	Purchase(const char *new_id);
	Purchase(const Purchase & m);

	Purchase & operator = (const Purchase &m);
	bool operator == (const Purchase &m);
	bool operator != (const Purchase &m);
	bool Pack(IOBuffer & Buffer) const;
	bool Unpack(IOBuffer & Buffer);

	friend istream & operator >> (istream &is, Purchase &m);
	friend ostream & operator << (ostream &os, Purchase &m);

	void update_id(const char * new_id) { memcpy(id, new_id, 16); }
	void update_member(const string new_member) { member = new_member; }
	void update_lecture(const char * new_lecture) { memcpy(lecture, new_lecture, 12); }
	void update_mileage(const char * new_mileage) { memcpy(mileage, new_mileage, 10); }
};

istream & operator >> (istream &is, Purchase &m);
ostream & operator << (ostream &os, Purchase &m);