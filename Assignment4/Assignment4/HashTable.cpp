#include "stdafx.h"
#include "HashTable.h"
#include "LinkedList.h"
#include <iterator>

// Calculates the array index by summing all the ASCII characters and modulating the sum by 101
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
	if (table[calculatedIndex].size() == 0) // check if the list  size is 0 then adds
	{
		table[calculatedIndex].add(item);
	}
	else
		table[calculatedIndex].add(item);
}

// Removes a specific entry at a given hashkey
template<class HashItem>
void HashTable<HashItem>::remove(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key); // calculate index
	int removeAt = table[index].contains(specific); // find iterator position at linked list
	if (removeAt >= 0)
		table[index].remove(removeAt); // remove the entry if it exists
}

template<class HashItem>
HashEntry<HashItem>* HashTable<HashItem>::find(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	for (int i = 0; i < table[index].size(); i++) // traverse the linked list
	{
		HashEntry<HashItem>* h1 = table[index].getItem(i); // if the hashitem at the node equals the specific item
		if (*h1 == *specific) // return it
			return h1;
	}
	return nullptr; // not found
}

template<class HashItem>
bool HashTable<HashItem>::contains(string key, HashEntry<HashItem>* specific)
{
	int index = calculateIndex(key);
	for (int i = 0; i < table[index].size(); i++) // traverse the linked list
	{
		HashEntry<HashItem>* h1 = table[index].getItem(i);
		if (*h1 == *specific) // if it matches, we know the list contains the specific entry
			return true;
	}
	return false; // not found
}

// Gets a movie by traversing the whole dictionary, given a linked list of strings as
// search criteria
// Assumption: the Hashtable is a Hashtable of movies
template<class HashItem>
Movie * HashTable<HashItem>::getMovie(const LinkedList<string>& info)
{
	for (int i = 0; i < 101; i++) // for each cell in the hashtable
	{
		for (int j = 0; j < table[i].size(); j++) // for each linked list in the cell
		{
			HashEntry<HashItem>* h1 = table[i].getItem(j); // get the item from the node
			
			auto movieNode = dynamic_cast<HashEntry<Movie*>*>(h1); // cast it as a movie hashentry 
			int matches = 0; // determines whether we found the correct movie through matches

			for (int k = 0; k < info.size(); k++)
			{
				// increase the number of matches if the director, title, year, are the same
				if (movieNode->getItem()->getDirector().find(info.getItem(k)) != string::npos ||
					movieNode->getItem()->getTitle().find(info.getItem(k)) != string::npos ||
					movieNode->getItem()->getYear().find(info.getItem(k)) != string::npos)
					matches++;
				if (matches >= 2) // if the matches are 2, then we found the movie
					return movieNode->getItem();
			}
		}
	}
	return nullptr; // movie not found
}

// performs a void hashentry method to every item in the dictionary
template<class HashItem>
void HashTable<HashItem>::traverse(void visit(HashEntry<HashItem>*))
{
	for (int i = 0; i < 101; i++) // traverse all the cells
	{
		table[i].traverse(visit); // traverse each linked list
	}
}

// clears every node in the dictionary. Empties it.
template<class HashItem>
void HashTable<HashItem>::clear()
{
	for (int i = 0; i < 101; i++) // call clear for every linked list to remove
		table[i].clear();
}
