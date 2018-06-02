#include "Database.h"

//Public //////////////////////////////////////////////////////////////////////

void printMovies(HashEntry<Movie*> *m) {
	std::cout << m->getItem()->getStock() << " " << m->getItem()->getTitle() << " ";
	std::cout << m->getItem()->getDirector() << " " << m->getItem()->getYear() << std::endl;
}

void Database::getCustomerMovies(const string& id) {

	bool result = false;
	for (int i = 0; i < checkedOut.size(); ++i) {
		auto item = checkedOut.getItem(i);
		if (item->first == id) {
			result = true;
			if (item->second.size() > 0) {
				std::cout << "Customer " << id << " has the following checked out:" << std::endl;
				for (int j = 0; j < item->second.size(); ++j) {
					std::cout << item->second.getItem(j) << std::endl;
				}
			}
			else {
				std::cout << "Customer " << id << " has nothing checked out." << std::endl;
			}
		}
	}
	if (result == false) {
		std::cout << "Customer " << id << " does not exist" << std::endl;
	}
}

void Database::borrowMovie(const string& id, string& data) {
	// Parse information to get movie
	if (parseSubstring(data, " ") == "D") {
		char genre = data[0];
		if (genre == 'C' || genre == 'D' || genre || 'F') {
			parseSubstring(data, " ");

			try {
				if (stoi(parseSubstring(data, " ")) < 1900) {
					return;
				}
			}
			catch (const std::exception& e) {
				
			}

			LinkedList<string> queries;
			bool running = true;

			while (running) {
				string query = parseSubstring(data, " ");
				if (query == data) {
					running = false;
				}
				query = parseSubstring(query, ",");
				queries.add(std::move(query));
			}


			Movie* result = movies.getMovie(queries);
			
			if (result != nullptr) {
				if (result->getStock() > 0) {
				
					bool found = false;
				
					for (int i = 0; i < checkedOut.size(); ++i) {
						auto item = checkedOut.getItem(i);
						if (item->first == id) {
							if (item->second.size() > 0) {
								for (int j = 0; j < item->second.size(); ++j) {
									if (item->second.getItem(j) == result->getTitle()) {
										return;
									}
								}
							}
							item->second.add(result->getTitle());
						}
					}
					result->setStock(result->getStock() - 1);
				}
			}
			result = nullptr;
		}
	}

	// If movie found
	// Check quantity
	// If quantity > 0
	// Check to see if customer and movie are already in the list
	// If the customer exists and the movie is not in the list
	// Add the movie to the list
	// Subtract quantity by 1
}

void Database::returnMovie(const string& id, string& data) {
	// Parse information to get movie
	if (parseSubstring(data, " ") == "D") {
		char genre = data[0];
		if (genre == 'C' || genre == 'D' || genre || 'F') {
			parseSubstring(data, " ");

			try {
				if (stoi(parseSubstring(data, " ")) < 1900) {
					return;
				}
			}
			catch (const std::exception& e) {

			}

			LinkedList<string> queries;
			bool running = true;

			while (running) {
				string query = parseSubstring(data, " ");
				if (query == data) {
					running = false;
				}
				query = parseSubstring(query, ",");
				queries.add(std::move(query));
			}


			Movie* result = movies.getMovie(queries);
			if (result != nullptr) {
			    for (int i = 0; i < checkedOut.size(); ++i) {
			        auto item = checkedOut.getItem(i);
			        if (item->first == id) {
			            if (item->second.size() > 0) {
			                for (int j = 0; j < item->second.size(); ++j) {
			                    if (item->second.getItem(j) == result->getTitle()) {
			                        item->second.remove(j);
			                        result->setStock(result->getStock() + 1);
			                    }
			                }
			            }
			        }
			    }
			}
			result = nullptr;
		}
	}
	// Parse information to get movie
	// If movie found
	// Check to see if customer and movie are already in the list
	// If the customer and movie exist
	// remove the movie from list
	// Increase quantity by 1
}

void Database::populate(const std::string& customerFile, const std::string& movieFile)
{
	populateCustomers(customerFile);
	populateMovies(movieFile);
}

