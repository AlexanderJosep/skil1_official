#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(string name, short gender, short birthYear, short deathYear);
    string getName();
    short getGender();
    short getBirthYear();
    short getDeathYear();
    string getOutput(int type);
private:
    void updateString(string &o, string data);
    string name;
    short gender; // 0 male, 1 female
    short birthYear;
    short deathYear; // -1 if not dead
};

#endif // PERSON_H
