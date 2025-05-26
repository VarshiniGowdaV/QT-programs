#include "person.h"
#include <iostream>
using namespace std;

void Person::setPersonDetails(string n, int a) {
    name = n;
    age = a;
}

void Person::displayPerson() {
    cout << "Name: " << name << "\nAge: " << age << endl;
}
