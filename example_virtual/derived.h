#ifndef DERIVED_H
#define DERIVED_H
#include "base.h"
class Derived:public Base
{
public:
    Derived();
    ~Derived();
    virtual void fun();
};

#endif // DERIVED_H
