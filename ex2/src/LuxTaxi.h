//
// Created by ori on 28/11/16.
//

#ifndef ASS2_LUXTAXI_H
#define ASS2_LUXTAXI_H

#include "Taxi.h"

class LuxTaxi: public Taxi {
public:
    LuxTaxi(int id, Type type, Color color, float tariff, Point location): Taxi(id,type,color,tariff,location){}
    void setTariff(float tariff);
    void moveOneStep(Point location);
};


#endif //ASS2_LUXTAXI_H
