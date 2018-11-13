// indbuff.tc
#include "tindbuff.h"

TextIndexBuffer::TextIndexBuffer(int keySize, int maxKeys,
	int extraFields, int extraSpace)
	: FixedFieldBuffer(1 + 2 * maxKeys + extraFields,
		sizeof(int) + maxKeys * keySize + maxKeys * sizeof(int) + extraSpace)
	// buffer fields consist of 
	//    numKeys, actual number of keys
	//    Keys [maxKeys] key fields size = maxKeys * keySize
	//    RecAddrs [maxKeys] record address fields size = maxKeys*sizeof(int)
{
	MaxKeys = maxKeys;
	KeySize = keySize;
	AddField(sizeof(int));
	for (int i = 0; i < maxKeys; i++)
	{
		AddField(KeySize);
		AddField(sizeof(int));
	}
	Dummy = new char[keySize + 1];
}

int TextIndexBuffer::Pack
(const TextIndex & index)
{
	int result;
	Clear();
	result = FixedFieldBuffer::Pack(&index.NumKeys);
	for (int i = 0; i < index.NumKeys; i++)
	{// note only pack the actual keys and recaddrs
		result = result && FixedFieldBuffer::Pack(index.Keys[i]);
		result = result && FixedFieldBuffer::Pack(&index.RecAddrs[i]);
	}
	for (int j = 0; j < index.MaxKeys - index.NumKeys; j++)
	{// pack dummy values for other fields
		result = result && FixedFieldBuffer::Pack(Dummy);
		result = result && FixedFieldBuffer::Pack(Dummy);
	}
	return result;
}

int TextIndexBuffer::Unpack
(TextIndex & index)
{
	int result;
	result = FixedFieldBuffer::Unpack(&index.NumKeys);
	for (int i = 0; i < index.NumKeys; i++)
	{// note only pack the actual keys and recaddrs
		index.Keys[i] = new char[KeySize + 1]; // just to be safe
		result = result && FixedFieldBuffer::Unpack(index.Keys[i]);
		index.Keys[i][KeySize] = '\0';
		result = result && FixedFieldBuffer::Unpack(&index.RecAddrs[i]);
	}
	for (int j = 0; j < index.MaxKeys - index.NumKeys; j++)
	{// pack dummy values for other fields
		result = result && FixedFieldBuffer::Unpack(Dummy);
		result = result && FixedFieldBuffer::Unpack(Dummy);
	}
	return result;
}
void TextIndexBuffer::Print(ostream & stream) const
{
	stream << "TextIndexBuffer: KeySize " << KeySize
		<< " MaxKeys " << MaxKeys << endl;
	FixedFieldBuffer::Print(stream);
}