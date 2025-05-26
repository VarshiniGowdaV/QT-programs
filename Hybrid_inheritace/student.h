#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
private:
    int studentID;

public:
    void setStudentID(int id);
    void displayStudent();
};

#endif
