#include "person.h"
#include <iostream>

Person::Person(std::string name,int age)
{
    m_name=name;
    m_age=age;
    std::cout<<"Person constructor called"<<std::endl;
}
Person::~Person()
{
    std::cout<<"person destructor called"<<std::endl;
}
std::string Person::getname()
{
    return m_name;
}
int Person::getage()
{
    return m_age;
}
void Person::setPersonDetails(const std::string name, int age) {
    m_name = name;
    m_age = age;
}

void Person::showPersonDetails() const {
    std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
}
