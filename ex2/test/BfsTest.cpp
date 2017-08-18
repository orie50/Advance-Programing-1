#include "BfsTest.h"
/******************************************************************************
* The Test Operation: realese BfsTest allocation
******************************************************************************/
void BfsTest::TearDown() {
    delete map;
    delete bfs;
}
/******************************************************************************
* The Test Operation: BfsTest ctor
******************************************************************************/
BfsTest::BfsTest() {
    int width = 10;
    int length = 10;
    map = new Map(width, length);
    Point* maxPoint = new Point(width,length);
    bfs = new Bfs(maxPoint);
    //no need for the actual point object for bfs. see Bfs ctor
    delete maxPoint;
}
/******************************************************************************
* The Test Operation: create some routes and verify that are indeed the
* shortest route. this test will not pass if private Test Bfs::createRoute
* doesn't work
******************************************************************************/
TEST_F(BfsTest, ShortestRouteTest){
    //comparator for Bfs logic
    PointComparator* cmp = new PointComparator();
    // route from (0,0) to (9,9)
    Point* src = new Point(0,0);
    Point* dest = new Point(9,9);
    //bfs route output
    vector<Node*>* route = bfs->find_shortest_route(map, src, dest, cmp);
    //expected route output
    vector<Node*>* shortestRoute = new vector<Node*>();
    //setting up the correct route
    for(int i = 0; i < 10; i++){
        shortestRoute->push_back(new Point(0,i));
    }
    for(int i= 1; i < 10; i++){
        shortestRoute->push_back(new Point(i,9));
    }
    //compare each point, and realese allocated memory
    for(int i = 0; i < shortestRoute->size(); i++){
        ASSERT_TRUE(cmp->equals(shortestRoute->at(i), route->at(i)));
        delete shortestRoute->at(i);
        delete route->at(i);
    }
    delete dest;
    delete route;

    // route from (9,9) to (0,0)
    src = new Point(9,9);
    dest = new Point(0,0);
    route = bfs->find_shortest_route(map, src, dest, cmp);
    for(int i= 9; i >= 0; i--){
        shortestRoute->push_back(new Point(i,9));
    }
    for(int i= 8; i >= 0; i--){
        shortestRoute->push_back(new Point(0,i));
    }
    for(int i = 0; i < shortestRoute->size(); i++){
        ASSERT_TRUE(cmp->equals(shortestRoute->at(i), route->at(i)));
        delete shortestRoute->at(i);
        delete route->at(i);
    }
    delete dest;
    delete route;

    // route from (0,9) to (9,0)
    src = new Point(0,9);
    dest = new Point(9,0);
    route = bfs->find_shortest_route(map, src, dest, cmp);
    for(int i= 0; i < 10; i++){
        shortestRoute->push_back(new Point(i,9));
    }
    for(int i= 8; i >= 0; i--){
        shortestRoute->push_back(new Point(9,i));
    }
    for(int i = 0; i < shortestRoute->size(); i++){
        ASSERT_TRUE(cmp->equals(shortestRoute->at(i), route->at(i)));
        delete shortestRoute->at(i);
        delete route->at(i);
    }
    delete dest;
    delete route;

    // route from (0,9) to (9,0)
    src = new Point(9,0);
    dest = new Point(0,9);
    route = bfs->find_shortest_route(map, src, dest, cmp);
    for(int i= 9; i >= 0; i--){
        shortestRoute->push_back(new Point(i,0));
    }
    for(int i= 1; i < 10; i++){
        shortestRoute->push_back(new Point(0,i));
    }
    for(int i = 0; i < shortestRoute->size(); i++){
        ASSERT_TRUE(cmp->equals(shortestRoute->at(i), route->at(i)));
        delete shortestRoute->at(i);
        delete route->at(i);
    }
    delete dest;
    delete route;
    delete cmp;
    delete shortestRoute;
}