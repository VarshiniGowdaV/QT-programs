#ifndef CALENDAR_H
#define CALENDAR_H
#include "date.h"
#include "theatermanager.h"
#include <string>

class Calendar
{
private:
    int currentMonth;
    int currentYear;
    TheaterManager* manager;
public:
    Calendar(TheaterManager* mgr);
    Calendar();
    ~Calendar();
    void showCalendar() const;
    void nextMonth();
    void prevMonth();
};

#endif
