#include "office.h"
#include "employee.h"
#include <iostream>
using namespace std;

int main()
{
    Office* off1 = new Office();
    Employee* e1 = new Employee("darshini", off1);
    Employee* e2 = new Employee("likitha", off1);
    Employee* e3 = new Employee("pallavi", e1);
    Employee* e4 = new Employee("varshini", e1);
    Employee* e5 = new Employee("vidya", e3);

    cout << "Printing all objects:\n";
    Baseobjectclass::print();

    cout << "\nFinding child in Employee list:\n";
    Baseobjectclass* found = e1->findChild("darshini");
    if (found)
    {
        cout << "Found: " << found->GetName() << endl;
    }
    else
    {
        cout << "Not Found\n";
    }
    cout << "\nFinding child in Office list:\n";
    found = off1->findChild("vidya");
    if (found)
    {
        cout << "Found: " << found->GetName() << endl;
    }
    else
    {
        cout << "Not Found\n";
    }
    cout << "\nCalling getme function:\n";
    Baseobjectclass* ptr = e2;
    ptr->getme();

    Baseobjectclass* ptr1 = e4;
    ptr1->getme();

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete off1;

    return 0;
}
