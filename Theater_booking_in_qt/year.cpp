#include "year.h"
#include <iostream>
using namespace std;

Year::Year(int year) : m_year(year), april(4, year)
{
    cout << "Year parameterized constructor called\n";
}

Year::~Year()
{
    cout << "Year destructor called\n";
}

Month& Year::getApril()
{
    return april;
}
