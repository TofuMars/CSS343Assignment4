#include "stdafx.h"
#include "Customer.h"

Customer::Customer(string id, string firstnme, string lastnme)
{
	ID = id;
	firstName = firstnme;
	lastName = lastnme;
}

Customer::~Customer()
{
}

bool Customer::IsBorrowed(string movie)
{
	list<string>::iterator it = borrowed.begin();
	while (it != borrowed.end())
	{
		if (it._Ptr->_Myval == movie)
			return true;
		else
			it++;
	}
	return false;
}

void Customer::addBorrowed(string movie)
{
	borrowed.push_back(movie);
}

void Customer::returnBorrowed(string movie)
{
	list<string>::iterator it = borrowed.begin();
	while (it != borrowed.end())
	{
		if (it._Ptr->_Myval == movie)
		{
			borrowed.erase(it);
			break;
		}
		else
			it++;
	}
}

string Customer::getKey()
{
	return ID;
}

string Customer::getID()
{
	return ID;
}

string Customer::getFirstName()
{
	return firstName;
}

string Customer::getLastName()
{
	return lastName;
}

bool Customer::operator==(const Customer & otherCustomer) const
{
	return (ID == otherCustomer.ID) && (firstName == firstName) && (lastName == lastName);
}
