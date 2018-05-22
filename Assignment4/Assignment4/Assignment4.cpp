// Assignment4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "Movie.h"
#include "HashEntry.h"
#include "HashTable.h"
#include "Database.h"

using std::cin;
using std::cout;
string getMovieKey(Movie* movie) { return movie->getKey(); }
void printMovieTitle(HashEntry<Movie*>* m) { cout << m->getItem()->getTitle() << std::endl; }

int main()
{
    Database database;
    // Populate database

    // Run commands from file

    //Dump everything we have from the file?

	//list<Movie*> movies;
	DramaMovie* m1 = new DramaMovie(10, "Steven Spielberg", "Fat Albert", "1997");
	ClassicMovie* m2 = new ClassicMovie(10, "Michael King", "Ink Spots", "1941", "2", "Bill Kenney");
	ComedyMovie* m3 = new ComedyMovie(10, "Steven Spielberg", "Romeo and Juliet", "1973");
	DramaMovie* m4 = new DramaMovie(10, "Daniel Smith", "The Mask", "1997");
	ClassicMovie* m5 = new ClassicMovie(10, "Slieve McDichael", "Bob's Train", "1941", "2", "Bing Crosby");
	ComedyMovie* m6 = new ComedyMovie(10, "Oprah Winfrey", "La Vie en Nose", "1973");
	DramaMovie* m7 = new DramaMovie(10, "William DeFoe", "Robertson Curusoe", "1997");
	ClassicMovie* m8 = new ClassicMovie(10, "Wen Shi", "Big Trouble in Beijing", "1941", "2", "Jet Li");
	ComedyMovie* m9 = new ComedyMovie(10, "Jotaro Kujo", "Jojo's Bizarre Adventure: Stardust Crusaders", "1973");
	
	HashEntry<Movie*>* movie1 = new HashEntry<Movie*>(getMovieKey(m1), m1);
	HashEntry<Movie*>* movie2 = new HashEntry<Movie*>(getMovieKey(m2), m2);
	HashEntry<Movie*>* movie3 = new HashEntry<Movie*>(getMovieKey(m3), m3);
	HashEntry<Movie*>* movie4 = new HashEntry<Movie*>(getMovieKey(m4), m4);
	HashEntry<Movie*>* movie5 = new HashEntry<Movie*>(getMovieKey(m5), m5);
	HashEntry<Movie*>* movie6 = new HashEntry<Movie*>(getMovieKey(m6), m6);
	HashEntry<Movie*>* movie7 = new HashEntry<Movie*>(getMovieKey(m7), m7);
	HashEntry<Movie*>* movie8 = new HashEntry<Movie*>(getMovieKey(m8), m8);
	HashEntry<Movie*>* movie9 = new HashEntry<Movie*>(getMovieKey(m9), m9);

	HashTable<Movie*> ht;
	ht.add(movie1->getKey(), movie1);
	ht.add(movie2->getKey(), movie2);
	ht.add(movie3->getKey(), movie3);
	ht.add(movie4->getKey(), movie4);
	ht.add(movie5->getKey(), movie5);
	ht.add(movie6->getKey(), movie6);
	ht.add(movie7->getKey(), movie7);
	ht.add(movie8->getKey(), movie8);
	ht.add(movie9->getKey(), movie9);

	ht.traverse(printMovieTitle);

	ht.remove(movie4->getKey(), movie4);
    return 0;
}

