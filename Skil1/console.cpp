#include "console.h"
#include "personmanager.h"
#include "snake.h"

// display, search, add, info, quit, clear console, edit, remove
// no organization, org. names in alphabetical order, org. by gender, org. by birth year, org. by death year
const char commands[14] = {'d', 's', 'a', 'i', 'q', 'c', 'e', 'r', 'g',
                           'o', 'n', 'g', 'b', 'd'};
const string instructions[9] = {"Use 'a' to add a person.", "Use 'c' to clear the console.", "Use 'd' to display persons.",
                                "Use 'e' to edit a person.","Use 'g' to start a game of snake.",
                                "Use 'i' to display info on instructions.", "Use 'r' to remove a person.",
                                "Use 's' to search for a person.", "Use 'q' if you want to quit."};
const string displayInstructions[5] = {"Use 'b' to organize by birth year." ,"Use 'd' to organize by death year." ,"Use 'g' to organize by gender.",
                                       "Use 'n' to organize by names in alphabetical order." ,"Use 'o' to have no organization."};

Console::Console() {

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
    for(int i = 0; i < 9; i++) {
        println(instructions[i]);
    }
}

void Console::printDisplayInstructions() {
    for(int i = 0; i < 5; i++) {
        println(displayInstructions[i]);
    }
}

void Console::printColumns(bool includeIndex) {
    if(includeIndex) {
        print("      ");
    }
    print("Name");
    addW(30);
    print("Gender");
    addW(16);
    print("Birth year");
    addW(16);
    println("Death year");
    if(includeIndex) {
        print("      ");
    }
    for (int i = 0; i < 66; i++) {
        print("=");
    }
    newLine();
}

void Console::printPersons(vector<Person> persons, bool reverse, bool includeIndex) {
    if(persons.size() <= 0) {
        println("No persons to display.");
        return;
    }
    newLine();
    printColumns(includeIndex);
    for(unsigned int i = (reverse ? persons.size() - 1 : 0); i < persons.size(); i += (reverse ? -1 : 1)) {
        if(includeIndex) {
            string s = to_string(i + 1);
            print(s);
            for(unsigned int j = 0; j < 6 - s.length(); j++) {
                print(" ");
            }
        }
        println(persons[i].getOutput());
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

string Console::getString(string s, bool ignore) {
    string in;
    while(true) {
        if(ignore) {
            cin.ignore();
        }
        print(s + " (max 30 chars): ");
        getline(cin, in);
        if(in.length() <= 30) {
            break;
        }
        println("Please don't use more than 30 characters.");
        ignore = false;
    }
    return in;
}


//type = 0 checks for basic commands, type = 1 checks for display organization commands
int Console::getIndex(char c, int type) {
    for(int i = type * 9; i < (type == 0 ? 9 : 14); i++) {
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
    return i - (type == 1 ? 9 : 0);
}

void Console::process(string fileName) {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    int currentYear = tPtr -> tm_year + 1900;
    println("The year is "+to_string(currentYear)+" and you're on Earth.");

    PersonManager pm = PersonManager(fileName, currentYear);
    printInstructions();
    while(true) {
        int i = getInstruction(0);
        if(i == 0) { // display
            newLine();
            printDisplayInstructions();
            int o = getInstruction(1);
            bool rev = getBool("Reverse output");
            printPersons(pm.getOrganizedPersons(o), rev, false);
        }
        if(i == 1) { // search
            printPersons(pm.getSearchResults(*this), false, false);
        }
        if(i == 2) { // add person
            pm.add(*this);
        }
        if(i == 3) { // info
            printInstructions();
        }
        if(i == 4) { // quit
            break;
        }
        if(i == 5) { // clear console
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }
        if(i == 6) { // edit person
            vector<Person> persons = pm.getOrganizedPersons(1); // organized in alphabetical order
            printPersons(persons, false, true); // alphabetical organization
            pm.edit(*this, persons);
        }
        if(i == 7) { // remove person
            vector<Person> persons = pm.getOrganizedPersons(1); // organized in alphabetical order
            printPersons(persons, false, true); // alphabetical organization
            pm.remove(*this, persons);
        }
        if(i == 8) { // snake
            Snake snake = Snake(*this);
            snake.processSnake(*this);
        }

    }
}

