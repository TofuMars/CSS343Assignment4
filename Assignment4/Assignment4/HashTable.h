#ifndef HASH_TABLE
#define HASH_TABLE
#include <string>
#include <list>
#include "HashEntry.h"
#include "Movie.h"
#include "Customer.h"
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
	void add(string, HashEntry<HashItem>*);
	void remove(string, HashEntry<HashItem>*);
	HashEntry<HashItem>* find(string, HashEntry<HashItem>*);
	bool contains(string, HashEntry<HashItem>*);
	void traverse(void(HashEntry<HashItem>*) visit);
};
#include "HashTable.cpp"
#endif
