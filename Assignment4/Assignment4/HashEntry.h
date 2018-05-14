#ifndef HASH_ENTRY
#define HASH_ENTRY
#include <string>
#pragma once
using std::string;
template<class HashItem>
class HashEntry
{
private:
	string key;
	HashItem item;
public:
	HashEntry(string ky, HashItem itm);
	string getKey();
	HashItem getItem();
	~HashEntry();
};
#include "HashEntry.cpp"

#endif