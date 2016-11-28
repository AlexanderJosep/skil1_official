#include "person.h"

Person::Person(string name, short sex, short birthYear, short deathYear)
{
    this -> name = name;
    this -> sex = sex;
    this -> birthYear = birthYear;
    this -> deathYear = deathYear;
}

void Person::display() {
    cout << "Name: " << name << endl;
    cout << "Sex: " << (sex == 0 ? "Male" : "Female") << endl;
    cout << "Birth year: " << birthYear << endl;
    if(deathYear >= 0) {
        cout << "Year of death: " << deathYear << endl;
    }
}
