#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person {
private:
    int empID;

public:
    void setEmployeeID(int id);
    void displayEmployee();
};

#endif
