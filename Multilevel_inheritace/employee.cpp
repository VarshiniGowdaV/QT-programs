#include "employee.h"
#include <iostream>

Employee::Employee(std::string name, int employeeid) : Person(name)
{
    m_employeeid = employeeid;
    std::cout << "Employee constructor called" << std::endl;
}

Employee::~Employee()
{
    std::cout << "Employee destructor called" << std::endl;
}

int Employee::getid()const {
    return m_employeeid;
}

void Employee::setid(int id)
{
    m_employeeid = id;
}

void Employee::displayEmployee() const
{
    std::cout << "Employee ID: " << m_employeeid << std::endl;
    std::cout << "Name: " << getName() << std::endl;
}
