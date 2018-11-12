#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include "delim.h"


#define LENMILE 10;
using namespace std;

class Member {
	string member_id;
	string password;
	string name;
	string phone_number;
	string address;
	char mileage[10];
	int level;
public:
	Member();
	Member(const string new_id);
	Member(const Member & m);

	Member& operator =(const Member &m);
	bool operator == (const Member &m);
	bool operator != (const Member &m);
	bool Pack(IOBuffer & Buffer) const;
	bool Unpack(IOBuffer & Buffer);
	friend istream & operator >> (istream &is, Member &s);
	friend ostream & operator << (ostream &os, Member &s);

	void update_id(const string new_id) { member_id= new_id; }
	void update_password(const string new_pass) { password = new_pass; }
	void update_name(const string new_name) { name = new_name; }
	void update_number(const string new_number) { phone_number =new_number; }
	void update_address(const string new_address) { address = new_address; }
	void update_mileage(const char* new_mileage) { memcpy(mileage,new_mileage,10); }
	void update_level(int new_level) { level = new_level; }
	bool check_password(const string in_pass) {
		if (in_pass == password)
			return true;
		return false; 
	}
	string get_id() { return member_id; }
	int get_level() { return level; }
};

istream & operator >> (istream &is, Member &m);
ostream & operator << (ostream &os, Member &m);
#endif