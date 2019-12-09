#include "polyline.h"

polyline::polyline()
{
    setShapeID(116);
    // Tester QPoints for polyline
    points.push_back(new QPoint(50, 150));
    points.push_back(new QPoint(100, 250));
    points.push_back(new QPoint(150, 150));
    points.push_back(new QPoint(200, 250));
}

polyline::polyline(int shapeID, Vector<QPoint*> p1)
{
    setShapeID(shapeID);
    points = p1;
}

polyline::polyline(int shapeID, Vector<QPoint*> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
    : polyline(shapeID, p1)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

polyline::~polyline()
{
    for(int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
}

void polyline::draw(QPaintDevice *toDraw)
{
    Vector <QPoint> newPoints;
    for(int i = 0; i < points.size(); ++i)
    {
        newPoints.push_back(*points[i]);
    }
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().drawPolyline(newPoints.getArrayFromVector(), newPoints.size());
    getQPainter().end();
}


void polyline::moveShape(int offsetX, int offsetY)
{
    for(int i = 0; i < points.size(); ++i)
    {
       points[i]->setX(points[i]->x()+offsetX);
       points[i]->setY(points[i]->y()+offsetY);
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
    if (points[index]->x() + offsetX < 0)
        points[index]->setX(0);
    else if (points[index]->x() + offsetX > 950)
        points[index]->setX(950);
    else
        points[index]->setX(points[index]->x() +offsetX);

    if (points[index]->y() + offsetY < 0)
        points[index]->setY(0);
    else if (points[index]->y() + offsetY > 450)
        points[index]->setY(450);
    else
        points[index]->setY(points[index]->y() + offsetY);
}

int polyline::numberOfNodes() const
{
    return points.size();
}

void polyline::addNode(int index)
{
    points.insert(&points[index], new QPoint(points[index]->x() + 10, points[index]->y() + 10));
}

void polyline::removeNode(int index)
{
    points.erase(&points[index]);
}
std::string polyline::getPoints() const
{
    std::string returnString = "";
    returnString += std::to_string(numberOfNodes()) + "\n";//indicate number of nodes to read
    for (int i = 0; i < numberOfNodes(); i++)
    {
        returnString += std::to_string(points[i]->x()) + " " + std::to_string(points[i]->y()) + "\n";
    }
    return returnString;
}
