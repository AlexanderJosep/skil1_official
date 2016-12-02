#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include "person.h"

using namespace std;

class Console {
public:
    Console();
    void addW(int w); // prints setw(w) to the console
    void print(string s); // prints s to the console
    void println(string s); // prints s and \n to the console
    void newLine(); // prints \n to the console
    void printInstructions(); // prints all basic command instructions
    void printDisplayInstructions(); // prints all display organization instructions
    void printColumns(bool includeIndex); // print all columns
    void printPersons(vector<Person> persons, bool reverse, bool includeIndex); // print all persons and reverses the output if reverse is true
    void clearBuffer(); // clears the stream buffer until it reaches \n
    char getChar(string s); // gets user input char
    short getShort(string s); // gets user input short
    bool getBool(string s); // gets user input bool (y/n)
    string getString(string s, bool ignore); // gets user input string and if ignore is true it ignores the first letter in the input buffer
    int getInstruction(int type); // gets the basic and organization command instruction
    void process(string fileName); // includes the main program loop
private:
    int getIndex(char c, int type); // gets the index of the basic/organization command
};



#endif // CONSOLE_H
