#include <gtest/gtest.h>
#include "../src/Map.h"
using namespace std;
//
// Created by adi on 04/12/16.
//
/******************************************************************************
* The Function Operation: verify if two points are
* adjacents according to the map rules
******************************************************************************/
bool isAdjacent(Point* src, Point* neighbor){
    // case neighbor is adjacent in the X axis
    if (((src->getX() == neighbor->getX() + 1) || (src->getX() == neighbor->getX() - 1)) &&
            (src->getY() == neighbor->getY())){
        return 1;
    // case neighbor is adjacent in the Y axis
    } else if (((src->getY() == neighbor->getY() + 1) || (src->getY() == neighbor->getY() - 1)) &&
               (src->getX() == neighbor->getX())){
        return 1;
    }
    return 0;
}

/******************************************************************************
* The Test Operation: assign random point and check if exception
* is thrown if it outside of the map
******************************************************************************/
TEST(MapTest, MapBoundryTest){
    Map* map;
    Point* p;
    int x,y;
    int width;
    int length;
    for(int i = 0; i < 10; i++){
        width = rand() % 100;
        length = rand() % 100;
        //random map
        map = new Map(width,length);
        x = rand() % 150;
        y= rand() % 150;
        //random point that can be larger than width or length
        p = new Point(x, y);
        if (x < 0 || x >= width || y < 0 || y >= length){
            EXPECT_THROW(map->getAdjacent(p), out_of_range);
        }
        delete p;
        delete map;
    }
}

/******************************************************************************
* The Test Operation: verify that Map adjacent logic is correct with
* random points
******************************************************************************/
TEST(MapTest, MapAdjacentTest){
    int width = 10;
    int length = 10;
    Map map(width, length);
    Point* p;
    Point* neighbor;
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 10;
        y = rand() % 10;
        p = new Point(x, y);
        //get the point adjacent
        queue<Node*>* adjacents = map.getAdjacent(p);
        //verify that the output is correct
        while (!adjacents->empty()){
            neighbor = (Point*) adjacents->front();
            EXPECT_TRUE(isAdjacent(p, neighbor));
            delete neighbor;
            adjacents->pop();
        }
        delete adjacents;
        delete p;
    }
}

/******************************************************************************
* The Test Operation: verify that Map gives a route that start at src,
* and ends at dest, and passes only through adjacent points.
* the route size isn't checked here.
******************************************************************************/
TEST(MapTest, MapRouteTest){
    PointComparator cmp;
    int x,y;
    int width;
    int length;
    vector<Point*>* route = NULL;
    Point *src, *dest, *temp, *outOfBound;
    Map* map = NULL;
    for(int i = 0; i < 10; i++){
        //create random map
        width = rand() % 100;
        length = rand() % 100;
        map = new Map(width,length);
        //create start point
        x = rand() % 100;
        y = rand() % 100;
        src = new Point(x, y);
        //create end point
        x = rand() % 100;
        y= rand() % 100;
        dest = new Point(x, y);
        route = map->getRoute(src,dest);
        //test isInMap function
        outOfBound = new Point(width + 1, length + 1);
        EXPECT_THROW(map->getRoute(outOfBound,outOfBound), out_of_range);
        delete map;
        delete outOfBound;
        //verify the route start at src
        temp = route->at(0);
        EXPECT_TRUE(cmp.equals((Node*) src, (Node*) temp));
        delete src;
        //verify that the route is continuous
        for(int i = 1; i < route->size(); i++){
            temp = route->at(i);
            EXPECT_TRUE(isAdjacent(src,temp));
            src = temp;
        }
        //verify the route ends at dest
        EXPECT_TRUE(cmp.equals((Node*) src, (Node*) dest));
        delete dest;
        for(int i = 1; i < route->size(); i++){
            delete route->at(i);
        }
        route->clear();
        delete route;
    }
};

/******************************************************************************
* The Test Operation: create a random map and a point outside its boundry.
* if exception is thrown from getRoute, then the Map boundries
* are set correctly
******************************************************************************/
TEST(MapTest, MapDeserializationTest){
    const int asciiOfZero = 48;
    int width;
    int length;
    Point* p;
    Map* map = NULL;
    char str[] = "00_00";
    for(int i =0 ; i<10; i++) {
        width = rand() % 100;
        length = rand() % 100;
        p = new Point(width + 1, length + 1);
        //assgin the random coordinate as a string
        str[0] = asciiOfZero + width / 10;
        str[1] = asciiOfZero + width % 10;
        str[3] = asciiOfZero + length / 10 ;
        str[4] = asciiOfZero + length % 10 ;
        map = Map::deserialize(str);
        EXPECT_THROW(map->getRoute(p,p), out_of_range);
        delete p;
    }
};
