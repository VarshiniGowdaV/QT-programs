#include "employee.h"
#include <iostream>
using namespace std;

void Employee::setEmployeeID(int id) {
    empID = id;
}

void Employee::displayEmployee() {
    displayPerson();
    cout << "Employee ID: " << empID << endl;
}
