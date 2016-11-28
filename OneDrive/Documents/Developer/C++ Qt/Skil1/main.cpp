#include <iostream>
#include "personmanager.h"

using namespace std;

const string FILE_NAME = "persons.txt";

int main()
{
    PersonManager pm = PersonManager(FILE_NAME);
    pm.displayPersons();
    return 1;
}
