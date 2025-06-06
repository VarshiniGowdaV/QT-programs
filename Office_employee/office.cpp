#include "office.h"
#include <iostream>

Office::Office() : Baseobjectclass("Office")
{
    std::cout<<"Office constructor called"<<std::endl;
}
Office::~Office()
{
    std::cout<<"Office destructor called"<<std::endl;
}
void Office::getme() const
{
    std::cout << "This is the Office." << std::endl;
}

Baseobjectclass* Office::findChild(const std::string& childName)
{
    std::cout << "Searching in Office: " << name << std::endl;

    if (name == childName)
    {
        std::cout << "Matched Office: " << name << std::endl;
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
