#include "Database.h"

//Public //////////////////////////////////////////////////////////////////////

void Database::populate(const std::string movieFile, const std::string customerFile)
{
    populateCustomers(customerFile);
    populateMovies(movieFile);
}

// Runs a single command from the 
void Database::runCommand(const std::string entry)
{
}

// Parses a file and runs commands from inside the file
void Database::runCommands(const std::string filename)
{
}


// Dumps all the information from the database to the screen
void Database::dump()
{
}


//Private /////////////////////////////////////////////////////////////////////

void Database::populateMovies(const std::string filename){
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
void Database::populateCustomers(const std::string filename)
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
                firstname = parseSubstring(line, delimiter);;

                // Get lastname
                lastname = parseSubstring(line, delimiter);

                // Create the contents and entry
                Customer* customer = new Customer(id, firstname, lastname);
                HashEntry<Customer*>* entry = new HashEntry<Customer*>(id, customer);

                // Check to see if it already exists (we don't need multiple entries)
                if (!customers.contains(id, entry)) {
                    customers.add(id, entry);
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
bool Database::isValidCustomer(const string id)
{
    try {
        stoi(id);
    }
    catch(const std::exception& e) {
        return false;
    }
    return true;
}

void Database::addComedy(string entry)
{
    //ComedyMovie* m3 = new ComedyMovie(10, "Steven Spielberg", "Romeo and Juliet", "1973");

    int quantity;
    string director;
    string movie;
    string year;
}

void Database::addDrama(string entry)
{
    //DramaMovie* m1 = new DramaMovie(10, "Steven Spielberg", "Fat Albert", "1997"

    int quantity;
    string director;
    string movie;
    string year;
}

void Database::addClassic(string entry)
{
    //ClassicMovie* m2 = new ClassicMovie(10, "Michael King", "Ink Spots", "1941", "2", "Bill Kenney");

    int quantity;
    string director;
    string movie;
    string year;
    string month;
    string actor; // Need to know how to add actor
}

// Parses a substring from a source given a delimiter. Concatonates the string
string Database::parseSubstring(string& source, const string delimiter) {
    size_t pos;
    string result;
    pos = source.find(delimiter);
    if (pos != string::npos) {
        result = source.substr(0, pos);
        source.erase(0, pos + delimiter.length());
    }
    else {
        result = source;
    }
    return result;
}