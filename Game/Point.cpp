#include"Point.h"


Point::Point(int x, int y) :x(0), y(0)
{
	setX(x);
	setY(y);
}
void Point::setX(int x)
{
	this->x = x;
}
int Point::getX()const
{
	return x;
}
void Point::setY(int y)
{
	this->y = y;
}
int Point::getY()const
{
	return y;
}
Point::Point() :x(0), y(0)
{}