#include "stdafx.h"
#include "HashTable.h"

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

template<class HashItem>
void HashTable<HashItem>::add(string key, HashEntry<HashItem>* item)
{
}

template<class HashItem>
void HashTable<HashItem>::remove(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);

}

template<class HashItem>
HashEntry<HashItem>* HashTable<HashItem>::find(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	list<HashEntry<HashItem>*> listOfItems = table[index];
	listOfItems
	//HashEntry<HashItem>* dynamic_cast<HashEntry<Movie>*> (listOfItems);
	return nullptr;
}

template<class HashItem>
bool HashTable<HashItem>::contains(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	return false;
}

template<class HashItem>
void HashTable<HashItem>::traverse(void(HashEntry<HashItem>*) visit)
{
}
