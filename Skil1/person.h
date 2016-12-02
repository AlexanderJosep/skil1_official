#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

class Person
{
public:
    Person(string name, short gender, short birthYear, short deathYear);
    string getName();
    short getGender();
    short getBirthYear();
    short getDeathYear();
    string getNationality();
    string getStoreOutput();
    string getOutput();
private:
    void updateString(ostringstream &o, string data, int &priorLength, int columnSize);
    string name;
    short gender; // 0 male, 1 female
    short birthYear;
    short deathYear; // -1 if not dead
    string nationality;
};

#endif // PERSON_H
