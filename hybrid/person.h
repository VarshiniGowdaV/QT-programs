#ifndef PERSON_H
#define PERSON_H
#include <iostream>
class Person
{
private:
    std::string m_name;
    int m_age;
public:
    Person( std::string name,int age);
    ~Person();
    std::string getname();
    int getage();
    void persondetails(std::string name,int age);
    void displayperson();

};

#endif // PERSON_H
