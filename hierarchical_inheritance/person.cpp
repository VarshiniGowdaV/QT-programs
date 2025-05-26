#include "person.h"

Person::Person(std::string name,int age)
{
    m_name=name;
    m_age=age;
    std::cout<<"Person constructor called"<<std::endl;
}
Person::~Person()
{
    std::cout<<"Person destructor called"<<std::endl;
}
std::string Person::getname()
{
    return m_name;
}
int Person::getage()
{
    return m_age;
}
void Person::setpersondetails(const std::string name,int age)
{
    m_name=name;
    m_age=age;
}
void Person::showpersondetails()const
{
    std::cout<<"Name: "<<m_name<<"\nAge: "<<m_age<<std::endl;
}

