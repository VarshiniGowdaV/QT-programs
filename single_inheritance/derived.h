#ifndef DERIVED_H
#define DERIVED_H
#include "base.h"
class Derived:public Base
{
public:
    Derived(std::string name,int age);
    ~Derived();

    void displayDerived();
};

#endif // DERIVED_H
