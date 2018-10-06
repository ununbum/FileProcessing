#include "Purchase.h"
#include <sstream>


Purchase::Purchase() {

}
Purchase::Purchase(const char *new_id)
{
	Purchase new_s;
	new_s.update_id(new_id);
}
Purchase::Purchase(const Purchase & m)
{
	update_id(m.id);
	update_member(m.member);
	update_lecture(m.lecture);
	update_mileage(m.mileage);
}
Purchase & Purchase::operator = (const Purchase &m)
{
	update_id(m.id);
	update_member(m.member);
	update_lecture(m.lecture);
	update_mileage(m.mileage);

	return *this;
}
bool Purchase::operator == (const Purchase &m)
{
	if (this->id == m.id && this->member == m.member && this->lecture == m.lecture && this->mileage == m.mileage)
		return true;
	else
		return false;
}
bool Purchase::operator != (const Purchase &m)
{
	if (this->id == m.id && this->member == m.member && this->lecture == m.lecture && this->mileage == m.mileage)
		return false;
	else
		return true;
}
bool Purchase::Pack(IOBuffer & Buffer) const {
	int numBytes;
	char buf[256];
	Buffer.Clear();

	string s_id(id, 16);
	string s_lecture(lecture, 12);
	string s_mileage(mileage, 10);

	numBytes = Buffer.Pack(s_id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_lecture.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(member.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_mileage.c_str());
	if (numBytes == -1) return false;
	
	return true;
}
bool Purchase::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[256];

	numBytes = Buffer.Unpack(id, 16);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(lecture, 12);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	member = buf;
	numBytes = Buffer.Unpack(mileage, 10);
	if (numBytes == -1) return false;



	return true;
}

istream & operator >> (istream &is, Purchase &m)
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
	m.update_lecture(token.data());

	getline(iss, token, '|');
	m.update_member(token);

	getline(iss, token, '|');
	m.update_mileage(token.data());
	return is;
}
ostream & operator << (ostream &os, Purchase &m)
{
	cout << "ID : ";
	for (int i = 0; i<16; i++)
		cout << m.id[i];
	cout << endl;
	cout << "LECTURE : ";
	for (int i = 0; i<12; i++)
		cout << m.lecture[i];
	cout << endl;
	cout << "MEMBER : " << m.member << endl;
	cout << "MILEAGE : ";
	for (int i = 0; i<10; i++)
		cout << m.mileage[i];
	cout << endl << endl;

	

	return os;
}