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
	string getKey(); // gets the key
	HashItem getItem(); // gets the item
	bool operator==(const HashEntry<HashItem> other) const; // hashentries are equal if the key and items are the same
	~HashEntry();
};
#include "HashEntry.cpp"

#endif