#pragma once
#include "Movie.h"
class DramaMovie : public Movie
{
public:
	DramaMovie(int, string, string, string);
	string getKey(); // returns the year released
	~DramaMovie();
	bool operator==(const DramaMovie& otherMovie) const; // same as the Movie == operator
};

