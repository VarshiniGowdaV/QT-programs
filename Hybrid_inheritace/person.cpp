#include "person.h"
#include <iostream>
using namespace std;

Person::Person(string name,int age)
{
    m_name=name;
    m_age=age;
    cout<<"Person constructor called"<<endl;
}

Person::~Person()
{
    cout<<"Person destructor called"<<endl;
}
string Person::getname()
{
    return m_name;
}
int Person::getage()
{
    return m_age;
}
void Person::setPersonDetails(string name,int age)
{
    m_name=name;
    m_age=age;
}
void Person::display()
{
    cout<<"Name: "<<m_name<<" Age: "<<m_age<<endl;
}
