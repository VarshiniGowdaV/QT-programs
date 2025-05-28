// #include <iostream>
// #include "base.h"
// #include "derived.h"
// using namespace std;

// int main()
// {
//     Derived d("varshi",22);
//     d.displayDerived();
//     return 0;
// }
#include <iostream>
#include "base.h"
#include "derived.h"

using namespace std;

int main()
{
    Base* ptr = new Derived("varshi", 22);
    ptr->display();
    delete ptr;
    return 0;
}
