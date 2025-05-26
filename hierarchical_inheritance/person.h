#ifndef PERSON_H
#define PERSON_H
#include "iostream"
class Person
{
private:
    std::string m_name;
    int m_age;
public:
    Person(std::string name,int age);
    ~Person();

    std::string getname();
    int getage();
    void setpersondetails(const std::string name,int age);
    void showpersondetails()const;
};

#endif // PERSON_H
