#include <iostream>
#include <string>
#include "delim.h"


#define LENID 8
#define LENNUM 13
#define LENBIR 10
#define STDMAXBUF 256

using namespace std;


class Student {
	char id[8];
	string name;
	char number[13];
	char birthday[10];

public:
	Student();
	Student(const char *new_id);
	Student(const Student & s);

	Student & operator = (const Student &s);
	bool operator == (const Student &s);
	bool operator != (const Student &s);

	friend istream & operator >> (istream &is, Student &s);
	friend ostream & operator << (ostream &os, Student &s);

	void update_id(const char * new_id) { memcpy(id, new_id, 8); }
	void update_name(const string new_name) { name = new_name; }
	void update_number(const char * new_number) { memcpy(number, new_number, 13); }
	void update_birthday(const char * new_birthday) { memcpy(birthday, new_birthday, 10); }
};

istream & operator >> (istream &is, Student &s);
ostream & operator << (ostream &os, Student &s);

