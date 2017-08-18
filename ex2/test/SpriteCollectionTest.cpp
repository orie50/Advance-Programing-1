#include "../src/SpriteCollection.h"
#include "../src/TaxiCenter.h"
#include "gtest/gtest.h"
/******************************************************************************
* PassengerTest: source file that test the SpriteCollection class.
******************************************************************************/

/******************************************************************************
* The Test Operation: add a sprite to the spriteCollection and expect no throw
* when try to remove
******************************************************************************/
TEST(SpriteCollectionTest, addSpriteClass){
    SpriteCollection sp;
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver* driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    sp.addSprite(driver);
    EXPECT_NO_THROW(sp.removeSprite(driver));
    delete driver;
}

/******************************************************************************
* The Test Operation: expect to exception when try to remove from empty vector
******************************************************************************/
TEST(SpriteCollectionTest, removeSpriteClass){
    SpriteCollection sp;
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver* driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    sp.addSprite(driver);
    sp.removeSprite(driver);
    EXPECT_THROW(sp.removeSprite(driver), exception);
    delete driver;
}

/******************************************************************************
* The Test Operation: add driver with trip to the spriteCollection and check
* if he moves when notify timePessed
******************************************************************************/
TEST(SpriteCollectionTest, notifyAllTimePassedTest) {
    // create the route
    SpriteCollection sp;
    vector <Passenger> pass;
    Map *map = new Map(10, 10);
    Point* src = new Point(1,1);
    Point* dest = new Point(9,9);
    vector<Point *>* route = map->getRoute(src,dest);
    Trip trip = Trip(1, *src, *dest, 4, *route, pass, 0);
    // create the driver and trip
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver *driver = new Driver(5, 20, SINGLE, 5, taxi, *map);
    driver->newTrip(trip);
    // add the driver to the spriteCollection
    sp.addSprite(driver);
    EXPECT_EQ(driver->getLocation(), Point(1,1));
    for (int i = 0; i < route->size(); i++) {
        // check if the driver move when notify time passed
        EXPECT_FALSE(driver->isAvaliable());
        sp.notifyAllTimePassed();
        EXPECT_EQ(driver->getLocation(), Point(0,i));
    }
    EXPECT_TRUE(driver->isAvaliable());
    for (int i = 0; i < route->size(); i++) {
        delete route->at(i);
    }
    delete dest;
    delete route;
    delete map;
    delete driver;
}