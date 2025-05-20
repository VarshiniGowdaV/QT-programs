#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    int m_value1;
    int m_value2;

public:
    Calculator(int value1,int value2);
    Calculator();
    ~Calculator();


    int add();
    int subtract();
    int multiply();
    double divide();
    int modulus();
};

#endif // CALCULATOR_H
