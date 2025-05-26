#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string m_name;
    int m_age;

public:
    Person(std::string name,int age);
    ~Person();

    std::string getname();
    int getage();

    void setPersonDetails(const std::string name, int age);
    void showPersonDetails() const;
};

#endif
