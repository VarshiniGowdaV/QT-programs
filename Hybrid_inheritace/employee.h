#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : virtual public Person {
private:
    int empID;

public:
    Employee();
    ~Employee();
    void setEmployeeID(int id);
    void displayEmployee();
};

#endif
