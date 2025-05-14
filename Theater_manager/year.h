#ifndef YEAR_H
#define YEAR_H
#include "month.h"

class Year {
private:
    int m_year;
    Month april;

public:
    Year(int year = 2025);
    ~Year();
    Month& getApril();
};

#endif
