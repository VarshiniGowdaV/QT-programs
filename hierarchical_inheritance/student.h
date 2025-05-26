#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
class Student:public Person
{
private:
    std::string m_course;
public:
    Student(std::string name,int age,std::string course);
    ~Student();

    std::string getcourse();
    void setstudentdetails(std::string name,int age,std::string course);
    void showStudentdetails()const;
};

#endif // STUDENT_H
