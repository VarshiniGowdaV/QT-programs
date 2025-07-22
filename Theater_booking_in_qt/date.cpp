#include "date.h"
#include <ctime>
#include <sstream>
#include <iostream>
using namespace std;

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y)
{
    static int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && isLeap(y)) return 29;
    return days[m - 1];
}

bool Date::isValid() const
{
    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
        return false;
    return true;
}

Date Date::today()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

bool Date::isPast() const
{
    return *this < today();
}

std::string Date::toString() const
{
    std::ostringstream oss;
    if (day < 10) oss << '0';
    oss << day << '-';
    if (month < 10) oss << '0';
    oss << month << '-' << year;
    return oss.str();
}

bool Date::operator<(const Date& other) const
{
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator==(const Date& other) const
{
    return day == other.day && month == other.month && year == other.year;
}
