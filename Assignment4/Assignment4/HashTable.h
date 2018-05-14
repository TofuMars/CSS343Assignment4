#ifndef HASH_TABLE
#define HASH_TABLE
#include <string>
#include <list>
#include "HashEntry.h"
using std::string;
using std::list;
#pragma once
template<class HashItem>
class HashTable
{
private:
	list<HashEntry<HashItem>*>  table[101];
	int calculateIndex(string key);
public:
	HashTable();
	~HashTable();
	void add(string, HashEntry*);
	void remove(string, HashEntry*);
	HashEntry<HashItem>* find(string, string);
	bool contains(string, string);
	void traverse(void(HashEntry<HashItem>*) visit);
};
#include "HashTable.cpp"
#endif
