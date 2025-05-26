#include <iostream>
#include "manager.h"

int main() {
    Manager man("Varshini", 101, "HR");

    // man.setname("Varshi");
    // man.setid(102);
    // man.setdepartment("Finance");

    man.displayManagerinfo();

    return 0;
}
