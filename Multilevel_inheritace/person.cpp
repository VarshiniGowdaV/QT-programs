#include "person.h"

Person::Person(std::string name)
{
    m_name=name;
    std::cout<<"person constructor called"<<std::endl;
}
Person::~Person()
{
    std::cout<<"person destructor called"<<std::endl;
}
std::string Person::getName()const
{
    return m_name;
}
void Person::setname(std::string name)
{
    m_name=name;
}
