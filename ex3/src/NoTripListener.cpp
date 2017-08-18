//
// Created by adi on 15/12/16.
//

#include "NoTripListener.h"

void NoTripListener::avaliableEvent(AvaliableNotifier *avaliable) {
    this->avaliableDrivers->push_back((Driver*) avaliable);
}

void NoTripListener::unavaliableEvent(AvaliableNotifier *unavaliable){
    for(int i = 0; i < this->avaliableDrivers->size(); i++) {
        if (this->avaliableDrivers->at(i) == unavaliable){
            this->avaliableDrivers->at(i) = NULL;
            this->avaliableDrivers->erase(avaliableDrivers->begin() + i);
            return;
        }
    }
}
