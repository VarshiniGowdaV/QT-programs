#include "employee.h"
#include <iostream>

Employee::Employee(std::string name, Baseobjectclass* parent)
    : Baseobjectclass(name)
{
    if (parent) parent->addChild(this);
}
Employee::~Employee()
{
        std::cout<<"Employee destructor called"<<std::endl;
}

void Employee::getme() const
{
    std::cout << "Employee Name: " << name << std::endl;
}

Baseobjectclass* Employee::findChild(const std::string& childName)
{
    std::cout << "Searching in Employee: " << name << std::endl;

    if (name == childName)
    {
        std::cout << "Matched Employee: " << name << std::endl;
        return this;
    }

    for (auto child : children)
    {
        Baseobjectclass* found = child->findChild(childName);
        if (found)
        {
            return found;
        }
    }

    return nullptr;
}
