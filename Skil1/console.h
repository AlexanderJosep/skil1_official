#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

using namespace std;

class Console
{
public:
    Console();
    int getInstruction(int type);
    void printInstructions();
    void printDisplayInstructions();
private:
    char getChar(string s);
    int getIndex(char c, int type);
};



#endif // CONSOLE_H
