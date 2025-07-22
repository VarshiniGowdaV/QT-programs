#include "calender.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

Calendar::Calendar()
{
    std::cout << "Calendar constructor called" << std::endl;
}

Calendar::~Calendar()
{
    std::cout << "Calendar destructor called" << std::endl;
}

Calendar::Calendar(TheaterManager* mgr)
{
    Date today = Date::today();
    currentMonth = today.toString()[3] == '0' ? today.toString()[4] - '0' : std::stoi(today.toString().substr(3, 2));
    currentYear = std::stoi(today.toString().substr(6));
    manager = mgr;
}

void Calendar::nextMonth()
{
    if (++currentMonth > 12)
    {
        currentMonth = 1;
        ++currentYear;
    }
}

void Calendar::prevMonth()
{
    if (--currentMonth < 1)
    {
        currentMonth = 12;
        --currentYear;
    }
}

void Calendar::showCalendar() const
{
    std::string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December" };

    std::cout << "\n" << monthNames[currentMonth] << " " << currentYear << "\n";
    std::cout << "  Sun     Mon   Tue   Wed   Thu   Fri   Sat\n";

    std::tm t = {};
    t.tm_mday = 1;
    t.tm_mon = currentMonth - 1;
    t.tm_year = currentYear - 1900;
    std::mktime(&t);
    int startDay = t.tm_wday;

    int days = Date::daysInMonth(currentMonth, currentYear);
    int printed = 0;

    for (int i = 0; i < startDay; ++i)
    {
        std::cout <<"      ";
        ++printed;
    }

    for (int d = 1; d <= days; ++d)
    {
        Date curr(d, currentMonth, currentYear);
        std::string dateStr = curr.toString();
        std::vector<std::string> booked = manager->getBookedTheatres(dateStr);
        int bookedCount = booked.size();

        if (bookedCount > 0)
        {
            std::ostringstream oss;
            oss << std::setw(2) << d << "/" << bookedCount;
            std::cout << std::setw(6) << oss.str();
        }
        else
        {
            std::ostringstream oss;
            oss << std::setw(2) << d;
            std::cout << std::setw(6) << oss.str();
        }

        ++printed;
        if (printed % 7 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}
