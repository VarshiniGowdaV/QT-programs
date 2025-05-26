#include "employee.h"
#include <iostream>

Employee::Employee(std::string name, int age, std::string designation, double salary)
    : Person(name, age), Job(designation, salary) {
}

Employee::~Employee()
{
    std::cout << "Employee destructor called" << std::endl;
}

void Employee::setEmployeeDetails(const std::string name, int age,
                                  const std::string designation, double salary) {
    setPersonDetails(name, age);
    setJobDetails(designation, salary);
}

void Employee::displayEmployee() const {
    showPersonDetails();
    showJobDetails();
}
