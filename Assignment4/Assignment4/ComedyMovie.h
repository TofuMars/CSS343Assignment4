#pragma once
#include "Movie.h"
class ComedyMovie : public Movie
{
public:
	ComedyMovie(int stock, string director, string title, string year);
	string getKey(); // returns year released
	~ComedyMovie();
	bool operator==(const ComedyMovie& otherMovie) const;// same as the Movie == operator
};

