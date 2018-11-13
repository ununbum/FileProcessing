#ifndef LECTURE_H
#define LECTURE_H
#include <iostream>
#include <string>
#include "delim.h"


#define LENID 12;
using namespace std;

class Lecture {
	char Lecture_id[12];
	string subject;
	char Level;
	string Price;
	char Extension;
	int Due_date;
	string Name_Of_Teacher;
	string Textbook;
	string key;
public:
	Lecture();
	Lecture(const char *new_id);
	Lecture(const Lecture & m);

	Lecture& operator =(const Lecture &m);
	bool operator == (const Lecture &m);
	bool operator != (const Lecture &m);
	bool Pack(IOBuffer & Buffer) const;
	bool Unpack(IOBuffer & Buffer);
	friend istream & operator >> (istream &is, Lecture &s);
	friend ostream & operator << (ostream &os, Lecture &s);

	void update_id(const char* new_id) { memcpy(Lecture_id,new_id,12); }
	void update_subject(const string new_subject) { subject = new_subject; }
	void update_level(const char new_level) { Level = new_level; }
	void update_price(const string new_price) { Price = new_price; }
	void update_Ext(const char new_extension) { Extension = new_extension; }
	void update_due(const int new_due) { Due_date = new_due; }
	void update_teacher(const string new_teacher) { Name_Of_Teacher = new_teacher; }
	void update_textbook(const string new_book) { Textbook = new_book; }
	char * get_id(void ) { return Lecture_id; }
	char * Key() {
		key.assign(Lecture_id, 12);
		return (char *)(key.c_str());
	}
};

istream & operator >> (istream &is, Lecture &m);
ostream & operator << (ostream &os, Lecture &m);
#endif