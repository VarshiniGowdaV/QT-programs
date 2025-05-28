#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee :virtual public Person {
public:
    Employee(string name,int age);
    ~Employee();

};

#endif