// Runs a single command from the file
void Database::runCommand(std::string& entry)
{
	string delimiter = " ";

	char command = entry[0];
	parseSubstring(entry, delimiter);
	switch (command) {
	case 'I':
		std::cout << "Inventory of movies:" << std::endl;
		movies.traverse(printMovies);
		std::cout << std::endl;
		break;
	case 'H':
		getCustomerMovies(parseSubstring(entry, delimiter));
		break;
	case 'B':
		borrowMovie(parseSubstring(entry, delimiter), entry);
		break;
	case 'R':
		// Parse string to get customer
		returnMovie(parseSubstring(entry, delimiter), entry);
		// If the list of movies is not empty...
		// Check further...
		// if found...
		// remove from list
		// Increase quantity by 1
		break;
	default:
		break;
	}
}

// Parses a file and runs commands from inside the file
void Database::runCommands(const std::string& filename)
{
	string line; // Line read from file
	std::ifstream file(filename);

	if (file.is_open()) {
		while (std::getline(file, line)) {
			runCommand(line);
		}
		file.close();
	}
	else {
		std::cout << "Commands could not be opened" << std::endl;
	}
}


// Dumps all the information from the database to the screen
void Database::dump()
{
}


//Private /////////////////////////////////////////////////////////////////////

void Database::populateMovies(const std::string& filename) {
	string line; // Line read from file
	std::ifstream file(filename);
	string delimiter = ", ";

	if (file.is_open()) {
		while (std::getline(file, line)) {
			char genre = line[0];
			parseSubstring(line, delimiter);
			switch (genre) {
			case 'C':
				addClassic(line);
				break;
			case 'D':
				addDrama(line);
				break;
			case 'F':
				addComedy(line);
				break;
			default:
				continue;
			}
		}
		file.close();
	}
	else {
		std::cout << "customers could not be populated" << std::endl;
	}
}

// Helper method that goes through a file of movies and populates it
void Database::populateCustomers(const std::string& filename)
{
	string line; // Line read from file
	string firstname = "";
	string lastname = "";
	string id = "";      // ID of the person in question

	string delimiter = " ";

	std::ifstream file(filename);

	if (file.is_open()) {
		while (std::getline(file, line)) {

			// Get id
			id = parseSubstring(line, delimiter);

			// We only check for a valid id, isn't worth checking other params
			// if the id isn't valid
			if (isValidCustomer(id)) {

				// Get firstname
				firstname = parseSubstring(line, delimiter);

				// Get lastname
				lastname = parseSubstring(line, delimiter);

				// Create the contents and entry
				Customer* customer = new Customer(id, firstname, lastname);
				HashEntry<Customer*>* entry = new HashEntry<Customer*>(id, customer);

				// Check to see if it already exists (we don't need multiple entries)
				if (!customers.contains(id, entry)) {
					customers.add(id, entry);
					checkedOut.add(new std::pair<string, LinkedList<string>>(id, LinkedList<string>()));
				}
			}
		}
		file.close();
	}
	else {
		std::cout << "customers could not be populated" << std::endl;
	}
}

// Returns true if the id is an integer
bool Database::isValidCustomer(const string& id)
{
	try {
		stoi(id);
	}
	catch (const std::exception& e) {
		return false;
	}
	return true;
}

void Database::addComedy(string& entry)
{
	//ComedyMovie* m3 = new ComedyMovie(10, "Steven Spielberg", "Romeo and Juliet", "1973");

	int quantity;
	string director;
	string movie;
	string year;

	try {
		quantity = stoi(parseSubstring(entry));
	}
	catch (const std::exception& e) {
		return;
	}

	director = parseSubstring(entry);
	movie = parseSubstring(entry);
	year = parseSubstring(entry);

	// Create the contents and entry
	ComedyMovie* comedy = new ComedyMovie(quantity, director, movie, year);
	HashEntry<Movie*>* comedyEntry = new HashEntry<Movie*>(comedy->getKey(), comedy);

	// Check to see if it already exists (we don't need multiple entries)
	if (!movies.contains(comedy->getKey(), comedyEntry)) {
		movies.add(comedy->getKey(), comedyEntry);
		HashEntry<Movie*>* search = movies.find(comedy->getKey(), comedyEntry);
		//Movie* search = (movies.find(classic->getKey(), classicEntry))->getItem();
		if (search != nullptr) {
			ClassicMovie* foundMovie = static_cast<ClassicMovie*>(search->getItem());
			foundMovie->setStock(foundMovie->getStock() + 10);
			foundMovie = nullptr;
		}
		//std::cout << director << " " << movie << " " << year << " " << std::endl;
	}
	else {
		delete comedy;
		delete comedyEntry;
	}

	comedy = nullptr;
	comedyEntry = nullptr;
}

