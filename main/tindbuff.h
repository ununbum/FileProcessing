#pragma once
//tindbuff.h
#ifndef TINDBUFF_H
#define TINDBUFF_H

#include "textind.h"
#include "fixfld.h"

// class TextIndexBuffer supports reading and writing index records from
//	class TextIndex
// each record is consistent in its maximum size
class TextIndexBuffer : public FixedFieldBuffer
{
public:
	TextIndexBuffer(int keySize, int maxKeys = 100,
		int extraFields = 0, int extraSize = 0);
	// extraSize is included to allow derived classes to extend
	// the buffer with extra fields. 
	// Required because the buffer size is exact.
	int Pack(const TextIndex &);
	int Unpack(TextIndex &);
	void Print(ostream &) const;
protected:
	int MaxKeys;
	int KeySize;
	char * Dummy; // space for dummy in pack and unpack
};

#endif
