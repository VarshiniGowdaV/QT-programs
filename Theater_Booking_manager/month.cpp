#include "month.h"
#include <iostream>
#include <iomanip>
using namespace std;

Month::Month()
{
    cout << "Month default constructor called" << endl;
}

Month::~Month()
{
    cout << "Month destructor called" << endl;
}

Month::Month(int monthNumber, int year) : m_monthNumber(monthNumber), m_year(year)
{
    for (int i = 1; i <= 30; ++i)
        m_dates.emplace_back(i, monthNumber, year);
    cout << "Month parameterized constructor called" << endl;
}

std::vector<Date>& Month::getDates()
{
    return m_dates;
}
