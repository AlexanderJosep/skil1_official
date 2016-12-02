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

using namespace std;

class PersonManager
{
public:
    PersonManager(string fileName);
    void add(Console c, string fileName, int currentYear);
    vector<Person> getOrganizedPersons(int o);
    vector<Person> getSearchResults(Console c);
private:
    void save(string fileName);
    string toLowerCase(string s);
    vector<Person> persons;
};

#endif // PERSONMANAGER_H
