#include <gtest/gtest.h>
#include "../src/Driver.h"

/******************************************************************************
* TripTest: source file that test the Driver class.
******************************************************************************/

/******************************************************************************
* The Test Operation: create driver with random age and compare to the getAge
******************************************************************************/
TEST(Driver, getAgeTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    for (int i = 0; i < 10; i++) {
        int age = (rand() % 30) + 20;
        Driver driver = Driver(5, age, SINGLE, 5, taxi, Map(10, 10));
        EXPECT_EQ(age, driver.getAge());
    }
}

/******************************************************************************
* The Test Operation: create random age, set to driver and compare to the getAge
******************************************************************************/
TEST(Driver, setAgeTest){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    int age = 20;
    Driver driver = Driver(5, age, SINGLE, 5, taxi, Map(10, 10));
        for (int i = 0; i < 10; i++) {
            age = (rand() % 30) + 20;
            driver.setAge(age);
            ASSERT_EQ(age, driver.getAge());
        }
}

/******************************************************************************
* The Test Operation: create taxi and compare it with the getTaxi
******************************************************************************/
TEST(Driver, getTaxiTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    EXPECT_EQ(taxi, driver.getTaxi());
}

/******************************************************************************
* The Test Operation: create a driver with status and compare to getStatus
******************************************************************************/
TEST(Driver, getStatusTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    for (int i = 0; i < 4; i++) {
        Status status = Status (i);
        Driver driver = Driver(5, 20, status, 5, taxi, Map(10, 10));
        EXPECT_EQ(status, driver.getStatus());
    }
}

/******************************************************************************
* The Test Operation: create a status set it to driver and compare with get
******************************************************************************/
TEST(Driver, setStatusTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Status status = SINGLE;
    Driver driver = Driver(5, 20, status, 5, taxi, Map(10, 10));
    for (int i = 0; i < 4; i++) {
        status = Status (i);
        driver.setStatus(status);
        ASSERT_EQ(status, driver.getStatus());
    }
}

/******************************************************************************
* The Test Operation: set new trip and check if he have trip
******************************************************************************/
TEST(Driver, newTripTest){
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    EXPECT_FALSE(driver.isAvaliable());
}

/******************************************************************************
* The Test Operation: set trip to the driver and check if he is avaliable
******************************************************************************/
TEST(Driver, isAvaliableTest){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    // driver start with trip = null
    EXPECT_TRUE(driver.isAvaliable());
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    driver.newTrip(trip);
    EXPECT_FALSE(driver.isAvaliable());
}

/******************************************************************************
* The Test Operation: compare the driver getPayment to the
* (trip price * the teriff of the taxi)
******************************************************************************/
TEST(Driver, getPaymentTest){
    float price = 4;
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(5, 5), 4, route, pass, price);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    // total price = price (4) * tariff (5) = 20
    EXPECT_EQ(driver.getPayment(), 20);
}

/******************************************************************************
* The Test Operation: check if the driver change his location after
* move one step
******************************************************************************/
TEST(Driver, moveOneStepTest) {
    vector<Point*>* route;
    vector <Passenger> pass;
    PointComparator cmp;
    // create a trip route
    Map *map = new Map(10,10);
    Point *src = new Point(0,0);
    Point *dest = new Point(9,9);
    route = map->getRoute(src, dest);
    Trip trip = Trip(1, Point(0, 0), Point(9, 9), 4, *route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, *map);
    for (int i = 0; i < route->size(); i++) {
        EXPECT_FALSE(driver.isAvaliable());
        driver.moveOneStep();
        Point p = driver.getTaxi().getLocation();
        // check if the driver's location updated
        EXPECT_TRUE(cmp.equals(&p, route->at(i)));
        EXPECT_EQ(driver.getPayment(), driver.getTaxi().getTariff() * i);
    }
    // move after the trip over
    EXPECT_TRUE(driver.isAvaliable());
    EXPECT_THROW(driver.moveOneStep(), exception);
    for(int i = 0; i < route->size(); i++){
        delete route->at(i);
    }
    delete map;
    delete dest;
    route->clear();
    delete route;
}

/******************************************************************************
* The Test Operation: compare the driver's getStisfacation and the
* one passenger stisfacation
******************************************************************************/
TEST(Driver, getSatisfacation){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    // create passenger and push it to the passenger's vector
    vector <Passenger> pass;
    Passenger passenger(Point (0,0), Point(1,1));
    pass.push_back(passenger);
    // create the route
    vector<Point*>* route;
    Map *map = new Map(10,10);
    Point *src = new Point(0,0);
    Point *dest = new Point(0,1);
    route = map->getRoute(src, dest);
    Trip trip = Trip(1, Point(0, 0), Point(0, 1), 1, *route, pass, 0);
    Driver driver = Driver(5, 25, SINGLE, 5, taxi, *map);
    // finish the trip
    driver.moveOneStep();
    // check the satisfacatin
    EXPECT_EQ(driver.getSatisfacation(), passenger.satisfacation());
    for(int i = 0; i < route->size(); i++){
        delete route->at(i);
    }
    delete map;
    delete dest;
    route->clear();
    delete route;
}