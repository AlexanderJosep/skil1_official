#include "personmanager.h"

PersonManager::PersonManager(string fileName, int currentYear) {
    this -> storage = Storage(fileName);
    this -> persons = storage.getPersons();
    this -> currentYear = currentYear;
}

void PersonManager::add(Console &c) {
    string name = getName(c, true);
    short gender = getGender(c, true);
    short birthYear = getBirthYear(c, true);
    short deathYear = getDeathYear(c, true, birthYear);
    persons.push_back(Person(name, gender, birthYear, deathYear));
    storage.savePersons(persons);
    c.println("You have added "+name+" to the list.");
    c.newLine();
}

void PersonManager::edit(Console &c, vector<Person> pList) {
    short index;
    while (true){
        index = c.getShort("Select index from the list (1-"+to_string(persons.size())+")");
        if(index > 0 && index <= (signed) persons.size()) {
            break;
        }
        c.println("Invalid index!");
        c.clearBuffer();
    }

    for(unsigned int i = 0; i < persons.size(); i++) { // get the actual index ; the old one was from the alphabetical ordering
        if(persons[i].getName() == pList[index - 1].getName() && persons[i].getGender() == pList[index - 1].getGender()
                && persons[i].getBirthYear() == pList[index - 1].getBirthYear() && persons[i].getDeathYear() == pList[index - 1].getDeathYear()) {
            index = i;
            break;
        }
    }
    string oldName = persons[index].getName();
    c.println("Old name: "+oldName);
    string name = getName(c, false);
    string oldGender = (persons[index].getGender() == 0 ? "Male" : "Female");
    c.println("Old gender: "+oldGender);
    short gender = getGender(c, false);
    c.println("Old birth year: "+to_string(persons[index].getBirthYear()));
    short birthYear = getBirthYear(c, false);
    if(persons[index].getDeathYear() > 0) {
         c.println("Old death year: "+to_string(persons[index].getDeathYear()));
    } else {
         c.println("Old person did not have a death year");
    }
    short deathYear = getDeathYear(c, false, birthYear);
    persons[index].setData(name, gender, birthYear, deathYear);
    storage.savePersons(persons);
    c.println("You have edited "+name+" (old name: "+oldName+").");
}

string PersonManager::getName(Console &c, bool n) {
    string s = n ? "Name" : "New name";
    string name = c.getString(s, true);
    while(true) {
        if(validName(name)) {
           name = capitialize(name);
           break;
        } else {
            c.println("Invalid name!");
            name = c.getString(s, false);
        }
    }
    return name;
}

short PersonManager::getGender(Console &c, bool n) {
    string s = n ? "Gender" : "New gender";
    short gender;
    while(true) {
        char g = c.getChar(s + " (m/f)");
        if(g == 'm' || g == 'f') {
            gender = (g == 'm' ? 0 : 1);
            break;
        }
        c.println("Invalid gender!");
        c.clearBuffer();
    }
    return gender;
}

short PersonManager::getBirthYear(Console &c, bool n) {
    string s = n ? "Birth year" : "New birth year";
    short birthYear;
    while (true){
        birthYear = c.getShort(s);
        if(birthYear > 0 && birthYear <= currentYear) {
            break;
        }
        c.println("Invalid birth year!");
        c.clearBuffer();
    }
    return birthYear;
}

short PersonManager::getDeathYear(Console &c, bool n, int birthYear) {

    short deathYear = -1;
    if(c.getBool("Person dead")) {
        while(true) {
            string s = n ? "Death year" : "New death year";
            deathYear = c.getShort(s);
            if(deathYear >= birthYear && deathYear <= currentYear) {
                break;
            }
            c.println("Please choose a death year the same or after the birth year.");
            c.clearBuffer();
        }
    }
    return deathYear;
}

vector<Person> PersonManager::getOrganizedPersons(int o) {
    if(o == 0) { // no organizing
        return persons;
    }
    vector<Person> out;
    if(o == 1) { // organize by names alphabetically
        vector<string> names;
        for(unsigned int i = 0; i < persons.size(); i++) {
            names.push_back(persons[i].getName());
        }
        sort(names.begin(), names.end());
        for(unsigned int i = 0; i < names.size(); i++) {
            for(unsigned int j = 0; j < persons.size(); j++) {
                if(names[i] == persons[j].getName()) {
                    out.push_back(persons[j]);
                    break;
                }
            }
        }
        return out;
    }
    if(o == 2) { // organize by gender
        for(int j = 0; j < 2; j++) {
            for(unsigned int i = 0; i < persons.size(); i++) {
                if(persons[i].getGender() == j) {
                    out.push_back(persons[i]);
                }
            }
        }
        return out;
    }
    if(o == 3 || o == 4) { // organize by birth year or by death year
        vector<int> years;
        vector<Person> copy;
        for(unsigned int i = 0; i < persons.size(); i++) {
            if((o == 3 && persons[i].getBirthYear() >= 0) || (o == 4 && persons[i].getDeathYear() >= 0)) {
                years.push_back(o == 3 ? persons[i].getBirthYear() : persons[i].getDeathYear());
            }
        }
        sort(years.begin(), years.end());
        for(unsigned int i = 0; i < persons.size(); i++) {
            copy.push_back(persons[i]);
        }
        for(unsigned int i = 0; i < years.size(); i++) {
            for(unsigned int j = 0; j < copy.size(); j++) {
                if((o == 3 && years[i] == copy[j].getBirthYear()) || (o == 4 && years[i] == copy[j].getDeathYear())) {
                    out.push_back(copy[j]);
                    copy.erase(copy.begin() + j);
                    break;
                }
            }
        }
        return out;

    }
    return out;
}

bool PersonManager::validName(string name) {
    if(name.find("  ") != string::npos) {
        return false;
    }
    for(unsigned int i = 0; i < name.length(); i++) {
        if(!isalpha(name[i]) && name[i] != 32) {
            return false;
        }
    }
    return true;
}

string PersonManager::trim(string s) {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string PersonManager::capitialize(string s) {
    s = toLowerCase(s);
    const char* c = s.c_str();
    bool capitalizeNext = true;
    char out[s.length() - 1];
    for(unsigned int i = 0; i <= s.length(); i++) {
        out[i] = *(c + i);
        if(capitalizeNext && out[i] != ' ') {
            capitalizeNext = false;
            out[i] -= 32;
        }
        if(out[i] == ' ') {
            capitalizeNext = true;
        }
    }
    delete c;
    return string(out);
}

string PersonManager::toLowerCase(string s) {
    string out;
    out.resize(s.size());
    transform(s.begin(), s.end(), out.begin(), ::tolower);
    return out;
}

vector<Person> PersonManager::getSearchResults(Console &c) {
    string search = toLowerCase(c.getString("Search", true));
    vector<Person> out;
    string male = "male";
    string female = "female";
   // search.
    for(Person p : persons) {
        if(toLowerCase(p.getName()).find(search) != string::npos || to_string(p.getBirthYear()).find(search) != string::npos
                || (p.getGender() == 0 && male.find(search) != string::npos) || (search != male && p.getGender() == 1 && female.find(search) != string::npos)
                || (p.getDeathYear() >= 0 && to_string(p.getDeathYear()).find(search) != string::npos)) {
           out.push_back(p);
        }
    }
    return out;
}
