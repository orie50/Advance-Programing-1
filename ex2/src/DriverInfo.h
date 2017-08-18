#ifndef ASS2_DRIVERINFO_H
#define ASS2_DRIVERINFO_H

#include "Driver.h"
#include "Map.h"

class DriverInfo {
private:
    Driver driver;
    Taxi cab;
    Point location;
    Trip trip;
    void setLocation(Point location);
public:
    DriverInfo(Driver driver, Taxi taxi, Point location, Trip trip):
            driver(driver), cab(taxi), location(location),
            trip(trip) {}
    Point getLocation();
};

#endif //ASS2_DRIVERINFO_H
