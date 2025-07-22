#include "theatermanager.h"
#include <algorithm>

TheaterManager::TheaterManager() {}
TheaterManager::~TheaterManager() {}

bool TheaterManager::isAvailable(const std::string& date, const std::string& theatreId) const {
    auto it = bookings.find(date);
    if (it == bookings.end())
        return true;
    const auto& booked = it->second;
    return std::find(booked.begin(), booked.end(), theatreId) == booked.end();
}

void TheaterManager::bookTheater(const std::string& date, const std::string& theatreId) {
    bookings[date].push_back(theatreId);
}

std::vector<std::string> TheaterManager::getBookedTheatres(const std::string& date) const {
    auto it = bookings.find(date);
    if (it != bookings.end())
        return it->second;
    return {};
}
