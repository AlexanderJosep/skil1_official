#ifndef STORAGE_H
#define STORAGE_H

#include <string.h>
#include <vector>
#include <fstream>
#include "person.h"

using namespace std;

class Storage {
public:
    Storage();
    Storage(string fileName);
    vector<Person> getPersons(); // loads persons from a file called 'fileName' and returns them in a vector
    void savePersons(vector<Person> persons); // saves all persons to the a file called 'fileName'
private:
    string fileName;
};

#endif // STORAGE_H
