// Assignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "Movie.h"

string getMovieKey(Movie* movie) { return movie->getKey(); }
int main()
{
	list<Movie*> movies;
	DramaMovie* m1 = new DramaMovie(10, "Steven Spielberg", "Fat Albert", "1997");
	ClassicMovie* m2 = new ClassicMovie(10, "Michael King", "Ink Spots", "1941", "2", "Bill Kenney");
	ComedyMovie* m3 = new ComedyMovie(10, "Steven Spielberg", "Romeo and Juliet", "1973");
	movies.push_back(m1);
	movies.push_back(m2);
	movies.push_back(m3);
	string s1(getMovieKey(m1));
	string s2(getMovieKey(m2));
	string s3(getMovieKey(m3));
    return 0;
}

