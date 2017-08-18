//
// Created by adi on 04/12/16.
//

#ifndef EX2_BFSTEST_H
#define EX2_BFSTEST_H

#include <gtest/gtest.h>
#include <vector>
#include "../src/Bfs.h"
#include "../src/Map.h"
/******************************************************************************
* BfsTest: Test class to test Bfs logic and private functions
******************************************************************************/
class BfsTest : public ::testing::Test{
protected:
    Bfs* bfs;
    Map* map;
    virtual void TearDown();
public:
    BfsTest();
};
#endif //EX2_BFSTEST_H
