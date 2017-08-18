//
// Created by adi on 06/12/16.
//

#ifndef EX2_POINTTEST_H
#define EX2_POINTTEST_H

#include <gtest/gtest.h>
#include "../src/Map.h"
/******************************************************************************
* The Function Operation: allocte random point and test its getters
******************************************************************************/
TEST(PointTest, getterTest){
    Point p(0,0);
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 100;
        y = rand() % 100;
        p = Point(x,y);
        EXPECT_EQ(p.getX(), x);
        EXPECT_EQ(p.getY(), y);
    }
}
/******************************************************************************
* The Function Operation: test the output of point hash function
******************************************************************************/
TEST(PointTest, hashTest){
    Point p0(72,36);
    Point p1(83,86);
    Point p2(77,15);
    Point p3(93,35);
    Point p4(86,92);
    Point p5(49,21);
    Point p6(62,27);
    Point p7(90,59);
    Point p8(63,26);
    Point p9(40,26);

    EXPECT_EQ(p0.hash(), 5958);
    EXPECT_EQ(p1.hash(), 14448);
    EXPECT_EQ(p2.hash(), 4355);
    EXPECT_EQ(p3.hash(), 8349);
    EXPECT_EQ(p4.hash(), 16017);
    EXPECT_EQ(p5.hash(), 2534);
    EXPECT_EQ(p6.hash(), 4067);
    EXPECT_EQ(p7.hash(), 11265);
    EXPECT_EQ(p8.hash(), 4068);
    EXPECT_EQ(p9.hash(), 2251);

}
/******************************************************************************
* The Function Operation: test the equal and not equal operator
******************************************************************************/
TEST(PointTest, equalityOperatorsTest) {
    Point point(0,0);
    Point other(0,0);
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 100;
        y = rand() % 100;
        point = Point(x,y);
        //y+1 in case random gives the same number
        other = Point(y + 1,x);
        EXPECT_EQ(point, point);
        EXPECT_NE(point, other);
        EXPECT_EQ(other, other);
    }
}

/******************************************************************************
* The Function Operation: test the serialization process of point
******************************************************************************/
TEST(PointTest, PointDeserializationTest){
    const int asciiOfZero = 48;
    Point *p = NULL;
    int x,y;
    for(int i = 0; i < 10; i++){
        char str[] = "00,00";
        x = rand() % 100;
        y = rand() % 100;
        //assgin the random coordinate as a string
        str[0] = asciiOfZero +  x / 10;
        str[1] = asciiOfZero +  x % 10;
        str[3] = asciiOfZero + y / 10 ;
        str[4] = asciiOfZero + y % 10 ;
        p = Point::deserialize(str);
        EXPECT_EQ(*p, Point(x,y));
        delete p;
    }
}

TEST(PointTest, PointComparatorTest){
    PointComparator cmp;
    Point *p1 = NULL;
    Point *p2 = NULL;
    Point *p3 = NULL;
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 100;
        y = rand() % 100;
        p1 = new Point(x,y);
        p2 = new Point(x,y);
        p3 = new Point(y + 1,x + 1);
        //assgin the random coordinate as a string
        EXPECT_TRUE(cmp.equals((Node*) p1, (Node*) p2));
        EXPECT_FALSE(cmp.equals((Node*) p1, (Node*) p3));
        delete p1;
        delete p2;
        delete p3;
    }
}
#endif