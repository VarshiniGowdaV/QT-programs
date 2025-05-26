#ifndef INTERN_H
#define INTERN_H

#include "student.h"
#include "employee.h"

class Intern : public Student, public Employee {
private:
    string department;

public:
    void setInternDetails(string dept);
    void displayIntern();
};

#endif
