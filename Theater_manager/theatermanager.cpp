#include "theatermanager.h"
#include <iostream>

void TheaterManager::bookTheater(const std::string& date, const std::string& theaterId)
{
    bookedTheaters[date].push_back(theaterId);
}

bool TheaterManager::isAvailable(const std::string& date, const std::string& theaterId)
{
    auto it = bookedTheaters.find(date);
    if (it != bookedTheaters.end())
    {
        for (const auto& booked : it->second)
        {
            if (booked == theaterId)
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::string> TheaterManager::getBookedTheatres(const std::string& date) const
{
    auto it = bookedTheaters.find(date);
    if (it != bookedTheaters.end())
    {
        return it->second;
    }
    return {};
}
