#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "personmanager.h"
#include "console.h"

using namespace std;

const string FILE_NAME = "persons.txt";

void process() {
    PersonManager pm = PersonManager(FILE_NAME);
    Console c = Console();

    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    int currentYear = tPtr -> tm_year + 1900;
    c.println("The year is "+to_string(currentYear)+" and you're on Earth.");

    c.printInstructions();
    while(true) {
        int i = c.getInstruction(0);
        if(i == 0) { // display
            c.printDisplayInstructions();
            int o = c.getInstruction(1);
            bool rev = c.getInstruction(2) == 1;
            cout << endl;
            c.printColumns();
            c.printPersons(pm.getOrganizedPersons(o), rev, o);
        }
        if(i == 1) { // search
            c.printPersons(pm.getSearchResults(c), false, 0);
        }
        if(i == 2) { // add person
            pm.add(c, FILE_NAME, currentYear);
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
int main() {
    process();
    return 1;
}
