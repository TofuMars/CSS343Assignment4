#pragma once
#include "HashTable.h"
#include "InputValidator.h"
#include <iostream>
#include <fstream>

class Database
{
public:
    void populate(const std::string movieFile, const std::string customerFile);
    void runCommand(const std::string entry);
    void runCommands(const std::string filename);
    void dump();
private:
    HashTable<Customer*> customers;
    HashTable<Movie*> movies;

    void populateMovies(const std::string filename);
    void populateCustomers(const std::string filename);

    bool isValidMovie(string entry);
    bool isValidCustomer(const string id);

    void addComedy(string entry);
    void addDrama(string entry);
    void addClassic(string entry);

    string parseSubstring(string& source, string delimiter);
};