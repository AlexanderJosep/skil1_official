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

//type: 0/1 = organize by name, 2 = organize by gender, 3 = organize by birth year, 4 = organize by death year
void Person::display(int type) {
    string out = "";
    string s = (gender == 0 ? "Male" : "Female");
    if(type == 0 || type == 1) {
        updateString(out, "Name: " + name);
    }
    if(type == 2) {
        updateString(out, "Gender: " + s);
    }
    if(type == 3) {
       updateString(out, "Birth year: " + birthYear);
    }
    if(type == 4) {
        updateString(out, "Year of death: " + deathYear);
    }

    if(type != 0 && type != 1) {
        updateString(out, "Name: " + name);
    }
    if(type != 2) {
        updateString(out, "Gender: " + s);
    }
    if(type != 3) {
       updateString(out, "Birth year: " + birthYear);
    }
    if(type != 4 && deathYear >= 0) {
        updateString(out, "Year of death: " + deathYear);
    }
    cout << out << endl;
}

void Person::updateString(string &o, string data) {
    if(o.length() > 0) {
        o += ", ";
    }
    o += data;
}
