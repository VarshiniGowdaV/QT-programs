#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person {
private:
    int m_employeeid;
public:
    Employee(std::string name, int employeeid);
     ~Employee();

    void setid(int id);
    int getid() const;
    void displayEmployee() const;
};

#endif // EMPLOYEE_H
