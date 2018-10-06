#include "Member.h"
#include <sstream>


Member::Member() {

}
Member::Member(const string new_id)
{
	Member new_s;
	new_s.update_id(new_id);
}
Member::Member(const Member & m)
{
	update_id(m.member_id);
	update_password(m.password);
	update_name(m.name);
	update_number(m.phone_number);
	update_address(m.address);
	update_mileage(m.mileage);

}
Member & Member::operator = (const Member &m)
{
	update_id(m.member_id);
	update_password(m.password);
	update_name(m.name);
	update_number(m.phone_number);
	update_address(m.address);
	update_mileage(m.mileage);

	return *this;
}
bool Member::operator == (const Member &m)
{
	if (this->member_id == m.member_id && this->password == m.password && this->name == m.name && this->phone_number == m.phone_number && this->address == m.address && this->mileage == m.mileage)
		return true;
	else
		return false;
}
bool Member::operator != (const Member &m)
{
	if (this->member_id != m.member_id && this->password != m.password && this->name != m.name && this->phone_number != m.phone_number && this->address != m.address && this->mileage != m.mileage)
		return false;
	else
		return true;
}

istream & operator >> (istream &is, Member &m)
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
	m.update_password(token);

	getline(iss, token, '|');
	m.update_name(token.data());

	getline(iss, token, '|');
	m.update_number(token.data());

	getline(iss, token, '|');
	m.update_address(token.data());

	getline(iss, token, '|');
	m.update_mileage(token.data());

	return is;
}
bool Member::Pack(IOBuffer & Buffer) const {
	int numBytes;
	char buf[256];
	Buffer.Clear();

	string s_mile(mileage, 10);

	numBytes = Buffer.Pack(member_id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(password.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(name.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(phone_number.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(address.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_mile.c_str());
	if (numBytes == -1) return false;

	return true;
}
bool Member::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[256];

	
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	member_id = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	password = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	name = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	phone_number = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	address = buf;
	numBytes = Buffer.Unpack(mileage,10);
	if (numBytes == -1) return false;

	return true;
}
ostream & operator << (ostream &os, Member &m)
{
	cout << "ID : " << m.member_id << endl;
	cout << "PASSWORD : " << m.password << endl;
	cout << "NAME : " << m.name << endl;
	cout << "NUMBER : " << m.phone_number << endl;
	cout << "ADDRESS : " << m.address << endl;
	cout << "ADDRESS : ";
	for (int i = 0; i<10; i++)
		cout << m.mileage[i];
	cout << endl << endl;
	return os;
}