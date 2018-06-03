#pragma once
#include "HashTable.h"
#include "InputValidator.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "Movie.h"
#include <iostream>
#include <fstream>

class Database
{
public:
	/* Methods */

	// Populates Database with contents of two files
	void populate(const std::string& customerFile, const std::string& movieFile);

	// Runs a series of commands from a file
	void runCommands(const std::string& filename);

	// Runs on operation on the Database
	void runCommand(std::string& entry);

private:
	/* Members */

	// Hashtable containing all customers
	HashTable<Customer*> customers;

	// Hashtable containing all movies
	HashTable<Movie*> movies;

	// Linked list that contains the customer ids and the titles of the movies
	// they checked out
	LinkedList<std::pair<string, LinkedList<string>>*> checkedOut;

	/* Methods */

	// Populates movies with the contents of a file
	void populateMovies(const std::string& filename);

	// Helper method to add a comedy to movies
	void addComedy(string& entry);

	// Helper method to add a drama to movies
	void addDrama(string& entry);

	// Helper method to add a classic to movies
	void addClassic(string& entry);

	// Populates customers with the contents of a file
	void populateCustomers(const std::string& filename);

	// Helper method to add 
	bool isValidCustomer(const string& id);

	// Prints out all the movies that a given customer has checked out.
	void getCustomerMovies(const string& id);

	// If a customer does not have a specified movie checked out, the movie is
	// removed from checkedOut and the the movie's quantity is increased by 1
	void borrowMovie(const string& id, string& data);

	// If a customer has a specified movie checked out, the movie is removed
	// from checkedOut and the the movie's quantity is increased by 1
	void returnMovie(const string& id, string& data);

	// Creates a substring from a source string with a defined delimiter
	string parseSubstring(string& source, const string& delimiter = ", ");
};
