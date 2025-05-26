#include "teacher.h"
#include <iostream>


Teacher::Teacher(const std::string name, int age, const std::string subject)
    : Person(name, age), m_subject(subject)
{
}

Teacher::~Teacher()
{
    std::cout << "Teacher destructor called" << std::endl;
}
std::string Teacher::getsubject()
{
    return m_subject;
}
void Teacher::setsubject(const std::string subject)
{
    m_subject = subject;
}
void Teacher::showteacherdetails() const
{
    showpersondetails();
    std::cout << "Subject: " << m_subject << std::endl;
}
