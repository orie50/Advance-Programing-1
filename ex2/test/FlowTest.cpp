#include "gtest/gtest.h"
#include "../src/Flow.h"
#include "../src/DriverInfo.h"
/******************************************************************************
* PassengerTest: source file that test the Flow class.
******************************************************************************/

/******************************************************************************
* The Test Operation: create flow and initilize it expected for no exception
******************************************************************************/
TEST(Flow, initilizeTest){
    SpriteCollection sp;
    Flow flow = Flow(sp);
    flow.initilize();
    EXPECT_NO_THROW("Somthing wrong");
}

/******************************************************************************
* The Test Operation: create flow and run it expected for no exception
******************************************************************************/
TEST(Flow, runTest){
    SpriteCollection sp;
    Flow flow = Flow(sp);
    flow.run();
    EXPECT_NO_THROW("Somthing wrong");
}

/******************************************************************************
* The Test Operation: check if when notify time passed the sprites in the
* SpriteCollection change location
******************************************************************************/
TEST(Flow, notifyTimePassedTest){
    // create driver and trip
    SpriteCollection sp;
    vector <Passenger> pass;
    Map *map = new Map(10, 10);
    vector<Point *> route;
    for (int i = 0; i < 2; i++) {
        route.push_back(new Point(0, i));
    }
    Trip trip = Trip(1, Point(0, 0), Point(2, 2), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver *driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));Flow flow = Flow(sp);
    driver->newTrip(trip);
    // add the driver to the flow sprite collection
    sp.addSprite(driver);
    EXPECT_EQ(driver->getLocation(), Point(0,0));
    for (int i = 0; i < 2; i++) {
        // check if the sprites changed location
        flow.notifyTimePassed();
        EXPECT_EQ(driver->getLocation(), Point(0,i));
    }
    EXPECT_TRUE(driver->isAvaliable());
    for (int i = 0; i < 2; i++) {
        delete route.at(i);
    }
    delete map;
    delete driver;
}