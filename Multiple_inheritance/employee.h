#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "person.h"
#include "job.h"

class Employee : public Person, public Job
{
public:
    Employee(std::string name, int age, std::string designation, double salary);
    ~Employee();
    void setEmployeeDetails(const std::string name, int age,const std::string designation, double salary);
    void displayEmployee() const;
};

#endif

