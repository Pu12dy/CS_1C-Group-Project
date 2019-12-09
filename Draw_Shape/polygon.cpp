#include "polygon.h"
#include <QLineF>
#include <QtMath>>

polygon::polygon()
{
    setShapeID(118);
    points.push_back(new QPoint(150, 250));
    points.push_back(new QPoint(200, 300));
    points.push_back(new QPoint(300, 275));
    points.push_back(new QPoint(200, 150));
}

polygon::polygon(int shapeID, Vector<QPoint*> p1)
{
   setShapeID(shapeID);
   points = p1;
}

polygon::polygon(int shapeID, Vector<QPoint*> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle)
    : polygon(shapeID, p1)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
    setBrushColor(bColor);
    setBrushStyle(bStyle);
}

polygon::~polygon()
{
    for(int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
}

void polygon::draw(QPaintDevice *toDraw)
{
    Vector <QPoint> newPoints;
    for(int i = 0; i < points.size(); ++i)
    {
        newPoints.push_back(*points[i]);
    }
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawPolygon(newPoints.getArrayFromVector(), newPoints.size());
    getQPainter().end();
}

void polygon::moveShape(int offsetX, int offsetY)
{
 for(int i = 0; i < points.size(); ++i)
 {
    points[i]->setX(points[i]->x()+offsetX);
    points[i]->setY(points[i]->y()+offsetY);
 }
}

double polygon::perimeter() const
{
 int result = 0;
 for(int i = 0; i < points.size()-1; ++i)
 {
     result += QLineF(points[i]->x(), points[i]->y(), points[i+1]->x(), points[i+1]->y()).length();
 }
 return result;
}

double polygon::area() const
{
// create array of x and y coordinates of each vertex in counterclockwise order
// repeat the coordinates of the first point in last element of array
// Multiply the x coordinate of each vertex by the y coordinate of the next vertex.
// Add the results.
// Multiply the y coordinate of each vertex by the x coordinate of the next vertex.
// Again, add these results
// Subtract the sum of the second products from the sum of the first products.
// Divide this difference by 2 to get the area of the polygon

double area = 0;
double total = 0;
double valOne = 0;
double valTwo = 0;
double valThree = 0;
double valFour = 0;

for (int i = 0; i <= lines.size() - 2; i++)
{
    int d = i + 1;
    valOne = QLineF(lines[i]->getP1(),lines[i]->getP2()).x1();
    valThree = QLineF(lines[i]->getP1(),lines[i]->getP2()).y1();

    for (int j = i; j < d; ++j)
    {
        valTwo = QLineF(lines[i]->getP1(),lines[i]->getP2()).y2();
        valFour = QLineF(lines[i]->getP1(),lines[i]->getP2()).x2();
    }
    total += ((valOne * valTwo) - (valThree * valFour));
}

return qFabs(total / 2);
}


std::string polygon::getShapeType() const
{
 return "Polygon";
}

void polygon::moveNode(int index, int offsetX, int offsetY)
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

int polygon::numberOfNodes() const
{
    return points.size();
}

void polygon::addNode(int index)
{
    points.insert(&points[index], new QPoint(points[index]->x() + 10, points[index]->y() + 10));
}
void polygon::removeNode(int index)
{
    points.erase(&points[index]);
}
std::string polygon::getPoints() const
{
    std::string returnString = "";
    returnString += std::to_string(numberOfNodes()) + "\n";//indicate number of nodes to read
    for (int i = 0; i < numberOfNodes(); i++)
    {
        returnString += std::to_string(points[i]->x()) + " " + std::to_string(points[i]->y()) + "\n";
    }
    return returnString;
}
void polygon::changeShapeSize(int newSize)
{

}
