#include "button.h"
#include "class.h"
#include<iostream>
using namespace std;

int main()
{
    int* ptr= new int;
    Class<int> m1(ptr);
    cout<<*ptr<<endl;
    Class<double> m2(new double);

    Class<Button> btnPtr(new Button(10));
    //btnPtr.getPtr()->print();
    btnPtr->print();
    return 0;
}
