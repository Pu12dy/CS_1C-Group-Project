#include "Rectangle.h"



//Rectangle::Rectangle()
//{
//	this->shapeID = 0;
//	this->x1 = 0;
//	this->y1 = 0;
//	this->length = 0;
//	this->width = 0;
//}


Rectangle::Rectangle(int shapeID, int x1, int y1, int length, int width)
{
	this->shapeID = shapeID;
	this->x1 = x1;
	this->y1 = y1;
	this->length = length;
	this->width = width;
}



Rectangle::~Rectangle(){}



void Rectangle::draw()
{
	
}



void Rectangle::move()
{
	
}



int Rectangle::perimeter(int a, int b, int c)
{
	int perimeter = 0;
	
	perimeter = a + b + c;
	
	return perimeter;
}



double Rectangle::area(int base, int height)
{
	double area = 0.0;
	
	area = (base * height) / 0.5;
	
	return area;
}
