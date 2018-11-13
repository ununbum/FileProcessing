#pragma once
// fixlen.h
#ifndef FIXLEN_H
#define FIXLEN_H

#include <stdlib.h>
#include <iostream>
#include "iobuffer.h"

class FixedLengthBuffer : public IOBuffer
	// Abstract class designed to support fixed length records
{
public:
	FixedLengthBuffer(int recordSize = 1000);
	FixedLengthBuffer(const FixedLengthBuffer & buffer); // copy constructor

	void Clear(); // clear values from buffer
	int Read(istream &);
	int Write(ostream &) const;
	int ReadHeader(istream &); // read header from stream
	int WriteHeader(ostream &) const; // write a header to the stream
	int Update(ostream & stream, int recref, int prev_size) const;
	void Print(ostream &) const;
	int SizeOfBuffer() const; // return size of buffer
protected:
	int Init(int recordSize);
	int ChangeRecordSize(int recordSize);
};

inline FixedLengthBuffer::FixedLengthBuffer(const FixedLengthBuffer & buffer)
	: IOBuffer(buffer)
{
	Init(buffer.BufferSize);
}

#endif
