#include "person.h"

Person::Person(std::string name,int age)
{
        m_name=name;
        m_age=age;
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
void Person::persondetails(std::string name,int age)
{
    m_name=name;
    m_age=age;
}
void Person::displayperson()
{
    std::cout<<"Name: "<<m_name<<"\n age: "<<m_age<<std::endl;
}
