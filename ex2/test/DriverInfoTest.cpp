#include "gtest/gtest.h"
#include "../src/DriverInfo.h"
/******************************************************************************
* TripTest: source file that test the DriverInfo class.
******************************************************************************/

/******************************************************************************
* The Test Operation: check if the location updeted when driver time passed
******************************************************************************/
TEST(DriverInfo, getLocationTest){
    // create driver and trip
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    DriverInfo driverInfo = DriverInfo(driver, taxi,Point(0,0), trip);
    for(int i = 0; i < 5; i++){
        // driver time passed and check if the location updeted
        driver.moveOneStep();
        EXPECT_EQ(Point(0,i), driverInfo.getLocation());
    }
}