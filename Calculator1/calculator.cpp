#include "calculator.h"
#include <iostream>

Calculator::Calculator()
{
    std::cout<<"calculator constructor called"<<std::endl;
}

Calculator::~Calculator()
{
    std::cout<<"calculator destructor called"<<std::endl;

}

void Calculator::add(int value1, int value2)
{
    std::cout<<"addition function called"<<std::endl;
    std::cout<<"Result = "<<value1+value2<<std::endl;
}

void Calculator::subtract(int value1, int value2)
{
    std::cout<<"subtraction function called"<<std::endl;
    std::cout<<"Result = "<<value1-value2<<std::endl;
}

void Calculator::multiply(int value1, int value2)
{
    std::cout<<"Multiply function called"<<std::endl;
    std::cout<<"Result = "<<value1*value2<<std::endl;
}

void Calculator::divide(int value1, int value2)
{
    std::cout<<"Divide function called"<<std::endl;
    std::cout<<"Result = "<<value1/value2<<std::endl;
}

void Calculator::modulus(int value1, int value2)
{
    std::cout<<"modulus function called"<<std::endl;
    std::cout<<"Result = "<<value1%value2<<std::endl;
}
