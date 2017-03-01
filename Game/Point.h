#pragma once
#include<iostream>
#include<fstream>
class Point
{
public:
	Point();
	Point(int,int);
	void setX(int);
	int getX()const;
	void setY(int);
	int getY()const;

private:
	int x;
	int y;

};


