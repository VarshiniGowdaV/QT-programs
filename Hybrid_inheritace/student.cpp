#include "student.h"
#include <iostream>
using namespace std;

Student::Student(string name,int age)
    :Person(name,age)
{
    cout<<"student constructor called"<<endl;
}

Student::~Student()
{
    cout<<"Student destructor called"<<endl;
}
