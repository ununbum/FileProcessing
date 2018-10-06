#include "Student.h"
#include <sstream>


Student::Student() {

}
Student::Student(const char *new_id)
{
	Student new_s;
	new_s.update_id(new_id);
}
Student::Student(const Student & s)
{
	update_id(s.id);
	update_birthday(s.birthday);
	update_name(s.name);
	update_number(s.number);
}
Student & Student::operator = (const Student &s)
{
	update_id(s.id);
	update_birthday(s.birthday);
	update_name(s.name);
	update_number(s.number);

	return *this;
}
bool Student::operator == (const Student &s)
{
	if (this->id == s.id && this->birthday == s.birthday && this->name == s.name && this->number == s.number)
		return true;
	else
		return false;
}
bool Student::operator != (const Student &s)
{
	if (this->id == s.id && this->birthday == s.birthday && this->name == s.name && this->number == s.number)
		return false;
	else
		return true;
}

istream & operator >> (istream &is, Student &s)
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
	s.update_id(token.data());

	getline(iss, token, '|');
	s.update_name(token);

	getline(iss, token, '|');
	s.update_number(token.data());

	getline(iss, token, '|');
	s.update_birthday(token.data());
	return is;
}
ostream & operator << (ostream &os, Student &s)
{
	cout << "ID : ";
	for(int i=0;i<8;i++)
		cout<< s.id[i];
	cout << endl;
	cout << "NAME : " << s.name << endl;
	cout << "NUMBER : ";
	for (int i = 0; i<13; i++)
		cout << s.number[i];
	cout << endl;
	cout << "BIRTHDAY : ";
	for (int i = 0; i<10; i++)
		cout <<  s.birthday[i];
	cout << endl;
	return os;
}