#ifndef HASH_TABLE
#define HASH_TABLE
#include <string>
#include <list>
#include "HashEntry.h"
#include "Movie.h"
#include "Customer.h"
#include "LinkedList.h"
using std::string;
using std::list;
#pragma once
template<class HashItem>
class HashTable
{
private:
	//list<HashEntry<HashItem>*>  table[101];
	LinkedList<HashEntry<HashItem>*> table[101];
	int calculateIndex(string key);
public:
	HashTable();
	~HashTable();
	void add(string, HashEntry<HashItem>*);
	void remove(string, HashEntry<HashItem>*);
	HashEntry<HashItem>* find(string, HashEntry<HashItem>*);
	bool contains(string, HashEntry<HashItem>*);
	Movie* getMovie(LinkedList<string> info);
	void traverse(void visit (HashEntry<HashItem>*));
	void clear();
};
#include "HashTable.cpp"
#endif
