// Assignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "Movie.h"
#include "HashEntry.h"
#include "HashTable.h"

string getMovieKey(Movie* movie) { return movie->getKey(); }

int main()
{
	//list<Movie*> movies;
	DramaMovie* m1 = new DramaMovie(10, "Steven Spielberg", "Fat Albert", "1997");
	ClassicMovie* m2 = new ClassicMovie(10, "Michael King", "Ink Spots", "1941", "2", "Bill Kenney");
	ComedyMovie* m3 = new ComedyMovie(10, "Steven Spielberg", "Romeo and Juliet", "1973");
	HashEntry<Movie*>* movie1 = new HashEntry<Movie*>(getMovieKey(m1), m1);
	HashEntry<Movie*>* movie2 = new HashEntry<Movie*>(getMovieKey(m2), m2);
	HashEntry<Movie*>* movie3 = new HashEntry<Movie*>(getMovieKey(m3), m3);
	HashTable<Movie*> ht;
	ht.add(movie1->getKey(), movie1);
	ht.add(movie2->getKey(), movie2);
	ht.add(movie3->getKey(), movie3);
	ht.remove(movie3->getKey(), movie3);
    return 0;
}

