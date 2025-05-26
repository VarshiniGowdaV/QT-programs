#include <iostream>
#include "base.h"
#include "derived.h"
using namespace std;

int main()
{
    Derived d("varshi",22);
    d.displayDerived();
    return 0;
}
