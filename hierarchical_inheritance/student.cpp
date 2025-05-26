#include "student.h"

Student::Student(std::string name,int age,std::string course)
    :Person(name,age)
{
    m_course = course;
}
Student::~Student()
{
    std::cout<<"Student destructor called"<<std::endl;
}
std::string Student::getcourse()
{
    return m_course;
}
void Student::setstudentdetails(std::string name,int age,std::string course)
{
    setpersondetails(name,age);
}
void Student::showStudentdetails()const
{
    showpersondetails();
    std::cout<<"course: "<<m_course<<std::endl;
}
