#include <string>
#include <windows.h>

#include "console.h"

using namespace std;

const string FILE_NAME = "persons.txt";

int main() {
    Console c = Console();
    c.process(FILE_NAME);
    return 1;
}
