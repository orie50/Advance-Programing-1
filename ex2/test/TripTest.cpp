#include "gtest/gtest.h"
#include "../src/Driver.h"
/******************************************************************************
* TripTest: source file that test the Trip class.
******************************************************************************/

/******************************************************************************
* The Test Operation: check the next point in the trip
******************************************************************************/
TEST(Trip, getNextPointTest){
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(2, 2), 4, route, pass, 0);
    EXPECT_EQ(trip.getNextPoint(), Point(0,1));
    EXPECT_EQ(trip.getNextPoint(), Point(0,2));
    EXPECT_EQ(trip.getNextPoint(), Point(1,2));
    EXPECT_EQ(trip.getNextPoint(), Point(2,2));
}

/******************************************************************************
* The Test Operation: create a trip with price 5 and compare to getPrice
******************************************************************************/
TEST(Trip, getPriceTest){
    vector<Point*> route;
    vector <Passenger> pass;
    float price = 5;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, price);
    EXPECT_FLOAT_EQ(5, trip.getPrice());
}

/******************************************************************************
* The Test Operation: set a random price and check if it equal to the get
******************************************************************************/
TEST(Trip, setPriceTest){
    vector<Point*> route;
    vector <Passenger> pass;
    float price;
    Trip trip = Trip(1, Point(0, 0), Point(5, 5), 4, route, pass, 0);
    for(int i = 0; i < 10; i++) {
        price = (rand() / RAND_MAX);
        trip.setPrice(price);
        EXPECT_FLOAT_EQ(trip.getPrice(), price);
    }
}