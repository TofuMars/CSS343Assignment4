#include "stdafx.h"
#include "ComedyMovie.h"

ComedyMovie::ComedyMovie(int stk, string dtor, string ttle, string yr) :Movie(stk, dtor, ttle, yr)
{
}

string ComedyMovie::getKey()
{
	return year;
}

ComedyMovie::~ComedyMovie()
{
}

bool ComedyMovie::operator==(const ComedyMovie & otherMovie) const
{
	return (year == otherMovie.year) && (title == otherMovie.title) && (director == otherMovie.director)
		&& stock == otherMovie.stock;
}
