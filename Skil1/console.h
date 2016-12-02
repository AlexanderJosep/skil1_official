#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Console
{
public:
    Console();
    char getChar(string s);
    short getShort(string s);
    bool getBool(string s);
    string getString(string s, bool ignore);
    void addW(int w);
    void print(string s);
    void println(string s);
    void newLine();
    void clearBuffer();
    int getInstruction(int type);
    void printInstructions();
    void printDisplayInstructions();
    void printColumns();
    void printPersons(vector<Person> persons, bool reverse);
    void process(string fileName);
private:
    int getIndex(char c, int type);
};



#endif // CONSOLE_H
