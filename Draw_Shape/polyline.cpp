#include "polyline.h"

polyline::polyline()
{
    setShapeID(116);
    // Tester QPoints for polyline
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

polyline::~polyline(){}

void polyline::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().drawPolyline(points.getArrayFromVector(), points.size());
    getQPainter().end();
}


void polyline::moveShape(int offsetX, int offsetY)
{
    for (int i = 0; i < lines.size(); ++i)
    {
        lines[i]->moveShape(offsetX, offsetY);
    }
}


void polyline::changeShapeSize(int newSize)
{
    for (int i = 0; i < lines.size(); ++i)
    {
        lines[i]->changeShapeSize(newSize);
    }
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

void polyline::moveNode(int index, int offsetX, int offsetY)
{
    if (points[index].x() + offsetX < 0)
        points[index].setX(0);
    else if (points[index].x() + offsetX > 950)
        points[index].setX(950);
    else
        points[index].setX(points[index].x() +offsetX);

    if (points[index].y() + offsetY < 0)
        points[index].setY(0);
    else if (points[index].y() + offsetY > 450)
        points[index].setY(450);
    else
        points[index].setY(points[index].y() + offsetY);
}

int polyline::numberOfNodes() const
{
    return points.size();
}
