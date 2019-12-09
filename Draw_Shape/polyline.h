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
	polyline(int shapeID, Vector<QPoint> p1);
	polyline(int shapeID, Vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
	virtual ~polyline();
	void draw(QPaintDevice *toDraw) override;
	void moveShape(int offsetX, int offsetY) override;
	void changeShapeSize(int newSize) override;
	double perimeter() const override; // Calculates the perimeters
	double area() const override;// Calculates the area
	std::string getShapeType() const override;

private:
	// vector<line*> lines;
	Vector<QPoint> points;
};

#endif // POLYLINE_H
