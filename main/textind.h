#pragma once
//textind.h
#ifndef TEXTIND_H
#define TEXTIND_H
#include <iostream>

using namespace std;

class TextIndex
{
public:
	TextIndex(int maxKeys = 100, int unique = 1);
	~TextIndex();
	int Insert(const char * key, int recAddr);
	int Remove(const char * key);
	int Search(const char * key) const;
	int Update(char * oldkey, char * key,int recaddr);
	int FirstRecAddr() const;
	int NextRecAddr(int old) const;
	void Print(ostream &) const;
protected:
	int MaxKeys;
	int NumKeys;
	char * * Keys;
	int * RecAddrs;
	int Find(const char * key) const;
	int Init(int maxKeys, int unique);
	
	int Unique; // if true, each key value must be unique in the index
	friend class TextIndexBuffer;
};

#endif

