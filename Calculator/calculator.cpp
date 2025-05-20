#include "calculator.h"
#include <iostream>
using namespace std;
Calculator::Calculator(int value1,int value2)
{
    m_value1=value1;
    m_value2=value2;
    cout<<"Calculator parameter constructor called"<<endl;
}
Calculator::Calculator()
{
    cout<<"Calculator default constructor called"<<endl;
}
Calculator::~Calculator()
{
    cout<<"Calculator destructor called "<<endl;
}
int Calculator::add()
{
    return m_value1 + m_value1;
}
int Calculator::subtract()
{
    return m_value1 - m_value2;
}
int Calculator::multiply()
{
    return m_value1 * m_value2;
}
double Calculator::divide()
{
    if(m_value2 == 0)
    {
        cout<<"Error: Division by zero"<<endl;
        return 0;
    }
    return(double)m_value1 / m_value2;
}
int Calculator::modulus()
{
    if(m_value2 == 0)
    {
        cout<<"Error:Modulus by zero"<<endl;
        return -1;
    }
    return m_value1 % m_value2;
}
