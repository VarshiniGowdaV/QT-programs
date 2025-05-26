#include "student.h"
#include <iostream>
using namespace std;

void Student::setStudentID(int id) {
    studentID = id;
}

void Student::displayStudent() {
    displayPerson();
    cout << "Student ID: " << studentID << endl;
}
