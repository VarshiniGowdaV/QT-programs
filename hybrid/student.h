#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
class Student:public Person
{
private:
    int studentId;
public:
    Student();
    ~Student();

};

#endif // STUDENT_H
