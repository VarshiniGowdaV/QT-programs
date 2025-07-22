#ifndef MONTH_H
#define MONTH_H
#include "date.h"
#include <vector>

class Month
{
private:
    int m_monthNumber;
    int m_year;
    std::vector<Date> m_dates;
public:
    Month();
    ~Month();
    Month(int monthNumber, int year);
    std::vector<Date> &getDates();
};

#endif
