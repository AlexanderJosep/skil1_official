#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "personmanager.h"
#include "console.h"

using namespace std;

const string FILE_NAME = "persons.txt";

int main() {
    Console c = Console();
    c.process(FILE_NAME);
    return 1;
}
