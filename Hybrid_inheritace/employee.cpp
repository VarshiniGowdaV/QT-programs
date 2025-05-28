#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string name,int age)
    :Person(name,age)
{
    cout<<"Employee constructor called"<<endl;
}
Employee::~Employee()
{
    cout<<"Employee destructor called"<<endl;
}
