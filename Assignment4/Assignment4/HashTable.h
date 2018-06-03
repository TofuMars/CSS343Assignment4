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

// The HashTable class is a dictionary of size 101 as the default size. 
// This is a template class that is used to map items to a certain string, which is converted to an array index
// This hashtable implements the separate chaining method of collision handling
template<class HashItem>
class HashTable
{
private:
	//list<HashEntry<HashItem>*>  table[101];
	LinkedList<HashEntry<HashItem>*> table[101];
	int calculateIndex(string key); // calculates the array index given a string
public:
	HashTable();
	~HashTable();
	void add(string, HashEntry<HashItem>*); // adds a hashitem with a corresponding string key
	void remove(string, HashEntry<HashItem>*); // removes a hashitem with a corresponding string key
	HashEntry<HashItem>* find(string, HashEntry<HashItem>*); // returns a hashitem with a given string key
	bool contains(string, HashEntry<HashItem>*); // checks whether a hashitem exists in the dictionary at a certain string key
	Movie* getMovie(const LinkedList<string>& info); // returns a movie pointer in the dictionary given pieces of search criteria
	void traverse(void visit (HashEntry<HashItem>*)); // traverses the dictionary to perform a method
	void clear(); // clears the whole dictionary of items
};
#include "HashTable.cpp"
#endif
