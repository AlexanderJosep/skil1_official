#include "storage.h"

Storage::Storage() {

}

Storage::Storage(string fileName) {
    this -> fileName = fileName;
}

vector<Person> Storage::getPersons() {
    vector<Person> persons;
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
    return persons;
}

void Storage::savePersons(vector<Person> persons) {
    ofstream out;
    out.open(fileName);
    for(unsigned int i = 0; i < persons.size(); i++) {
        out << persons[i].getStoreOutput() << endl;
    }
}