void Database::addDrama(string& entry)
{
	//DramaMovie* m1 = new DramaMovie(10, "Steven Spielberg", "Fat Albert", "1997"

	int quantity;
	string director;
	string movie;
	string year;

	try {
		quantity = stoi(parseSubstring(entry));
	}
	catch (const std::exception& e) {
		return;
	}

	director = parseSubstring(entry);
	movie = parseSubstring(entry);
	year = parseSubstring(entry);

	// Create the contents and entry
	DramaMovie* drama = new DramaMovie(quantity, director, movie, year);
	HashEntry<Movie*>* dramaEntry = new HashEntry<Movie*>(drama->getKey(), drama);

	// Check to see if it already exists (we don't need multiple entries)
	if (!movies.contains(drama->getKey(), dramaEntry)) {
		movies.add(drama->getKey(), dramaEntry);
	}
	else {
		HashEntry<Movie*>* search = movies.find(drama->getKey(), dramaEntry);
		//Movie* search = (movies.find(classic->getKey(), classicEntry))->getItem();
		if (search != nullptr) {
			ClassicMovie* foundMovie = static_cast<ClassicMovie*>(search->getItem());
			foundMovie->setStock(foundMovie->getStock() + 10);
			foundMovie = nullptr;
		}

		delete drama;
		delete dramaEntry;
	}

	drama = nullptr;
	dramaEntry = nullptr;
}

void Database::addClassic(string& entry)
{
	//ClassicMovie* m2 = new ClassicMovie(10, "Michael King", "Ink Spots", "1941", "2", "Bill Kenney");

	int quantity;
	string director;
	string movie;
	string year;
	string month;
	string actor; // Need to know how to add actor

	string delimiter = " ";
	string actorFirstname;
	string actorLastname;

	try {
		quantity = stoi(parseSubstring(entry));
	}
	catch (const std::exception& e) {
		return;
	}

	director = parseSubstring(entry);
	movie = parseSubstring(entry);
	actorFirstname = parseSubstring(entry, delimiter);
	actorLastname = parseSubstring(entry, delimiter);
	month = parseSubstring(entry, delimiter);
	year = parseSubstring(entry, delimiter);

	actor = actorFirstname + " " + actorLastname;
	// Create the contents and entry
	ClassicMovie* classic = new ClassicMovie(quantity, director, movie, year, month, actor);
	HashEntry<Movie*>* classicEntry = new HashEntry<Movie*>(classic->getKey(), classic);


	HashEntry<Movie*>* search = movies.find(classic->getKey(), classicEntry);
	//Movie* search = (movies.find(classic->getKey(), classicEntry))->getItem();

	if (search != nullptr) {
		ClassicMovie* foundMovie = static_cast<ClassicMovie*>(search->getItem());
		if (!foundMovie->containsActor(actor)) {
			auto list = foundMovie->getLeadActors();
			list.add(actor);
			std::cout << actor << " added to " << movie << std::endl;
			foundMovie->setStock(foundMovie->getStock() + 10);
		}
		foundMovie = nullptr;
	}

	// Check to see if it already exists (we don't need multiple entries)
	//if (!movies.contains(classic->getKey(), classicEntry)) {
	else {
		movies.add(classic->getKey(), classicEntry);
		//std::cout << director << " " << movie << " " << year << " " << actor << std::endl;
	}
	search = nullptr;
	classic = nullptr;
	classicEntry = nullptr;
}

// Parses a substring from a source given a delimiter. Concatonates the string
string Database::parseSubstring(string& source, const string& delimiter) {
	size_t pos;
	string result;
	pos = source.find(delimiter);
	if (pos != string::npos) {
		result = source.substr(0, pos);
		source.erase(0, pos + delimiter.length());
		source.shrink_to_fit();
	}
	else {
		result = source;
	}
	return result;
}
