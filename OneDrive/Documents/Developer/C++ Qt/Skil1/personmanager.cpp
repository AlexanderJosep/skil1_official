#include "personmanager.h"

PersonManager::PersonManager(char fileName[])
{
    ifstream in;
    in.open(fileName);
    string name;
    short sex;
    short birthYear;
    short deathYear;
    while(in >> name && in >> sex && in >> birthYear && in >> deathYear) {
        persons.push_back(Person(name, sex, birthYear, deathYear));
    }
}
