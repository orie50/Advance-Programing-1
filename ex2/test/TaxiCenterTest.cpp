#include "gtest/gtest.h"
#include "../src/TaxiCenter.h"
/******************************************************************************
* TripTest: source file that test the TaxiCenter class.
******************************************************************************/

/******************************************************************************
* The Test Operation: start the taxiCentre and check if no exepcion throw
******************************************************************************/
TEST(TaxiCenter, startTest){
    vector <DriverInfo> employees;
    Map* map = new Map(10,10);
    TaxiCenter taxiCenter = TaxiCenter(map, employees);
    taxiCenter.start();
    EXPECT_NO_THROW("Somthing wrong");
    delete map;
}

/******************************************************************************
* The Test Operation: create driver with trip, add his driver info to the
* employees vector and check if the time passed update
******************************************************************************/
TEST(TaxiCenter, timePassedTest){
    // create driver
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    Map* map = new Map(10,10);
    // create driver info put in the emplyees vector and check if he move after time passed
    vector <DriverInfo> employees;
    DriverInfo driverInfo = DriverInfo(driver, taxi,Point(0,0), trip);
    employees.push_back(driverInfo);
    TaxiCenter taxiCenter = TaxiCenter(map, employees);
    taxiCenter.timePassed();
    EXPECT_EQ(driverInfo.getLocation(), Point(0,1));
    delete map;
}