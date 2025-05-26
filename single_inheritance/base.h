#ifndef BASE_H
#define BASE_H
#include <iostream>
class Base
{
private:
   std::string m_name;
    int m_age;
public:
    Base(std::string name,int age);
    ~Base();
    std::string getname();
    int getage();
    void setBase(std::string name,int age);
    void display();
};

#endif // BASE_H
