#include "office.h"
#include <iostream>
Office::Office()
{
    std::cout<<"Office constructor called"<<std::endl;
}
Office::~Office()
{
    std::cout<<"office destructor called"<<std::endl;
}
void Office::printoffice()
{
    emp.printemployee();
    std::cout<<"office function called"<<std::endl;
}
