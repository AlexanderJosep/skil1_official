#include "personmanager.h"

PersonManager::PersonManager(string fileName) {
    ifstream in;
    in.open(fileName);
    string name;
    short gender;
    short birthYear;
    short deathYear;
    string nationality;
    while(in >> name && in >> gender && in >> birthYear && in >> deathYear) {
        replace(name.begin(), name.end(), '_', ' ' );
        persons.push_back(Person(name, gender, birthYear, deathYear));
    }
    in.close();
}

void PersonManager::add(Console c, string fileName, int currentYear) {
    string name = c.getString("Name", true);
    while(true) {
        if(validName(name)) {
           name = getFinalName(name);
           break;
        } else {
            c.println("Invalid name!");
            name = c.getString("Name", false);
        }
    }
    short gender;
    while(true) {
        char g = c.getChar("Gender (m/f)");
        if(g == 'm' || g == 'f') {
            gender = (g == 'm' ? 0 : 1);
            break;
        }
        c.println("Invalid gender!");
        c.clearBuffer();
    }
    short birthYear;
    while (true){
        birthYear = c.getShort("Birth year");
        if(birthYear > 0 && birthYear <= currentYear) {
            break;
        }
        c.println("Invalid birth year!");
        c.clearBuffer();
    }

        //short answer;
    short deathYear = -1;
    if(c.getBool("Person dead")) {
        while(true) {
            deathYear = c.getShort("Death year");
            if(deathYear >= birthYear && deathYear <= currentYear) {
                break;
            }
            c.println("Please choose a death year the same or after the birth year.");
        }
    }
    persons.push_back(Person(name, gender, birthYear, deathYear));
    save(fileName);
    c.println("You have added "+name+" to the list.");
    c.newLine();
}

void PersonManager::save(string fileName) {
    ofstream out;
    out.open(fileName);
    for(unsigned int i = 0; i < persons.size(); i++) {
        out << persons[i].getStoreOutput() << endl;
    }
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

string PersonManager::getFinalName(string name) {
    name = capitialize(name);

    return name;
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

vector<Person> PersonManager::getSearchResults(Console c) {
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
