#include "gtest/gtest.h"
#include "../src/LuxTaxi.h"
/******************************************************************************
* LuxTaxiTest: source file that test the LuxTaxi class.
******************************************************************************/

/******************************************************************************
* The Test Operation: expect to get lux taxi velocity = 2
******************************************************************************/
TEST(LuxTaxi, getVelocityTest){
    LuxTaxi lx(0, HONDA, RED);
    EXPECT_EQ(2, lx.getVelocity());
}