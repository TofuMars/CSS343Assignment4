#include "Database.h"
//Helper Methods //////////////////////////////////////////////////////////////

// Used with travers to print out all its info
void printMovies(HashEntry<Movie*> *m) {
	std::cout << m->getItem()->getStock() << " ";
	std::cout << m->getItem()->getTitle() << " ";
	std::cout << m->getItem()->getDirector() << " ";
	std::cout << m->getItem()->getYear() << std::endl;
}

//Public //////////////////////////////////////////////////////////////////////

// Populates Database with contents of two files
void Database::populate(const std::string& customerFile, 
						const std::string& movieFile)
{
	populateCustomers(customerFile);
	populateMovies(movieFile);
}

// Runs on operation on the Database
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

// Runs a series of commands from a file
void Database::runCommand(std::string& entry)
{
	string delimiter = " ";

	char command = entry[0]; // First letter determines type of command
	parseSubstring(entry, delimiter);
	switch (command) {
	case 'I': // Get inventory
		std::cout << "Inventory of movies:" << std::endl;
		movies.traverse(printMovies);
		std::cout << std::endl;
		break;
	case 'H': // Get checked out movies of customer
		getCustomerMovies(parseSubstring(entry, delimiter));
		break;
	case 'B': // Customer borrows movie
		borrowMovie(parseSubstring(entry, delimiter), entry);
		break;
	case 'R': // Customer returns movie
		returnMovie(parseSubstring(entry, delimiter), entry);
		break;
	default:
		break;
	}
}

//Private /////////////////////////////////////////////////////////////////////

