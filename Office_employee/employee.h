#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "baseobjectclass.h"

class Employee : public Baseobjectclass {
public:
    Employee(std::string name, Baseobjectclass* parent);
    ~Employee();
    void getme() const override;
    Baseobjectclass* findChild(const std::string& childName) override;
};

#endif
