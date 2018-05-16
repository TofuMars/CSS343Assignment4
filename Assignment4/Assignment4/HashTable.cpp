#include "stdafx.h"
#include "HashTable.h"
#include <iterator>
template<class HashItem>
int HashTable<HashItem>::calculateIndex(string key)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
		sum += key[i];
	return sum % 101;
}

template<class HashItem>
HashTable<HashItem>::HashTable()
{
}

template<class HashItem>
HashTable<HashItem>::~HashTable()
{
}

// adds an entry at the specified key
template<class HashItem>
void HashTable<HashItem>::add(string key, HashEntry<HashItem>* item)
{
	int calculatedIndex = calculateIndex(item->getKey()); // calculate index

	if (table[calculatedIndex].size() == 0) // if first entry, instantiate list and add
	{
		table[calculatedIndex] = list<HashEntry<HashItem>*>();
		table[calculatedIndex].push_back(item);
	}
	else // list exists, add to the back of the list
		table[calculatedIndex].push_back(item);
}

template<class HashItem>
void HashTable<HashItem>::remove(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	list<HashEntry<HashItem>*> listOfItems = table[index]; // iterate through the list
	list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
	while (it != table[index].end())
	{
		if (it._Ptr->_Myval->getItem() == specific->getItem()) // if the items match, it is the element to be deleted
		{
			table[index].erase(it);
			break;
		}
		it++;
	}
}

template<class HashItem>
HashEntry<HashItem>* HashTable<HashItem>::find(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	list<HashEntry<HashItem>*> listOfItems = table[index];
	list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
	while (it != table[index].end())
	{
		if (it._Ptr->_Myval->getItem() == specific->getItem())
		{
			return it._Ptr->_Myval; 
		}
		it++;
	}
	return nullptr;
}

template<class HashItem>
bool HashTable<HashItem>::contains(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	list<HashEntry<HashItem>*> listOfItems = table[index];
	list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
	while (it != table[index].end())
	{
		if (it._Ptr->_Myval->getItem() == specific->getItem())
		{
			return true;
		}
		it++;
	}
	return false;
}

template<class HashItem>
void HashTable<HashItem>::traverse(void visit(HashEntry<HashItem>*))
{
	for (int i = 0; i < 101; i++)
	{
		list<HashEntry<HashItem>*> listOfItems = table[i];
		list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
		while (it != table[i].end())
		{
			visit(it._Ptr->MyVal);
			it++;
		}
	}
}
