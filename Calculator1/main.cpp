#include "calculator.h"
#include <iostream>
using namespace std;

int main()
{
    Calculator calc;
    calc.add(20 , 10);
    calc.subtract(40 , 10);
    calc.multiply(60 , 10);
    calc.divide(20 , 10);
    calc.modulus(10 , 20);
    return 0;
}
