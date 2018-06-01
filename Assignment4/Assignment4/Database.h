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
    void populate(const std::string& customerFile, const std::string& movieFile);
    void runCommand(std::string& entry);
    void runCommands(const std::string& filename);
    void dump();
private:
    HashTable<Customer*> customers;
    HashTable<Movie*> movies;
    LinkedList<std::pair<string, LinkedList<string>>*> checkedOut;


    void populateMovies(const std::string& filename);
    void populateCustomers(const std::string& filename);

    void getCustomerMovies(const string& id);
    void borrowMovie(const string& id, string& data);
    void returnMovie(const string& id, string& data);

    //bool isValidMovie(string& entry);
    bool isValidCustomer(const string& id);

    void addComedy(string& entry);
    void addDrama(string& entry);
    void addClassic(string& entry);

    string parseSubstring(string& source, const string& delimiter = ", ");
};