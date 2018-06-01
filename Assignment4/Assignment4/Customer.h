#pragma once
#include <string>
#include <list>
using std::string;
using std::list;
class Customer
{
private:
	string ID;
	string firstName;
	string lastName;
	list<string> borrowed;
public:
	Customer(string id, string firstnme, string lastnme);
	~Customer();
	bool IsBorrowed(string movie); // checks whether a movie is inside the borrowed list
	void addBorrowed(string movie); // adds a movie to the borrowed list
	void returnBorrowed(string movie); // removes a movie form the borrowed list
	string getKey(); // returns the ID of the customer
	virtual string getID();
	string getFirstName();
	string getLastName();
	bool operator==(const Customer& otherCustomer) const; // customers are equal if their ID, first name, and last name are equal
};

