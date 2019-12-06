#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "line.h"
#include <QPoint>
#include "vector.h"

class polyline : public shape
{
public:
	polyline();
	polyline(int shapeID, vector<QPoint> p1);
	void draw(QPaintDevice *toDraw);
	void moveShape(int offsetX, int offsetY);
	//    int perimeter();// Calculates the perimeters
	//    double area();// Calculates the area

private:
	vector<line*> lines;
};

#endif // POLYLINE_H
