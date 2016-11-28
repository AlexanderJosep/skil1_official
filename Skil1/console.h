#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

using namespace std;

class Console
{
public:
    Console();
    int getInstruction();
    void printInstructions();
private:
    char getChar(string s);
    bool isValid(char c);
};



#endif // CONSOLE_H
