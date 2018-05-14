#include "HashEntry.h"

template<class HashItem>
HashEntry<HashItem>::HashEntry(string ky, HashItem itm)
{
	key = ky;
	item = itm;
}

template<class HashItem>
string HashEntry<HashItem>::getKey()
{
	return key;
}

template<class HashItem>
HashItem HashEntry<HashItem>::getItem()
{
	return item;
}

template<class HashItem>
HashEntry<HashItem>::~HashEntry()
{
}
