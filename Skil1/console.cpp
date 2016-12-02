#include "console.h"

//display, search, add, info, quit, no organization, org. names in alphabetical order, org. by gender, org. by birth year, org. by death year
const char commands[10] = {'d', 's', 'a', 'i', 'q', 'o', 'n', 'g', 'b', 'd'};
const string instructions[5] = {"Use 'a' to add a person.", "Use 'd' to display persons.", "Use 'i' to display info on instructions.",
                                "Use 's' to search for a person.", "Use 'q' if you want to quit."};

const string displayInstructions[5] = {"Use 'b' to organize by birth year." ,"Use 'd' to organize by death year." ,"Use 'g' to organize by gender.",
                                       "Use 'n' to organize by names in alphabetical order." ,"Use 'o' to have no organization."};

Console::Console()
{

}

void Console::addW(int w) {
    cout << setw(w);
}

void Console::print(string s) {
    cout << s;
}

void Console::println(string s) {
    cout << s << endl;
}

void Console::newLine() {
    cout << endl;
}

void Console::clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Console::printInstructions() {
    for(int i = 0; i < 6; i++) {
        println(instructions[i]);
    }
}

void Console::printDisplayInstructions() {
    for(int i = 0; i < 5; i++) {
        println(displayInstructions[i]);
    }
}

void Console::printColumns() {
    print("Name");
    addW(30);
    print("Gender");
    addW(16);
    print("Birth year");
    addW(16);
    println("Death year");
    for (int i = 0; i < 70; i++) {
        print("=");
    }
    newLine();
}

char Console::getChar(string s) {
    print(s + ": ");
    char c;
    cin >> c;
    return c;
}

short Console::getShort(string s) {
    print(s + ": ");
    short in;
    cin >> in;
    return in;
}

bool Console::getBool(string s) {
    char c;
    while(true) {
        clearBuffer();
        print(s + " (y/n): ");
        cin >> c;
        if(c == 'y' || c == 'n') {
            break;
        }
        println("Invalid command!");
    }
    return c == 'y';
}

string Console::getString(string s) {
    string in;
    while(true) {
        cin.ignore();
        print(s + " (max 30 chars): ");
        getline(cin, in);
        if(in.length() <= 30) {
            break;
        }
        println("Please don't use more than 30 characters.");
    }
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
    int i;
    while(true) {
        i = getIndex(getChar((type == 0 ? "Instruction" : "Organization")), type);
        if(i < 0) {
            println("Invalid command!");
            clearBuffer();
            continue;
        } else {
            break;
        }
    }
    return i - (type == 1 ? 5 : 0);
}

void Console::printPersons(vector<Person> persons, bool reverse) {
    if(persons.size() <= 0) {
        println("No persons to display.");
        return;
    }
    newLine();
    printColumns();
    for(unsigned int i = (reverse ? persons.size() - 1 : 0); i < persons.size(); i += (reverse ? -1 : 1)) {
        println(persons[i].getOutput());
    }
    newLine();
}
