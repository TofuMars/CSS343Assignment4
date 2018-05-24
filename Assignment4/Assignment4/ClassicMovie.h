#pragma once
#include "Movie.h"
#include "LinkedList.h"

class ClassicMovie : public Movie
{
private:
	LinkedList<string> leadActors;
	string month;
public:
	ClassicMovie(int stock, string, string, string, string, string); // follows the order of 
																	// (stock, director, title, year, month, leadActor)
																	// leadActor is a string that includes both the first and last name 
	~ClassicMovie();
	LinkedList<string>& getLeadActors();
	string getKey(); // returns a string of the format "month year"
	string getMonth();
	bool containsActor(string actor); // bool that returns whether an actor is in the film
	bool operator==(const ClassicMovie& otherMovie) const; // classic movies are equal if their title, director, month, year, and stock are equal
};

