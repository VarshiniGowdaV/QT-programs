#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
public:
    Calculator();
    ~Calculator();

    void add(int value1, int value2);
    void subtract(int value1, int value2);
    void multiply(int value1, int value2);
    void divide(int value1, int value2);
    void modulus(int value1, int value2);

};
#endif // CALCULATOR_H
