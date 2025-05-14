#ifndef THEATRE_H
#define THEATRE_H
#include <vector>
#include <iostream>

class Theatre
{
private:
    int m_id;
    std::vector<int> bookedDays;
public:
    ~Theatre();
    Theatre(int id = -1);
    int getId() const;
    void bookDay(int day);
    bool isBooked(int day) const;
    friend std::ostream& operator<<(std::ostream& os, const Theatre& t);
};

#endif
