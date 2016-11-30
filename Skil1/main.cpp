#include <iostream>
#include "personmanager.h"
#include "console.h"

using namespace std;

const string FILE_NAME = "persons.txt";

void process() {
    PersonManager pm = PersonManager(FILE_NAME);
    Console c = Console();
    c.printInstructions();
    while(true) {
        int i = c.getInstruction(0);
        if(i == 0) { // display
            c.printDisplayInstructions();
            int o = c.getInstruction(1);
            bool rev = c.getInstruction(2) == 1;
            cout << endl;
            c.printPersons(pm.getOrganizedPersons(o), rev, o);
        }
        if(i == 1) { // search

        }
        if(i == 2) { // add person

        }
        if(i == 3) { // info
            c.printInstructions();
        }
        if(i == 4) { // quit
            break;
        }
        if(i == 5) { //Secret phase

        }
    }
}

//rada eftir kyni, ari, nafni, danardag
int main()
{
    process();
    return 1;
}
