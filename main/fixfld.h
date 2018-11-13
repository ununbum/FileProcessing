#pragma once
// fixfld.h
#ifndef FIXFLD_H
#define FIXFLD_H

#include <stdlib.h>
#include <iostream>
#include "fixlen.h"

class FixedFieldBuffer : public FixedLengthBuffer
	// Abstract class designed to support fixed length records
	// Use of this class requires that all fields be defined before
	//    reading and writing can take place
{
public:
	FixedFieldBuffer(int maxFields, int RecordSize = 1000);
	FixedFieldBuffer(int maxFields, int * fieldSize);
	// initialize all fields at once
	FixedFieldBuffer(const FixedFieldBuffer &); //copy constructor
	FixedFieldBuffer & operator = (const FixedFieldBuffer &);
	void Clear(); // clear values from buffer
	int AddField(int fieldSize); // define the next field
	int ReadHeader(istream &); // write a buffer to the stream
	int WriteHeader(ostream &) const; // write a buffer to the stream
	int Pack(const void * field, int size = -1); // set the value of the next field of the buffer;
	int Unpack(void * field, int maxBytes = -1); // extract the value of the next field of the buffer
	void Print(ostream &) const;
	int NumberOfFields() const; // return number of defined fields
	int Init(int maxFields);
	int Init(int numFields, int * fieldSize);
protected:
	int * FieldSize; // array to hold field sizes
	int MaxFields; // maximum number of fields
	int NumFields; // actual number of defined fields
	int NextField; // index of next field to be packed/unpacked
};

inline FixedFieldBuffer::FixedFieldBuffer(const FixedFieldBuffer & buffer)
	: FixedLengthBuffer(buffer)
{
	Init(buffer.NumFields, buffer.FieldSize);
}

#endif

