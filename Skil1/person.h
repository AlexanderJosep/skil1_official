#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

class Person {
public:
    Person(string name, short gender, short birthYear, short deathYear);
    string getName();
    short getGender();
    short getBirthYear();
    short getDeathYear();
    void setData(string name, short gender, short birthYear, short deathYear); // set name, gender, birthYear and deathYear
    string getStoreOutput(); // gets output ready to be saved to a file
    string getOutput(); // gets output ready to be printed to the console
private:
    void updateString(ostringstream &o, string data, int &priorLength, int columnSize); // helps with getting ouput string for console
    string name;
    short gender; // 0 male, 1 female
    short birthYear;
    short deathYear; // -1 if not dead
};

#endif // PERSON_H
