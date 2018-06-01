#include "stdafx.h"
#include "HashTable.h"
#include "LinkedList.h"
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
	clear();
}

// adds an entry at the specified key
template<class HashItem>
void HashTable<HashItem>::add(string key, HashEntry<HashItem>* item)
{
	int calculatedIndex = calculateIndex(item->getKey()); // calculate index
	if (table[calculatedIndex].size() == 0)
	{
		table[calculatedIndex].add(item);
	}
	else
		table[calculatedIndex].add(item);
	//if (table[calculatedIndex].size() == 0) // if first entry, instantiate list and add
	//{
	//	table[calculatedIndex] = list<HashEntry<HashItem>*>();
	//	table[calculatedIndex].push_back(item);
	//}
	//else // list exists, add to the back of the list
	//	table[calculatedIndex].push_back(item);
}

template<class HashItem>
void HashTable<HashItem>::remove(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	int removeAt = table[index].contains(specific);
	if (removeAt >= 0)
		table[index].remove(removeAt);
	//list<HashEntry<HashItem>*> listOfItems = table[index]; // iterate through the list

	//list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
	//while (it != table[index].end())
	//{
	//	if (it._Ptr->_Myval->getItem() == specific->getItem()) // if the items match, it is the element to be deleted
	//	{
	//		table[index].erase(it);
	//		break;
	//	}
	//	it++;
	//}
}

template<class HashItem>
HashEntry<HashItem>* HashTable<HashItem>::find(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	for (int i = 0; i < table[index].size(); i++)
	{
		HashEntry<HashItem>* h1 = table[index].getItem(i);
		if (*h1 == *specific)
			return h1;
	}
	//return table[index].getItem(findAt);
	//list<HashEntry<HashItem>*> listOfItems = table[index];
	//list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
	//while (it != table[index].end())
	//{
	//	if (it._Ptr->_Myval->getItem() == specific->getItem())
	//	{
	//		return it._Ptr->_Myval; 
	//	}
	//	it++;
	//}
	return nullptr;
}

template<class HashItem>
bool HashTable<HashItem>::contains(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	for (int i = 0; i < table[index].size(); i++)
	{
		HashEntry<HashItem>* h1 = table[index].getItem(i);
		if (*h1 == *specific)
			return true;
	}
	//list<HashEntry<HashItem>*> listOfItems = table[index];
	//list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
	//while (it != table[index].end())
	//{
	//	if (it._Ptr->_Myval->getItem() == specific->getItem())
	//	{
	//		return true;
	//	}
	//	it++;
	//}
	return false;
}

template<class HashItem>
Movie * HashTable<HashItem>::getMovie(LinkedList<string> info)
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; i < table[i].size(); j++)
		{
			HashEntry<HashItem>* h1 = table[i].getItem(j);
			auto movieNode = dynamic_cast<HashEntry<Movie*>*>(h1);
			int matches = 0;
			for (int k = 0; k < info.size(); k++)
			{

				if (movieNode->getItem()->getDirector() == info[k] ||
					movieNode->getItem()->getTitle() == info[k] ||
					movieNode->getItem()->getYear() == info[k])
					matches++;
				if (matches >= 2)
					return movieNode->getItem();
			}
		}
	}
	return nullptr;
}

template<class HashItem>
void HashTable<HashItem>::traverse(void visit(HashEntry<HashItem>*))
{
	for (int i = 0; i < 101; i++)
	{
		table[i].traverse(visit);
		//list<HashEntry<HashItem>*> listOfItems = table[i];
		//list<HashEntry<HashItem>*>::iterator it = listOfItems.begin();
		//while (it != table[i].end())
		//{
		//	visit(it._Ptr->MyVal);
		//	it++;
		//}
	}
}

template<class HashItem>
void HashTable<HashItem>::clear()
{
	for (int i = 0; i < 101; i++)
		table[i].clear();
}
