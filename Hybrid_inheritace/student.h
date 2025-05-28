#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : virtual public Person {
public:
    Student(string name,int age);
    ~Student();

};

#endif

