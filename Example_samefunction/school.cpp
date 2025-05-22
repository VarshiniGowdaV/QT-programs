#include "school.h"
#include <iostream>
School::School()
{
    std::cout<<"School constructor called"<<std::endl;
}
School::~School()
{
    std::cout<<"school destructor called"<<std::endl;
}
void School::addStudent(Student* student)
{
    std::cout<<"school constructor called"<<std::endl;
    stduents.push_back(student);
}
void School::printme()
{

}
