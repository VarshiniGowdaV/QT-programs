#include <iostream>
#include "derived.h"

Derived::Derived(std::string name, int age)
    : Base(name, age)
{
    std::cout << "Derived constructor called" << std::endl;
}
Derived::~Derived()
{
    std::cout << "Derived destructor called" << std::endl;
}

void Derived::displayDerived()
{
    display();
    std::cout << "Calling display from Derived class:" << std::endl;
}
