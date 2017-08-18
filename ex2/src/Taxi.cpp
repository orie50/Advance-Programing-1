
#include "Taxi.h"

void Taxi::addKm(float km){}

void Taxi::setTariff(float tariff){}

float Taxi::getTariff(){
    return 0;
}

void Taxi::moveOneStep(Point next){}

void Taxi::updateLocation(Point location){}

Point Taxi::getLocation(){
    return Point(0,0);
}

float Taxi::getKm(){
    return 0;
}

bool Taxi::operator==(const Taxi &rhs) const {
    return id == rhs.id;
}

bool Taxi::operator!=(const Taxi &rhs) const {
    return !(rhs == *this);
}
