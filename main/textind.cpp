
//textind.cc
#include "textind.h"
#include <iostream>
#include <string>

using namespace std;


TextIndex::TextIndex(int maxKeys, int unique)
	: NumKeys(0), Keys(0), RecAddrs(0)
{
	Init(maxKeys, unique);
}

TextIndex :: ~TextIndex()
{
	delete Keys; delete RecAddrs;
}

int TextIndex::Insert(const char * key, int recAddr)
{
	int i;
	int index = Find(key);
	if (Unique && index >= 0) return 0; // key already in
	if (NumKeys == MaxKeys) return 0; //no room for another key
	for (i = NumKeys - 1; i >= 0; i--)
	{
		if (strcmp(key, Keys[i]) > 0) break; // insert into location i+1
		Keys[i + 1] = Keys[i];
		RecAddrs[i + 1] = RecAddrs[i];
	}
	Keys[i + 1] = strdup(key);
	RecAddrs[i + 1] = recAddr;
	NumKeys++;
	return 1;
}

int TextIndex::Remove(const char * key)
{
	int index = Find(key);
	if (index < 0) return 0; // key not in index
	for (int i = index; i < NumKeys; i++)
	{
		Keys[i] = Keys[i + 1];
		RecAddrs[i] = RecAddrs[i + 1];
	}
	NumKeys--;
	return 1;
}
int TextIndex::Update(char * oldkey, char * key,int recaddr)
{
	Remove(oldkey);
	Insert(key, recaddr);
	return recaddr;
}
int TextIndex::FirstRecAddr() const
{
	return 0;
}
int TextIndex::NextRecAddr(int old) const
{
	return old + 1;
}
int TextIndex::Search(const char * key) const
{
	/*
	int index = Find(key);
	if (index < 0) return index;
	return RecAddrs[index];
	*/
	int left = FirstRecAddr();
	int right = NumKeys-1;
	int i = (left + right) / 2;
	while (strcmp(key,Keys[i]))
	{
		
		if (left == right)
		{
			i = -1;
			break;
		}
		if (strcmp(Keys[i], key) > 0)
			right = i;
		else if (strcmp(Keys[i], key) < 0)
			left = NextRecAddr(i);
		i = (left + right) / 2;
	}
	if (i < 0) return i;
	return RecAddrs[i];


}
void TextIndex::Print(ostream & stream) const
{
	stream << "Text Index max keys " << MaxKeys
		<< " num keys " << NumKeys << endl;
	for (int i = 0; i < NumKeys; i++)
		stream << "\tKey[" << i << "] " << Keys[i]
		<< " RecAddr " << RecAddrs[i] << endl;
}

int TextIndex::Find(const char * key) const
{
	for (int i = 0; i < NumKeys; i++)
		if (strcmp(Keys[i], key) == 0) return i;// key found
//		else if (strcmp(Keys[i], key)>0) return -1;// not found
	return -1;// not found
}

int TextIndex::Init(int maxKeys, int unique)
{
	Unique = unique != 0;
	if (maxKeys <= 0)
	{
		MaxKeys = 0;
		return 0;
	}
	MaxKeys = maxKeys;
	Keys = new char *[maxKeys];
	RecAddrs = new int[maxKeys];
	return 1;
}

