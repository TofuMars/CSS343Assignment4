// Assignment4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "Movie.h"
#include "HashEntry.h"
#include "HashTable.h"
#include "Database.h"

using std::cin;
using std::cout;

int main()
{
    Database database;
    // Populate database
    database.populate("data4customers.txt", "data4movies.txt");

    // Run commands from file
    database.runCommands("data4commands.txt");
    return 0;
}

