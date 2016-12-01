#include "person.h"

Person::Person(string name, short gender, short birthYear, short deathYear)
{
    this -> name = name;
    this -> gender = gender;
    this -> birthYear = birthYear;
    this -> deathYear = deathYear;
}

string Person::getName() {
    return name;
}

short Person::getGender() {
    return gender;
}

short Person::getBirthYear() {
    return birthYear;
}

short Person::getDeathYear() {
    return deathYear;
}

string Person::getStoreOutput() {
    string copy = name;
    replace(copy.begin(), copy.end(), ' ', '_' );
    return copy + " " + to_string(gender) + " " + to_string(birthYear) + " " + to_string(deathYear);
}

//type: 0/1 = organize by name, 2 = organize by gender, 3 = organize by birth year, 4 = organize by death year
string Person::getOutput(int type) {
    ostringstream out;
    string s = (gender == 0 ? "Male" : "Female");
    int priorLength  = 0;
    if(type == 0 || type == 1) {
        updateString(out, "" + name, priorLength);
    }
    if(type == 2) {
        updateString(out, "" + s, priorLength);
    }
    if(type == 3) {
        updateString(out, "" + to_string(birthYear), priorLength);
    }
    if(type == 4) {
        updateString(out, "" + to_string(deathYear), priorLength);
    }
    if(type != 0 && type != 1) {
        updateString(out, "" + name, priorLength);
    }
    if(type != 2) {
        updateString(out, "" + s, priorLength);
    }
    if(type != 3) {
        updateString(out, "" + to_string(birthYear), priorLength);
    }
    if(type != 4 && deathYear >= 0) {
        updateString(out, "" + to_string(deathYear), priorLength);
    }
    return out.str();
}

void Person::updateString(ostringstream &o, string data, int &priorLength) {
    if(o.tellp() > 0 && priorLength < 30) {
        o << setw(30 - (priorLength - data.length()));
    }
    o << data;
    priorLength = data.length();
}
