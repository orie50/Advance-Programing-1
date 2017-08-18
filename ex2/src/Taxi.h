#ifndef ASS2_TAXI_H
#define ASS2_TAXI_H

#include "Map.h"

enum Type {HONDA, SUBARO, TESLA, FIAT};
enum Color {RED, BLUE, GREEN, PINK, WHITE};

class Taxi{
private:
    int id;
    float totalKm;
    Type manufacturer;
    Color color;
    float tariff;
    Point location;
    int velocity;
    void addKm(float km);
public:
    Taxi(int id, Type type, Color color, float tariff, Point location):
            id(id), manufacturer(type), color(color), tariff(tariff), location(location){};
    virtual void setTariff(float tariff);
    float getKm();
    float getTariff();
    virtual void moveOneStep(Point next);
    void updateLocation(Point location);
    Point getLocation();
    bool operator==(const Taxi &rhs) const;
    bool operator!=(const Taxi &rhs) const;
};


#endif //ASS2_TAXI_H
