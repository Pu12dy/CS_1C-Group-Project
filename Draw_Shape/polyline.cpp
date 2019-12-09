#include "polyline.h"

polyline::polyline()
{
	setShapeID(116);
	QPoint point;

	point.setX(50);
	point.setY(150);
	points.push_back(point);

	point.setX(100);
	point.setY(250);
	points.push_back(point);

	point.setX(150);
	point.setY(150);
	points.push_back(point);

	point.setX(200);
	point.setY(250);
	points.push_back(point);
}

polyline::polyline(int shapeID, Vector<QPoint> p1)
{
	setShapeID(shapeID);
	points = p1;
	//    for (int i = 0; i < p1.size() - 1; ++i)
	//    {
	//        line *temp = new line(shapeID, p1[i], p1[i + 1]);
	//        lines.push_back(temp);
	//    }
}

polyline::polyline(int shapeID, Vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
	: polyline(shapeID, p1)
{
	setPenColor(penColor);
	setPenWidth(penWidth);
	setPenStyle(penStyle);
	setPenCapStyle(penCap);
	setPenJoinStyle(penJoin);
}

polyline::~polyline() {}

void polyline::draw(QPaintDevice *toDraw)
{

	getQPainter().begin(toDraw);
	getQPainter().setPen(getQPen());
	getQPainter().setBrush(getQBrush());
	getQPainter().drawPolyline(points.getArrayFromVector(), points.size());
	getQPainter().end();

	//    for (int i = 0; i < lines.size(); ++i)
	//    {
	//        lines[i]->draw(toDraw);
	//    }
}


void polyline::moveShape(int offsetX, int offsetY)
{

	for (int i = 0; i < points.size(); ++i)
	{
		points[i].setX(points[i].x() + offsetX);
		points[i].setY(points[i].y() + offsetY);
	}
}


void polyline::changeShapeSize(int newSize)
{
	//    for (int i = 0; i < lines.size(); ++i)
	//    {
	//        lines[i]->changeShapeSize(newSize);
	//    }
}

double polyline::perimeter() const
{
	return 0;
}

double polyline::area() const
{
	return 0;
}

std::string polyline::getShapeType() const
{
	return "Polyline";
}
