#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string name, int employeeid, std::string department);
    ~Manager();

    void setdepartment(std::string department);
    std::string getdepartment() const;
    void displayManagerinfo() const;
};

#endif // MANAGER_H
