#include "stdafx.h"
#include "ClassicMovie.h"

ClassicMovie::ClassicMovie(int stck, string dtor, string ttle, string yr, string mth, string lead) : Movie(stck, dtor, ttle, yr)
{
	month = mth;
	leadActors.add(lead);
}

ClassicMovie::~ClassicMovie()
{
	leadActors.clear();
}

LinkedList<string>& ClassicMovie::getLeadActors()
{
	// TODO: insert return statement here
	return leadActors;
}

string ClassicMovie::getKey()
{
	return month + " " + year;
}

string ClassicMovie::getMonth()
{
	return month;
}

bool ClassicMovie::containsActor(string actor)
{
	return leadActors.contains(actor) >= 0;
}

bool ClassicMovie::operator==(const ClassicMovie & otherMovie) const
{
	return (month == otherMovie.month) && (year == otherMovie.year) && (title == otherMovie.title)
		&& (director == otherMovie.director) && stock == otherMovie.stock;
}
