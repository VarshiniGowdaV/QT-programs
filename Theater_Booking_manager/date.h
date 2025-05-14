#ifndef DATE_H
#define DATE_H
#include <string>

class Date
{
private:
    int day, month, year;
public:
    Date();
    Date(int d, int m, int y);
    bool isValid() const;
    bool isPast() const;
    std::string toString() const;
    static bool isLeap(int year);
    static int daysInMonth(int month, int year);
    static Date today();
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
};

#endif
