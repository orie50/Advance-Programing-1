#include "gtest/gtest.h"
#include "../src/Driver.h"
#include "../src/TaxiCenter.h"

/******************************************************************************
* TripTest: source file that test the Trip class.
******************************************************************************/

/******************************************************************************
* The Test Operation: check the next point in the trip
******************************************************************************/
TEST(Trip, getNextPointTest){
    Map* map = new Map(3,3);
    Point* point = NULL;
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(2, 2);
    Trip* trip = new Trip(0, start, end, 2, 1);
    // create the trip's route
    taxiCenter->addTrip(trip);
    // check the trip's advanced
    for(int i = 0; i <= 2; i++){
        point = trip->getNextPoint();
        EXPECT_EQ(Point(0,i), *point);
        delete point;
    }
    for(int j = 1; j <= 2; j++){
        point = trip->getNextPoint();
        EXPECT_EQ( Point(j,2), *point);
        delete point;
    }
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: create a trip with price 5 and compare to getPrice
******************************************************************************/
TEST(Trip, getPriceTest){
    float price = 5;
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, 2, price);
    EXPECT_FLOAT_EQ(5, trip->getPrice());
    delete trip;
}

/******************************************************************************
* The Test Operation: create a trip with 2 passengers and compare to
* getNumPassengers
******************************************************************************/
TEST(Trip, getNumPassengersTest){
    int passengers = 2;
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, passengers, 1);
    EXPECT_EQ(2, trip->getNumPassengers());
    delete trip;
}

/******************************************************************************
* The Test Operation: create a trip with 2 passengers and check is it's between
* 2 to 10 (every passenger give grade between 1 to 5)
******************************************************************************/
TEST(Trip, sumOfSatisfactionTest){
    int passengers = 2;
    Point start(0, 0);
    Point end(0, 1);
    Trip* trip = new Trip(0, start, end, passengers, 1);
    EXPECT_LE(2, trip->sumOfSatisfaction());
    EXPECT_GE(10, trip->sumOfSatisfaction());
    delete trip;
}