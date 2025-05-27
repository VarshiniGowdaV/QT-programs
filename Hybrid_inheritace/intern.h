#ifndef INTERN_H
#define INTERN_H

#include "student.h"
#include "employee.h"

class Intern : public Student, public Employee {
private:
    string department;

public:
    Intern();
    ~Intern();
    void setInternDetails(string dept);
    void displayIntern();
};

#endif
