#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string m_name;
public:
    Person(std::string name);
    ~Person();

    void setname(std::string name);
    std::string getName() const;
};

#endif // PERSON_H
