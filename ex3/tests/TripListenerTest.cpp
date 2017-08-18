#include <gtest/gtest.h>
#include "../src/Driver.h"
#include "../src/TripListener.h"

/******************************************************************************
* The Test Operation: test that the avaliableEvent and
* UnavaliableEvent works correctly
******************************************************************************/
TEST(TripListenerTest, EventsTest){
    vector <Driver*> avaliableDrivers;
    Driver driver(0, 40, SINGLE, 6, 0);
    TripListener tl(&avaliableDrivers);
    tl.avaliableEvent(&driver);
    EXPECT_EQ(&driver, avaliableDrivers.at(0));
    tl.unavaliableEvent(&driver);
    EXPECT_EQ(avaliableDrivers.size(), 0);
}
