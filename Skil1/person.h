#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(string name, short sex, short birthYear, short deathYear);
    string getName();
    short getSex();
    short getBirthYear();
    short getDeathYear();
    void display(int type);
private:
    void updateString(string &o, string data);
    string name;
    short sex; // 0 male, 1 female
    short birthYear;
    short deathYear; // -1 if not dead
};

#endif // PERSON_H
