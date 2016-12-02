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

class PersonManager
{
public:
    PersonManager(string fileName);
    void add(Console &c, int currentYear);
    vector<Person> getOrganizedPersons(int o);
    vector<Person> getSearchResults(Console &c);
private:
    void save(string fileName);
    bool validName(string name);
    string getFinalName(string name);
    string trim(string s);
    string capitialize(string s);
    string toLowerCase(string s);
    vector<Person> persons;
    Storage storage;
};

#endif // PERSONMANAGER_H
