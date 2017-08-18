#ifndef ASS2_TRIP_H
#define ASS2_TRIP_H

#include "Passenger.h"

class Trip {
private:
    int id;
    int totalMeterPassed;
    Point start;
    Point end;
    int numOfPass;
    vector <Point> route;
    float price;
    vector <Passenger> passengers;
    void addMeter();
public:
    Trip(int id, Point start, Point end, int numOfPass, vector<Point *> route,
         vector<Passenger> passengers, float price) : start(0, 0), end(0, 0){};
    Point getNextPoint();
    void setPrice(float price);
    float getPrice();
};

#endif //ASS2_TRIP_H
