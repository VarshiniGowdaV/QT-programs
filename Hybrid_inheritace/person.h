#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string m_name;
    int m_age;

public:
    Person(string name,int age);
    ~Person();
    string getname();
    int getage();
    void setPersonDetails(string name, int age);
    void display();
};

#endif
