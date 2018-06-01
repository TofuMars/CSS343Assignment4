#include "HashEntry.h"

template<class HashItem>
HashEntry<HashItem>::HashEntry(string ky, HashItem itm)
{
	key = ky;
	item = itm;
}

template<class HashItem>
string HashEntry<HashItem>::getKey()
{
	return key;
}

template<class HashItem>
HashItem HashEntry<HashItem>::getItem()
{
	return item;
}

template<class HashItem>
bool HashEntry<HashItem>::operator==(const HashEntry<HashItem> other) const
{
	auto otherItem = dynamic_cast<Movie*>(other.item);
	auto thisItem = dynamic_cast<Movie*>(item);
	auto otherCustomerItem = dynamic_cast<Customer*>(other.item);
	auto thisCustomerItem = dynamic_cast<Customer*>(item);

	if (otherItem && thisItem)
	{
		return key == other.key && *thisItem == *otherItem;
	}
	else if (otherCustomerItem && thisCustomerItem)
	{
		return key == other.key && *thisCustomerItem == *otherCustomerItem;
	}
	else
		return key == other.key && item == other.item;
}

template<class HashItem>
HashEntry<HashItem>::~HashEntry()
{
}
