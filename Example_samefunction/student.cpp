#include "student.h"
#include "school.h"
#include <iostream>
Student::Student(const std::string& name,School* school)
    :name(name),schoolptr(school),studentptr(nullptr)
{
    std::cout<<"Student constructor called with school parameter"<<std::endl;
    if(schoolptr)
    {
        schoolptr->addStudent(this);
    }
}
Student::Student(const std::string& name,Student* student)
    :name(name),schoolptr(nullptr),studentptr(student)
{
    std::cout<<"Stduent constructor with employee parameter"<<std::endl;
    if(studentptr)
    {
        studentptr->addchild(this);
    }
}
Student::~Student()
{
    std::cout<<"student destructor called"<<std::endl;
    std::cout<<"student destructor called"<<std::endl;

}
std::string Student::getname()
{
    return name;
}
void Student::addchild(Student* child)
{
    childern.push_back(child);
}
void Student::printme()
{
    std::cout<<"Student print called"<<std::endl;
    printchildren();
}
void Student::printchildren()
{
    for(auto child :childern)
    {
        child->printme();
        std::cout<<child->name<<std::endl;
    }
}
