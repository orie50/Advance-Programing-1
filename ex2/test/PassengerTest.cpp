#include "gtest/gtest.h"
#include "../src/Passenger.h"
#include "../src/Driver.h"
/******************************************************************************
* PassengerTest: source file that test the Passenger class.
******************************************************************************/

/******************************************************************************
* The Test Operation: compare the satisfacation in case he gave 0
******************************************************************************/
TEST(Passenger, satisfacationTest){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    Passenger passenger = Passenger(Point (0,0), Point(1,1));
    EXPECT_EQ(0, passenger.satisfacation());
}
