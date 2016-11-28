#include <iostream>
#include "personmanager.h"
#include "console.h"

using namespace std;

const string FILE_NAME = "persons.txt";
const string displayInstructions[2] = {"Organizing: Use 's' to organize by sex, ", "Use 'q' if you want to quit."};

char getChar() {
    char c;
    cin >> c;
    return c;
}

void process() {
    PersonManager pm = PersonManager(FILE_NAME);
    Console c = Console();
    c.printInstructions();
    while(true) {
        int i = c.getInstruction();
        if(i == 0) {
            pm.displayPersons();
        }
        if(i == 2) {
            c.printInstructions();
        }
        if(i == 3) {
            break;
        }
    }
}

//rada eftir kyni, ari, nafni, danardag
int main()
{
    process();
    return 1;
}
