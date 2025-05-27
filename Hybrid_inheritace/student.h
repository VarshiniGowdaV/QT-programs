#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : virtual public Person {
private:
    int studentID;

public:
    Student();
    ~Student();
    void setStudentID(int id);
    void displayStudent();
};

#endif

