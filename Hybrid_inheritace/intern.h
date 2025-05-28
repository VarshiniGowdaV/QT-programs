#ifndef INTERN_H
#define INTERN_H

#include "student.h"
#include "employee.h"

class Intern : public Student, public Employee {

public:
    Intern(string name,int age);
    ~Intern();

};

#endif
