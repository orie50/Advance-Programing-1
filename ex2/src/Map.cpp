#include <stdexcept>
#include "Map.h"
using namespace std;
/******************************************************************************
* The Function Operation: retrive the vertical and horizontal
* neihgbors of a given point
******************************************************************************/
queue<Node*>* Map::getAdjacent(const Node *point) {
    if (!isInMap((Point*) point)) {
        throw out_of_range("getAdjacent args are out of bounds!");
    }
	queue<Node*>* adjacents = new queue<Node*>();
	int x = ((Point*) point)->getX();
	int y = ((Point*) point)->getY();
	//verify which are Point's neighbors and add them to adjacents
	if (x - 1 >= 0) adjacents->push(new Point(x - 1, y));
	if (y + 1 < length) adjacents->push(new Point(x , y + 1));
	if (x + 1 < width) adjacents->push(new Point(x + 1, y));
	if (y - 1 >= 0) adjacents->push(new Point(x , y - 1));
	return adjacents;
}
/******************************************************************************
* The Function Operation: retrive the shortest route
* between two points in the map
******************************************************************************/
vector<Point*>* Map::getRoute(Point *start, Point *end){
    if (!isInMap(start) || !isInMap(end)) {
        throw out_of_range("getRoute args are out of bounds!");
    }
	//create max point availble in the grid, which has the highest hash value
    Node* maxPoint = new Point(width, length);
	//send max point to bfs, in order to allocate a large enough hash table
	Bfs bfs(maxPoint);
    delete maxPoint;
    PointComparator comparator;
	return (vector<Point*>*) bfs.find_shortest_route(this,
                                                     start, end, &comparator);
}
/******************************************************************************
* The Function Operation: decide on whether point is in the map boundarys
******************************************************************************/
bool Map::isInMap(Point *p){
    int x = p->getX();
    int y = p->getY();
	//verify that x and y are between valid values of the map
    return (x >= 0 && x < width && y >= 0 && y < length);
}
/******************************************************************************
* The Function Operation: deserialize a Map object from text width_length
******************************************************************************/
Map* Map::deserialize(char* s){
    Point* maxPoint = Point::deserialize(s);
    Map* g = new Map(maxPoint->getX(),maxPoint->getY());
    delete maxPoint;
    return g;
}
/******************************************************************************
* The Function Operation: return x axis value of the point
******************************************************************************/
int Point::getX(){
	return this->x;
}
/******************************************************************************
* The Function Operation: return y axis value of the point
******************************************************************************/
int Point::getY(){
	return this->y;
}
/******************************************************************************
* The Function Operation: return an integer value for a point with cantor's
* diagonal proof method
******************************************************************************/
int Point::hash(){
	int x = this->getX();
	int y = this->getY();
	//map (x,y) to an integer number
	return ((x + y) * (x + y + 1)) / 2 + x;
}
/******************************************************************************
* The Function Operation: evaluate if 2 points are equal by their x,y values
******************************************************************************/
bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}
/******************************************************************************
* The Function Operation: evaluate if 2 points are not equal by their x,y values
******************************************************************************/
bool Point::operator!=(const Point &other) const {
    return !(other == *this);
}
/******************************************************************************
* The Function Operation: deserialize a Point object from text x_y
******************************************************************************/
Point* Point::deserialize(char* s){
    char* x = strtok(s,"_");
    char* y = strtok(NULL, "_");
    return new Point(atoi(x), atoi(y));
}
/******************************************************************************
* The Function Operation: evaluate if 2 points are equal by their == operator
* used in order to provide a clean downcast and code writing
******************************************************************************/
bool PointComparator::equals(const Node *n1, const Node *n2) const {
    // downcast to Point, in order to use Point '==' operator
    return   *(Point*) n1 == *(Point*) n2;
}
