// #include "employee.h"

// int main() {
//     Employee employee("varshini",23,"software",15000);
//     employee.displayEmployee();

//     return 0;
// }
#include "employee.h"

int main() {
    Employee* employee = new Employee("Varshini", 23, "Software", 15000);
        employee->displayEmployee();
        delete employee;

    return 0;
}
