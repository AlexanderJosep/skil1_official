#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "person.h"

using namespace std;

class PersonManager
{
public:
    PersonManager(string fileName);
    void add(string fileName, string name, short gender, short birthYear, short deathYear);
    vector<Person> getOrganizedPersons(int o);
    void displayPersons(int o, bool rev);
private:
    void save(string fileName);
    vector<Person> persons;
};

#endif // PERSONMANAGER_H
