#ifndef THEATERMANAGER_H
#define THEATERMANAGER_H

#include <map>
#include <vector>
#include <string>

class TheaterManager
{
private:
    std::map<std::string, std::vector<std::string>> bookings;

public:
    TheaterManager();
    ~TheaterManager();

    bool isAvailable(const std::string& date, const std::string& theatreId) const;
    void bookTheater(const std::string& date, const std::string& theatreId);
    std::vector<std::string> getBookedTheatres(const std::string& date) const;
};

#endif // THEATERMANAGER_H
