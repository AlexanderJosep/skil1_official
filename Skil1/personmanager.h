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
    vector<Person> getOrganizedPersons(int o);
    void displayPersons(int o, bool rev);
private:
    vector<Person> persons;
};

#endif // PERSONMANAGER_H
