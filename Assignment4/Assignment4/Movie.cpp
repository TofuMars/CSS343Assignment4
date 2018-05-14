#include "stdafx.h"
#include "Movie.h"

Movie::Movie(int stck, string drtor, string ttle, string yr)
{
	stock = stck;
	director = drtor;
	title = ttle;
	year = yr;
}

Movie::~Movie()
{
}

int Movie::getStock()
{
	return stock;
}

void Movie::setStock(int num)
{
	stock = num;
}

string Movie::getTitle()
{
	return title;
}

string Movie::gerDirector()
{
	return director;
}

string Movie::getYear()
{
	return year;
}

string Movie::getKey()
{
	return year;
}

bool Movie::operator==(const Movie & otherMovie) const
{
	return (year == otherMovie.year) && (title == otherMovie.title) && (director == otherMovie.director)
		&& stock == otherMovie.stock;
}


