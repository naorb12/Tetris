#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(int newX, int newY) : x(newX), y(newY) {}

// Getter functions
int Point::getX() const{
	return x;
}

int Point::getY() const{
	return y;
}

// Setter functions
void Point::setXAndY(int newX, int newY) {
	x = newX;
	y = newY;
}
void Point::setX(int newX) {
	x = newX;
}
void Point::setY(int newY) {
	y = newY;
}
// add functions
void Point::addToX(int addX)
{
	x += addX;
}
void Point::addToY(int addY)
{
	y += addY;
}
void Point::addToXAndY(int addX, int addY)
{
	x += addX;
	y += addY;
}
