#include "console.h"
#include <iomanip>

//display, search, add, info, quit, no organization, org. names in alphabetical order, org. by gender, org. by birth year, org. by death year
const char commands[11] = {'d', 's', 'a', 'i', 'q', 'S', 'o', 'n', 'g', 'b', 'd'};
const string instructions[6] = {"Use 'a' to add a person", "Use 'd' to display persons ", "Use 'i' to display info on instructions",
                                "Use 's' to search for a person", "Use 'q' if you want to quit.", "Use 'S' for a secret ;)."};
const string displayInstructions[3] = {"Organizing: Use 'n' to organize by names in alphabetical order.",
                                       "Use 'g' to organize by gender, 'b' to organize by birth year and 'd' to organize by death year.",
                                       "Use 'o' to have no organization."};

Console::Console()
{

}

void Console::printInstructions() {
    for(int i = 0; i < 6; i++) {
         cout << instructions[i] << endl;
    }
}

void Console::printDisplayInstructions() {
    for(int i = 0; i < 3; i++) {
         cout << displayInstructions[i] << endl;
    }
}

void Console::printColumns() {
    cout << "Name:" << setw(30) << "Gender:" << setw(30) << "Birth year:" << setw(30) << "Death year:" << endl;
    for (int i = 0; i < 110; i++) {
        cout << "=";
    }
    cout << endl;
}

char Console::getChar(string s) {
    cout << s << ": ";
    char c;
    cin >> c;
    return c;
}

short Console::getShort(string s) {
    cout << s << ": ";
    short in;
    cin >> in;
    return in;
}

string Console::getString(string s) {
    cout << s << ": ";
    string in;
    cin >> in;
    return in;
}

//type = 0 checks for basic commands, type = 1 checks for display organization commands
int Console::getIndex(char c, int type) {
    for(int i = type * 5; i < (type + 1) * 5; i++) {
        if(c == commands[i]) {
            return i;
        }
    }
    return -1;
}

int Console::getInstruction(int type) {
    if(type == 2) {
        return (getChar("Reverse output (y/n)") == 'y' ? 1 : 0);
    }
    int i;
    while(true) {
        i = getIndex(getChar((type == 0 ? "Instruction" : "Organization")), type);
        if(i < 0) {
            cout << "Invalid command!" << endl;
            continue;
        } else {
            break;
        }
    }
    return i - (type == 1 ? 5 : 0);
}

void Console::printPersons(vector<Person> persons, bool reverse, int o) {
    for(unsigned int i = (reverse ? persons.size() - 1 : 0); i < persons.size(); i += (reverse ? -1 : 1)) {
        cout << persons[i].getOutput(o) << endl;
    }
}
