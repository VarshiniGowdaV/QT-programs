#include "manager.h"
#include <iostream>

Manager::Manager(std::string name, int employeeid, std::string dept)
    : Employee(name, employeeid), department(dept) {
    std::cout << "Manager constructor called" << std::endl;
}

Manager::~Manager() {
    std::cout << "Manager destructor called" << std::endl;
}

void Manager::setdepartment(std::string dept) {
    department = dept;
}

std::string Manager::getdepartment() const {
    return department;
}

void Manager::displayManagerinfo() const {
    displayEmployee();
    std::cout << "Department: " << department << std::endl;
}
