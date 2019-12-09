#include "line.h"

line::line() : line(100,50,100,100,10)
{

}

line::line(int shapeID, Vector<QPoint*> points, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
{
    setShapeID(shapeID);
    this->points = points;
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

line::line(int shapeID, int x1, int y1, int x2, int y2)
{
    setShapeID(shapeID);
    points.push_back(new QPoint(x1, y1));
    points.push_back(new QPoint(x2, y2));
}

line::~line()
{
    for (int i = 0; i < points.size(); i++)
    {
        delete points[i];
    }

}

void line::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawLine(*points[0], *points[1]);
    getQPainter().end();
}

void line::moveShape(int offsetX, int offsetY)
{
    for (int i = 0; i < points.size(); i++)
    {
        points[i]->setX(points[i]->x() + offsetX);
        points[i]->setY(points[i]->y() + offsetY);
    }
}

void line::changeShapeSize(int newSize)
{

}

const QPoint line::getP1() const
{
    return *points[0];
}

const QPoint line::getP2() const
{
    return *points[1];
}

double line::perimeter() const
{
    return 0;
}

double line::area() const
{
    return 0;
}
std::string line::getShapeType() const
{
    return "Line";
}
std::string line::getPoints() const
{
    std::string returnString = "";
    returnString += "2\n";//indicate number of nodes to read
    for (int i = 0; i < 2; i++)
    {
        returnString += std::to_string(points[i]->x()) + " " + std::to_string(points[i]->y()) + "\n";
    }
    return returnString;
}

int line::numberOfNodes() const
{
    return 2;
}

void line::moveNode(int index, int offsetX, int offsetY)
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
