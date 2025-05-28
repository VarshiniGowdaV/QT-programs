// #include <iostream>
// #include "manager.h"

// int main() {
//     Manager man("Varshini", 101, "HR");
//     man.displayManagerinfo();

//     return 0;
// }
#include <iostream>
#include "manager.h"

int main()
{
    Manager* man = new Manager("Varshini", 101, "HR");
        man->displayManagerinfo();
        delete man;

    return 0;
}
