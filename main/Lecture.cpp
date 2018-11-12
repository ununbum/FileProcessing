#include "Lecture.h"
#include <sstream>


Lecture::Lecture() {

}
Lecture::Lecture(const char *new_id)
{
	Lecture new_s;
	new_s.update_id(new_id);
}
Lecture::Lecture(const Lecture & m)
{
	update_id(m.Lecture_id);
	update_subject(m.subject);
	update_level(m.Level);
	update_price(m.Price);
	update_Ext(m.Extension);
	update_due(m.Due_date);
	update_teacher(m.Name_Of_Teacher);
	update_textbook(m.Textbook);
}
Lecture & Lecture::operator = (const Lecture &m)
{
	update_id(m.Lecture_id);
	update_subject(m.subject);
	update_level(m.Level);
	update_price(m.Price);
	update_Ext(m.Extension);
	update_due(m.Due_date);
	update_teacher(m.Name_Of_Teacher);
	update_textbook(m.Textbook);

	return *this;
}
bool Lecture::operator == (const Lecture &m)
{
	int i;
	for (i = 0; i < 12; i++)
	{
		if (this->Lecture_id[i] != m.Lecture_id[i])
			return false;
	}
	return true;
}
bool Lecture::operator != (const Lecture &m)
{
	int i;
	for (i = 0; i < 12; i++)
	{
		if (this->Lecture_id[i] != m.Lecture_id[i])
			return true;
	}
	return false;
}
bool Lecture::Pack(IOBuffer & Buffer) const {
	int numBytes;
	char buf[256];
	Buffer.Clear();

	string s_id(Lecture_id, 12);
	string s_price= Price;
	buf[0] = Level;
	string s_level(buf,1);
	buf[0] = Extension;
	string s_extension(buf,1);
	string s_due = to_string(Due_date);

	numBytes = Buffer.Pack(s_id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(subject.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_level .c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(Price.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_extension.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_due.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(Name_Of_Teacher.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(Textbook.c_str());
	if (numBytes == -1) return false;

	return true;
}
bool Lecture::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[256];

	numBytes = Buffer.Unpack(Lecture_id,12);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	subject = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	Level = buf[0];
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	Price = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	Extension = buf[0];
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	Due_date = atoi(buf);
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	Name_Of_Teacher = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	Textbook = buf;

	return true;
}

istream & operator >> (istream &is, Lecture &m)
{
	string st;
	is.exceptions(istream::failbit | istream::badbit);

	try {
		getline(is, st);
	}
	catch (istream::failure e)
	{
		return is;
	}

	istringstream iss(st);
	string token;

	getline(iss, token, '|');
	m.update_id(token.data());

	getline(iss, token, '|');
	m.update_subject(token.data());

	getline(iss, token, '|');
	m.update_level(token.data()[0]);

	getline(iss, token, '|');
	m.update_price(token.data());

	getline(iss, token, '|');
	m.update_Ext(token.data()[0]);

	getline(iss, token, '|');
	m.update_due(atoi(token.data()));

	getline(iss, token, '|');
	m.update_teacher(token.data());

	getline(iss, token, '|');
	m.update_textbook(token.data());

	return is;
}
ostream & operator << (ostream &os, Lecture &m)
{
	cout << "ID : ";
	for (int i = 0; i<12; i++)
		cout << m.Lecture_id[i];
	cout << endl;
	cout << "SUBJECT : " << m.subject << endl;
	cout << "LEVEL : " << m.Level << endl;
	cout << "PRICE : " << m.Price << endl;
	cout << "EXTENSION : " << m.Extension << endl;
	cout << "DUE DATE : " << m.Due_date << endl;
	cout << "NAME OF TEACHER : " << m.Name_Of_Teacher << endl;
	cout << "TEXTBOOK : " << m.Textbook << endl << endl;
	return os;
}