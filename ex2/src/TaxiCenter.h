#ifndef ASS2_TAXICENTER_H
#define ASS2_TAXICENTER_H

#include "DriverInfo.h"
#include "Trip.h"

class TaxiCenter: public Sprite {
private:
    vector <DriverInfo> employees;
    Map* map;
    DriverInfo findClosestDriver();
    void answerCalls();
    void notifyNewTrip(Trip trip);
    Trip createNewTrip();
public:
    TaxiCenter(Map* map, vector <DriverInfo> employees);
    void start();
    void timePassed();
};


#endif //ASS2_TAXICENTER_H
