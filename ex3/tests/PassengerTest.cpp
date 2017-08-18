#include "gtest/gtest.h"
#include "../src/Passenger.h"
/******************************************************************************
* PassengerTest: source file that test the Passenger class.
******************************************************************************/

/******************************************************************************
* The Test Operation: check if the satisfacation between 1 to 5
******************************************************************************/
TEST(Passenger, satisfacationTest){
    Passenger passenger = Passenger();
    EXPECT_LE(1, passenger.satisfacation());
    EXPECT_GE(5, passenger.satisfacation());
}
