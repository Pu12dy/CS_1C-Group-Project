#include "polyline.h"

polyline::polyline()
{
    setShapeID(116);
    // Tester QPoints for polyline
    vector<QPoint> p1;
    QPoint point;

    point.setX(50);
    point.setY(150);
    p1.push_back(point);

    point.setX(100);
    point.setY(250);
    p1.push_back(point);

    point.setX(150);
    point.setY(150);
    p1.push_back(point);

    point.setX(200);
    point.setY(250);
    p1.push_back(point);

    for (int i = 0; i < p1.size() - 1; ++i)
    {
        line *temp = new line(116, p1[i], p1[i + 1]);
        lines.push_back(temp);
    }
}

polyline::polyline(int shapeID, vector<QPoint> p1)
{
    setShapeID(shapeID);
    for (int i = 0; i < p1.size() - 1; ++i)
    {
        line *temp = new line(shapeID, p1[i], p1[i + 1]);
        lines.push_back(temp);
    }
}

polyline::polyline(int shapeID, vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
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
    for (int i = 0; i < lines.size(); ++i)
    {
        lines[i]->draw(toDraw);
    }
}


void polyline::moveShape(int offsetX, int offsetY)
{
    for (int i = 0; i < lines.size(); ++i)
    {
        lines[i]->moveShape(offsetX, offsetY);
    }
}

int polyline::perimeter() const
{
    return 0;
}

double polyline::area() const
{
    return 0;
}
