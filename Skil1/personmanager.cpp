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
    if(o == 3 || o == 4) { // organize by birth year or by death year
        vector<int> years;
        vector<Person> copy;
        for(unsigned int i = 0; i < persons.size(); i++) {
            if((o == 3 && persons[i].getBirthYear() >= 0) || (o == 4 && persons[i].getDeathYear() >= 0)) {
                years.push_back(o == 3 ? persons[i].getBirthYear() : persons[i].getDeathYear());
            }
        }
        sort(years.begin(), years.end());
        for(unsigned int i = 0; i < persons.size(); i++) {
            copy.push_back(persons[i]);
        }
        for(unsigned int i = 0; i < years.size(); i++) {
            for(unsigned int j = 0; j < copy.size(); j++) {
                if((o == 3 && years[i] == copy[j].getBirthYear()) || (o == 4 && years[i] == copy[j].getDeathYear())) {
                    out.push_back(copy[j]);
                    copy.erase(copy.begin() + j);
                    break;
                }
            }
        }
        return out;

    }
    return out;
}
