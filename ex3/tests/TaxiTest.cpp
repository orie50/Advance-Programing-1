#include "gtest/gtest.h"
#include "../src/Taxi.h"
/******************************************************************************
* TaxiTest: source file that test the Taxi class.
******************************************************************************/

/******************************************************************************
* The Test Operation: create taxi with id 0 and check it's id
******************************************************************************/
TEST(Taxi, getIdTest){
    int id = 0;
        Taxi taxi(id, HONDA, RED);
        EXPECT_EQ(0, taxi.getId());
}

/******************************************************************************
* The Test Operation: create taxi wnd check it's tariff (expect to 1)
******************************************************************************/
TEST(Taxi, getTariffTest){
        Taxi taxi(1, HONDA, RED);
        EXPECT_FLOAT_EQ(1, taxi.getTariff());
}

/******************************************************************************
* The Test Operation: create taxi with random location set to taxi
* and compare to getLocation
******************************************************************************/
TEST(Taxi, getLocationTest) {
    for (int i = 0; i < 10; i++) {
        Point* location = new Point((rand() % 3), (rand() % 3));
        Taxi* taxi = new Taxi(1, HONDA, RED);
        taxi->updateLocation(location);
        EXPECT_EQ(*location, *taxi->getLocation());
        delete location;
        delete taxi;
    }
}

/******************************************************************************
* The Test Operation: update the taxi's location and compare with getLocation
******************************************************************************/
TEST(Taxi, updateLocationTest) {
    Point* location =NULL;
    Taxi* taxi = new Taxi(1, HONDA, RED);
    for (int i = 0; i < 10; i++) {
        location = new Point((rand() % 3), (rand() % 3));
        taxi->updateLocation(location);
        ASSERT_EQ(*location, *taxi->getLocation());
        delete location;
    }
    delete taxi;
}

/******************************************************************************
* The Test Operation: create taxi (with default 0 km) and compare to 0
******************************************************************************/
TEST(Taxi, getKmTest){
    Taxi taxi(1, HONDA, RED);
    EXPECT_FLOAT_EQ(0, taxi.getKm());
}

/******************************************************************************
* The Test Operation: check the taxi's movmenet
******************************************************************************/
TEST(Taxi, moveOneStepTest){
    Taxi taxi(1, HONDA, RED);
    Point* location = taxi.getLocation();
    Point* nextLocation = new Point(location->getX(), location->getY() + 1);
    taxi.moveOneStep(nextLocation);
    // check the taxi's km (private method)
    EXPECT_FLOAT_EQ(taxi.getKm(), 0.001);
    EXPECT_EQ(*taxi.getLocation(), *nextLocation);
    delete nextLocation;
}

/******************************************************************************
* The Test Operation: expect to get reguler taxi velocity = 1
******************************************************************************/
TEST(Taxi, getVelocityTest){
    Taxi taxi(1, HONDA, RED);
    EXPECT_EQ(1, taxi.getVelocity());
}

/******************************************************************************
* The Function Operation: test the equal and not equal operator
******************************************************************************/
TEST(Taxi, equalityOperatorsTest) {
    Taxi taxi1(0, HONDA, RED);
    Taxi taxi2(1, HONDA, RED);
    Taxi taxi3(0, HONDA, RED);
    EXPECT_EQ(taxi1, taxi3);
    EXPECT_NE(taxi1, taxi2);
}