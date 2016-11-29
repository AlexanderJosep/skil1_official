#include "personmanager.h"

PersonManager::PersonManager(string fileName)
{
    ifstream in;
    in.open(fileName);
    string name;
    short gender;
    short birthYear;
    short deathYear;
    while(in >> name && in >> gender && in >> birthYear && in >> deathYear) {
        replace(name.begin(), name.end(), '_', ' ' );
        persons.push_back(Person(name, gender, birthYear, deathYear));
    }
    in.close();
}

vector<Person> PersonManager::getOrganizedPersons(int o) {
    if(o == 0) { // no organizing
        return persons;
    }
    vector<Person> out;
    if(o == 1) { // organize by names alphabetically
        vector<string> names;
        for(unsigned int i = 0; i < persons.size(); i++) {
            names.push_back(persons[i].getName());
        }
        sort(names.begin(), names.end());
        for(unsigned int i = 0; i < names.size(); i++) {
            for(unsigned int j = 0; j < persons.size(); j++) {
                if(names[i] == persons[j].getName()) {
                    out.push_back(persons[j]);
                    break;
                }
            }
        }
        return out;
    }
    if(o == 2) { // organize by gender
        for(int j = 0; j < 2; j++) {
            for(unsigned int i = 0; i < persons.size(); i++) {
                if(persons[i].getGender() == j) {
                    out.push_back(persons[i]);
                }
            }
        }
        return out;
    }
    if(o == 3) { // organize by birth year
        for(unsigned int i = 0; i < persons.size(); i++) {
            if(persons[i].getBirthYear() > persons[i + 1].getBirthYear()) {
                out.push_back(persons[i]);
            }
        }
    }
    if(o == 4) { // organize by death year

    }
    return out;
}

void PersonManager::displayPersons(int o, bool rev) {
    vector<Person> persons = getOrganizedPersons(o);
    for(unsigned int i = (rev ? persons.size() - 1 : 0); i < persons.size(); i += (rev ? -1 : 1)) {
        persons[i].display(o);
    }
}
