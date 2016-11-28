#include "console.h"

const char commands[4] = {'d', 's', 'i', 'q'};
const string instructions[3] = {"Use 'd' to display persons and 's' to search.", "Use 'i' to display instructions",
                                "Use 'q' if you want to quit."};

Console::Console()
{

}

void Console::printInstructions() {
    for(int i = 0; i < 3; i++) {
         cout << instructions[i] << endl;
    }
}

char Console::getChar(string s) {
    cout << s << ": ";
    char c;
    cin >> c;
    return c;
}

bool Console::isValid(char c) {
    for(int i = 0; i < 4; i++) {
        if(c == commands[i]) {
            return true;
        }
    }
    return false;
}

//0 = display, 1 = search, c = write out possible instructions, 3 = quit
int Console::getInstruction() {
    char c;
    while(true) {
        c = getChar("Instruction");
        if(!isValid(c)) {
            cout << "Invalid command!" << endl;
            continue;
        } else {
            break;
        }
    }
    for(int i = 0; i < 4; i++) {
        if(c == commands[i]) {
            return i;
        }
    }
    return -1;
}
