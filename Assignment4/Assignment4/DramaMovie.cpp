#include "stdafx.h"
#include "DramaMovie.h"

DramaMovie::DramaMovie(int stk, string dtor, string ttle, string yr) : Movie(stk, dtor, ttle, yr)
{

}

string DramaMovie::getKey() { return year; }

DramaMovie::~DramaMovie()
{
}

bool DramaMovie::operator==(const DramaMovie & otherMovie) const
{
	return (year == otherMovie.year) && (title == otherMovie.title) && (director == otherMovie.director)
		&& stock == otherMovie.stock;
}
