#include "intern.h"
#include <iostream>
using namespace std;

Intern::Intern() {}

Intern::~Intern() {}

void Intern::setInternDetails(string dept) {
    department = dept;
}

void Intern::displayIntern() {
    cout << "Intern Details:" << endl;
    Student::displayStudent();
    cout << "Department: " << department << endl;
}
