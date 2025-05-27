#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person();
    ~Person();
    void setPersonDetails(string n, int a);
    void displayPerson();
};

#endif
