#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string.h>
#include "person.h"
#include "console.h"
#include "storage.h"

using namespace std;

class PersonManager {
public:
    PersonManager(string fileName, int currentYear);
    void add(Console &c); // adds a new person to the list
    void edit(Console &c, vector<Person> pList); // edits a person in the persons list
    vector<Person> getOrganizedPersons(int o); // gets organized persons list which organizes by type o
    vector<Person> getSearchResults(Console &c); // gets a search input and find the results according to that
private:
    bool validName(string name); // checks if a name is valid or not
    string trim(string s); // trims the edges of a string for any pesky spaces
    string capitialize(string s); // capitalizes a string
    string toLowerCase(string s); // lowercases a string
    string getName(Console &c, bool n); // gets the name from user input, n is true if user is creating a new person, false if editing
    short getGender(Console &c, bool n); // gets the gender from user input, n is true if user is creating a new person, false if editing
    short getBirthYear(Console &c, bool n); // gets the birth year from user input, n is true if user is creating a new person, false if editing
    short getDeathYear(Console &c, bool n, int birthYear); // gets the death year from user input, n is true if user is creating a new person, false if editing
    vector<Person> persons;
    Storage storage;
    int currentYear;
};

#endif // PERSONMANAGER_H
