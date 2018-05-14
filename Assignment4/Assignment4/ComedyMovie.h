#pragma once
#include "Movie.h"
class ComedyMovie : public Movie
{
public:
	ComedyMovie(int , string, string, string);
	string getKey(); // returns year released
	~ComedyMovie();
	bool operator==(const ComedyMovie& otherMovie) const;// same as the Movie == operator
};

