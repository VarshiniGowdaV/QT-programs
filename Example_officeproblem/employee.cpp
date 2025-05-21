#include "employee.h"
#include <iostream>
Employee::Employee()
{
    std::cout<<"Employee constructor called"<<std::endl;
}
Employee::~Employee()
{
    std::cout<<"Employee destructor called"<<std::endl;
}
void Employee::printemployee()
{
    std::cout<<"Employee function called"<<std::endl;
}
