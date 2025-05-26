#include <iostream>
#include "base.h"
#include "derived.h"
using namespace std;

int main()
{
    Base *ptr =new Derived;
    ptr->fun();
    return 0;
}
