#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
class School;
class Student
{
private:
    std::string name;
    School* schoolptr;
    Student* studentptr;
    std::vector<Student*> childern;
public:
    Student(const std::string& name, School* school);
    Student(const std::string& name, Student* student);
    ~Student();

    std::string getname();
    void printme();
    void printchildren();
    void addchild(Student* student);
};

#endif // STUDENT_H
