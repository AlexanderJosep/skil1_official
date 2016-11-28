#include "personmanager.h"

PersonManager::PersonManager(string fileName)
{
    ifstream in;
    in.open(fileName);
    string name;
    short sex;
    short birthYear;
    short deathYear;
    while(in >> name && in >> sex && in >> birthYear && in >> deathYear) {
        replace(name.begin(), name.end(), '_', ' ' );
        persons.push_back(Person(name, sex, birthYear, deathYear));
    }
    in.close();
}

void PersonManager::displayPersons() {
    for(unsigned int i = 0; i < persons.size(); i++) {
        persons[i].display();
        cout << "_____________________" << endl;
    }
}
