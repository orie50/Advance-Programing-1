#include "gtest/gtest.h"
#include "../src/LuxTaxi.h"
/******************************************************************************
* PassengerTest: source file that test the LuxTaxi class.
******************************************************************************/

/******************************************************************************
* The Test Operation: set random tariff and compare to getTariff
******************************************************************************/
TEST(LuxTaxi, setTariffTest) {
    float tariff = 0;
    LuxTaxi luxTaxi(1, HONDA, RED, tariff, Point(0,0));
    for (int i = 0; i < 10; i++) {
        tariff = (rand() / RAND_MAX) + (rand() % 100);
        luxTaxi.setTariff(tariff);
        ASSERT_EQ(tariff, luxTaxi.getTariff());
    }
}

/******************************************************************************
* The Test Operation: check the taxi's movmenet of one or two cells
* expected exception when try to move more than 2 cells
******************************************************************************/
TEST(LuxTaxi, moveOneStepTest){
    LuxTaxi luxTaxi(1, HONDA, RED, 1, Point(0,0));
    Point location = luxTaxi.getLocation();
    // move 1 cell
    Point nextLocation(location.getX(), location.getY() + 1);
    luxTaxi.moveOneStep(nextLocation);
    EXPECT_FLOAT_EQ(luxTaxi.getKm(), 0.001);
    EXPECT_EQ(luxTaxi.getLocation(), nextLocation);
    // move 2 cells
    nextLocation = Point(location.getX() + 1, location.getY() + 1);
    luxTaxi.moveOneStep(nextLocation);
    EXPECT_EQ(luxTaxi.getLocation(), nextLocation);
    EXPECT_FLOAT_EQ(luxTaxi.getKm(), 0.003);
    //try to move more then 2 cell
    nextLocation = Point(location.getX() + 2, location.getY() + 2);
    EXPECT_THROW(luxTaxi.moveOneStep(nextLocation), exception);
    //tests for out of map next location in driver tests
}