// Populates movies with the contents of a file
void Database::populateMovies(const std::string& filename) {
	string line; // Line read from file
	std::ifstream file(filename);
	string delimiter = ", ";

	if (file.is_open()) {
		while (std::getline(file, line)) {
			char genre = line[0]; // First letter defines genre
			parseSubstring(line, delimiter);
			switch (genre) {
			case 'C': // Add classic movie
				addClassic(line);
				break;
			case 'D': // Add drama movie
				addDrama(line);
				break;
			case 'F': // Add comedy movie
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

// Helper method to add a comedy to movies
void Database::addComedy(string& entry)
{

	int quantity;
	string director;
	string movie;
	string year;

	try {
		quantity = stoi(parseSubstring(entry));
	}
	catch (const std::exception&) {
		// If the quantity isn't a number, we're not gonna add it
		return;
	}

	director = parseSubstring(entry);
	movie = parseSubstring(entry);
	year = parseSubstring(entry);

	// Create the contents and entry
	ComedyMovie* comedy = new ComedyMovie(quantity, director, movie, year);
	HashEntry<Movie*>* comedyEntry =
		new HashEntry<Movie*>(comedy->getKey(), comedy);

	// Check to see if it already exists (we don't need multiple entries)
	if (!movies.contains(comedy->getKey(), comedyEntry)) {
		movies.add(comedy->getKey(), comedyEntry);
		HashEntry<Movie*>* search = movies.find(comedy->getKey(), comedyEntry);
		if (search != nullptr) {
			ClassicMovie* foundMovie =
				static_cast<ClassicMovie*>(search->getItem());
			foundMovie->setStock(foundMovie->getStock() + 10);
			foundMovie = nullptr;
		}
	}
	else {
		delete comedy;
		delete comedyEntry;
	}

	comedy = nullptr;
	comedyEntry = nullptr;
}

// Helper method to add a drama to movies
void Database::addDrama(string& entry)
{
	int quantity;
	string director;
	string movie;
	string year;

	try {
		quantity = stoi(parseSubstring(entry));
	}
	catch (const std::exception&) {
		// If the quantity isn't a number, we're not gonna add it
		return;
	}

	director = parseSubstring(entry);
	movie = parseSubstring(entry);
	year = parseSubstring(entry);

	// Create the contents and entry
	DramaMovie* drama = new DramaMovie(quantity, director, movie, year);
	HashEntry<Movie*>* dramaEntry =
		new HashEntry<Movie*>(drama->getKey(), drama);

	// Check to see if it already exists (we don't need multiple entries)
	if (!movies.contains(drama->getKey(), dramaEntry)) {
		movies.add(drama->getKey(), dramaEntry);
	}
	else {
		HashEntry<Movie*>* search = movies.find(drama->getKey(), dramaEntry);
		if (search != nullptr) {
			ClassicMovie* foundMovie =
				static_cast<ClassicMovie*>(search->getItem());
			foundMovie->setStock(foundMovie->getStock() + 10);
			foundMovie = nullptr;
		}

		delete drama;
		delete dramaEntry;
	}

	drama = nullptr;
	dramaEntry = nullptr;
}

// Helper method to add a classic to movies
void Database::addClassic(string& entry)
{

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
	catch (const std::exception&) {
		// If the quantity isn't a number, we're not gonna add it
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
	ClassicMovie* classic =
		new ClassicMovie(quantity, director, movie, year, month, actor);
	HashEntry<Movie*>* classicEntry =
		new HashEntry<Movie*>(classic->getKey(), classic);

	// Search for the movie
	HashEntry<Movie*>* search = movies.find(classic->getKey(), classicEntry);
	if (search != nullptr) {
		ClassicMovie* foundMovie =
			static_cast<ClassicMovie*>(search->getItem());
		// If the actor isn't in there, add an actor
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
	}
	search = nullptr;
	classic = nullptr;
	classicEntry = nullptr;
}


// Populates customers with the contents of a file
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
				HashEntry<Customer*>* entry =
					new HashEntry<Customer*>(id, customer);

				// Check to see if it already exists (we don't need multiple 
				// entries)
				if (!customers.contains(id, entry)) {
					customers.add(id, entry);
					checkedOut.add(new std::pair<string, LinkedList<string>>
						(id, LinkedList<string>()));
				}
			}
		}
		file.close();
	}
	else {
		std::cout << "customers could not be populated" << std::endl;
	}
}

// Helper method to see if the id number is valid
bool Database::isValidCustomer(const string& id)
{
	try {
		stoi(id);
	}
	catch (const std::exception&) {
		return false;
	}
	return true;
}

// Prints out all the movies that a given customer has checked out.
void Database::getCustomerMovies(const string& id) {

	bool result = false;
	for (int i = 0; i < checkedOut.size(); ++i) {
		auto item = checkedOut.getItem(i);
		if (item->first == id) {
			result = true;
			if (item->second.size() > 0) {
				std::cout << "Customer " << id;
				std::cout << " has the following checked out:" << std::endl;
				for (int j = 0; j < item->second.size(); ++j) {
					std::cout << item->second.getItem(j) << std::endl;
				}
			}
			else {
				std::cout << "Customer " << id << " has nothing checked out.";
				std::cout << std::endl;
			}
		}
	}
	if (result == false) {
		std::cout << "Customer " << id << " does not exist" << std::endl;
	}
}

// If a customer does not have a specified movie checked out, the movie is
// removed from checkedOut and the the movie's quantity is decreased by 1
void Database::borrowMovie(const string& id, string& data) {
	// Parse information to get movie
	if (parseSubstring(data, " ") == "D") {
		char genre = data[0];
		if (genre == 'C' || genre == 'D' || genre || 'F') {
			parseSubstring(data, " ");

			// Don't want to let people check out multiple copies of the same
			// movie
			try {
				if (stoi(parseSubstring(data, " ")) < 1900) {
					return;
				}
			}
			catch (const std::exception&) {
				
			}

			// Break up the data we recieve in the function into smaller
			// queries to do a lookup with
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

			// Find in the Hashtable
			Movie* result = movies.getMovie(queries);
			
			// If found...
			if (result != nullptr) {
				// Check to make there are enough movies
				if (result->getStock() > 0) {
					for (int i = 0; i < checkedOut.size(); ++i) {
						// Get the customer
						auto item = checkedOut.getItem(i);
						if (item->first == id) {
							if (item->second.size() > 0) {
								for (int j = 0; j < item->second.size(); ++j) {
									// If the movie is in the inventory, don't
									// let the customer borrow it
									if (item->second.getItem(j) ==
										result->getTitle()) {
										return;
									}
								}
							}
							// The customer borrows the movie
							item->second.add(result->getTitle());
						}
					}
					// The stock is adjusted
					result->setStock(result->getStock() - 1);
				}
			}
			result = nullptr;
		}
	}
}

// If a customer has a specified movie checked out, the movie is removed
// from checkedOut and the the movie's quantity is increased by 1
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
			catch (const std::exception&) {

			}

			// Break up the data we recieve in the function into smaller
			// queries to do a lookup with
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

			// Try to do a lookup
			Movie* result = movies.getMovie(queries);
			if (result != nullptr) {
			    for (int i = 0; i < checkedOut.size(); ++i) {
					// Get the customer
			        auto item = checkedOut.getItem(i);
					// If the customer is the required one...
			        if (item->first == id) {
						// Look for the movie
			            if (item->second.size() > 0) {
			                for (int j = 0; j < item->second.size(); ++j) {
								// If the movie was found in the list...
			                    if (item->second.getItem(j) ==
									result->getTitle()) {
									// Return the movie to the inventory
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
}

// Creates a substring from a source string with a defined delimiter
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
