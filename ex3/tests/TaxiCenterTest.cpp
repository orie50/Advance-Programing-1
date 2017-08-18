#include "gtest/gtest.h"
#include "../src/TaxiCenter.h"

/******************************************************************************
* TaxiCenterTest: source file that test the TaxiCenter class.
******************************************************************************/

/******************************************************************************
* The Test Operation: add driver with id 0 and check the location of the
* driver with id 0 in the driver's vector expect to get the default driver's
* location (0,0)
******************************************************************************/
TEST(TaxiCenter, addDriverTest){
    Map* map = new Map(3,3);
    Driver* driver = new Driver(0, 40, SINGLE, 6, 0);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    taxiCenter->addDriver(driver);
    Point* point = taxiCenter->getDriverLocation(0);
    EXPECT_EQ(Point(0,0), *point);
    delete point;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: add taxi with id 0 to the avaliable cabs vector and
* check if the search by id give the right taxi from the vector
******************************************************************************/
TEST(TaxiCenter, searchTaxiByIdTest){
    Map* map = new Map(3,3);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    // no such taxi
    EXPECT_TRUE(taxiCenter->searchTaxiById(0) == NULL);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    taxiCenter->addAvaliableTaxi(taxi);
    // check if it's same taxi
    EXPECT_EQ(*taxi, *taxiCenter->searchTaxiById(0));
    delete taxi;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: add taxi with id 0 to the avaliable cabs vector and
* check if the taxi added to the vector
******************************************************************************/
TEST(TaxiCenter, addAvaliableTaxiTest){
    Map* map = new Map(3,3);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    taxiCenter->addAvaliableTaxi(taxi);
    EXPECT_EQ(*taxi, *taxiCenter->searchTaxiById(0));
    delete taxi;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: add trip and check if the taxi center calculate it's
* route and add it to the driver
******************************************************************************/
TEST(TaxiCenter, addTripTest){
    Map* map = new Map(3,3);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(0, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0,0);
    Point end(2,2);
    Trip* trip = new Trip(0,start, end, 2, 1);
    taxiCenter->addTrip(trip);
    // check if the taxi center calculate the trip's route
    Point* point = trip->getNextPoint();
    EXPECT_TRUE(point != NULL);
    delete point;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: add driver with id 0 and default location (0,0) and ask
 * for the driver's (with id 0) location expect (0,0)
******************************************************************************/
TEST(TaxiCenter, getDriverLocationTest) {
    Map* map = new Map(3,3);
    Driver* driver = new Driver(0, 40, SINGLE, 6, 0);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    taxiCenter->addDriver(driver);
    Point* point = taxiCenter->getDriverLocation(0);
    EXPECT_EQ(Point(0,0), *point);
    delete point;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: add driver and give him a trip check if when time passed
* the driver in the driver's vector move one step
******************************************************************************/
TEST(TaxiCenter, timePassedTest) {
    Map *map = new Map(3,3);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(0, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, 2, 1);
    // calculate a route and give to the driver
    taxiCenter->addTrip(trip);
    Point* point = NULL;
    for (int i = 0; i < 2; i++) {
        // order to driver with trip to move
        taxiCenter->timePassed();
        point = taxiCenter->getDriverLocation(0);
        // check the driver's move
        EXPECT_EQ(Point(0,i), *point);
        delete point;
    }
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: add driver and give him a trip and check if the taxi
* center should stop (need to stop when all the driver is avaliable)
******************************************************************************/
TEST(TaxiCenter, shouldStopTest) {
    Map* map = new Map(3,3);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, 2, 1);
    taxiCenter->addTrip(trip);
    EXPECT_FALSE(taxiCenter->shouldStop());
    delete taxiCenter;
}