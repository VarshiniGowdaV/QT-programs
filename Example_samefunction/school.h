#ifndef SCHOOL_H
#define SCHOOL_H
#include "student.h"
#include <vector>
class School
{
private:
    std::vector<Student*> stduents;

public:
    School();
    ~School();

    void addStudent(Student* student);
    void printme();
};

#endif // SCHOOL_H
