#include "base.h"

Base::Base(std::string name,int age)
{
    m_name=name;
    m_age=age;
    std::cout<<"Base class constructor called"<<std::endl;
}
Base::~Base()
{
    std::cout<<"Base class destructor called"<<std::endl;
}
std::string Base ::getname()
{
    return m_name;
}
int Base::getage()
{
    return m_age;
}
void Base ::setBase(std::string name,int age)
{
    m_name=name;
    m_age=age;
}
void Base::display()
{
    std::cout<<"name: "<<m_name<<std::endl;
    std::cout<<"age: "<<m_age<<std::endl;
    std::cout<<"Base class display called"<<std::endl;
}
