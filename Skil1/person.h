#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(string name, short sex, short birthYear, short deathYear);
    void display();
private:
    string name;
    short sex; // 0 male, 1 female
    short birthYear;
    short deathYear; // -1 if not dead
};

#endif // PERSON_H
