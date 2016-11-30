#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Console
{
public:
    Console();
    int getInstruction(int type);
    void printInstructions();
    void printDisplayInstructions();
    void printPersons(vector<Person> persons, bool reverse, int o);
private:
    char getChar(string s);
    int getIndex(char c, int type);
};



#endif // CONSOLE_H
