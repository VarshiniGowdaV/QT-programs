#include "intern.h"
#include <iostream>

using namespace std;

Intern::Intern(string name, int age)
    :Person(name,age),Student(name, age), Employee(name, age)
{
    cout<<"Intern constructor called"<<endl;
}
Intern::~Intern()
{
    cout<<"Intern destructor called"<<endl;
}
