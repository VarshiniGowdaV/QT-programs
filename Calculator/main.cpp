#include <iostream>
#include "calculator.h"
using namespace std;

int main()
{
    int a, b;
    char operator1;

    cout << "Enter first value: ";
    cin >> a;

    cout << "Enter operator (+, -, *, /, %): ";
    cin >> operator1;

    cout << "Enter second value: ";
    cin >> b;

    Calculator cal(a, b);

    switch (operator1)
    {
    case '+':
        cout << "Result: " << cal.add() << endl;
        break;
    case '-':
        cout << "Result: " << cal.subtract() << endl;
        break;
    case '*':
        cout << "Result: " << cal.multiply() << endl;
        break;
    case '/':
        cout << "Result: " << cal.divide() << endl;
        break;
    case '%':
        cout << "Result: " << cal.modulus() << endl;
        break;
    default:
        cout << "Invalid operator!" << endl;
    }

    return 0;
}
