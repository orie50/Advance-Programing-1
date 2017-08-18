//
// Created by ori on 28/11/16.
//

#ifndef ASS2_PASSENGER_H
#define ASS2_PASSENGER_H

#include "Map.h"

class Passenger {
private:
    Point src;
    Point dest;
public:
    Passenger(Point src, Point dest): src(src), dest(dest){};
    int satisfacation();
};


#endif //ASS2_PASSENGER_H
