#include "theater.h"
#include <algorithm>
#include <iostream>
using namespace std;

Theatre::Theatre(int id) : m_id(id)
{
    cout << "Theatre parameterized constructor called for ID " << id << endl;
}

Theatre::~Theatre()
{
    cout << "Theatre destructor called for ID " << m_id << endl;
}

int Theatre::getId() const
{
    return m_id;
}

void Theatre::bookDay(int day)
{
    if (!isBooked(day)) bookedDays.push_back(day);
}

bool Theatre::isBooked(int day) const
{
    return std::find(bookedDays.begin(), bookedDays.end(), day) != bookedDays.end();
}

std::ostream& operator<<(std::ostream& os, const Theatre& t)
{
    os << "Theater ID: " << t.m_id << "\nBooked Days: ";
    if (t.bookedDays.empty()) os << "None";
    else for (int d : t.bookedDays) os << d << " ";
    return os;
}
