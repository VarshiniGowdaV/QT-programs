#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

class Teacher:public Person
{
private:
    std::string m_subject;
public:
    Teacher(const std::string name, int age, const std::string subject);
    ~Teacher();

    std::string getsubject();
    void setsubject(const std::string subject);
    void showteacherdetails()const;
};

#endif // TEACHER_H
