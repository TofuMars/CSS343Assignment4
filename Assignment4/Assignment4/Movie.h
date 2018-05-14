#include <string>
#pragma once
using std::string;
class Movie
{
protected:
	string year;
	string title;
	string director;
	int stock;
public:
	Movie(int, string, string , string); // constructor follows the parameters (stock, director, title, year)
	~Movie();
	int getStock();
	void setStock(int num); // sets the stock to the desired amount
	string getTitle();
	string gerDirector();
	string getYear();
	virtual string getKey(); // by default, returns the year released
	bool operator==(const Movie& otherMovie) const; // movies are equal if the title, director, stock, and year are equal
};

