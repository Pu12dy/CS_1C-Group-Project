#include "line.h"

//!line class constructor
//!Creates a default line
line::line() : line(100,50,100,100,10)
{

}

//! An alternate line class constructor
//! line(int shapeID, Vector<QPoint*> points, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
//!There are seven varibles passed of type int, Vector, string, int, string, string, and string
//!This constructor uses setters to update pen color, style, width, capstyle, joinstyle, and shape Id
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

//!An alternater line class constructor
//!line(int shapeID, int x1, int y1, int x2, int y2)
//!There are five variable passed all of type int
//!This constructor creates new points (x1, y1) and (x2, y2)
line::line(int shapeID, int x1, int y1, int x2, int y2)
{
    setShapeID(shapeID);
    points.push_back(new QPoint(x1, y1));
    points.push_back(new QPoint(x2, y2));
}
//!A destructor for the line class
//!deletes all points stored (existing line data)
line::~line()
{
    for (int i = 0; i < points.size(); i++)
    {
        delete points[i];
    }
}

//!void draw(QPaintDevice *toDraw)
//!Method passes an argument of type QPaintDevice pointer toDraw
//!returns no value
//!Allows the line to be drawn.
void line::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawLine(*points[0], *points[1]);
    getQPainter().end();
}

//!void moveShape(int offsetX, int offsetY)
//!Method allows the line shape to move by manipulating the X and Y values
//!Method passes two arguments of type int and returns no value
void line::moveShape(int offsetX, int offsetY)
{
    for (int i = 0; i < points.size(); i++)
    {
        points[i]->setX(points[i]->x() + offsetX);
        points[i]->setY(points[i]->y() + offsetY);
    }
}
//!void changeShapeSize(int newSize)
//!method allows the lines size to be changed
void line::changeShapeSize(int newSize)
{

}

//! const Qpoint getP1() const
// @param  Passed: none
// @return type: QPoint
const QPoint line::getP1() const
{
    return *points[0];
}

//! const Qpoint getP2() const
// @param  Passed: none
// @return type: QPoint
const QPoint line::getP2() const
{
    return *points[1];
}

//!double perimeter()const
//!Method calculates the perimeter of the line
// @param Passed: none
// @return type: double
double line::perimeter() const
{
    return 0;
}

//!double area() const
//!Method calculates the area of the line
// @param Passed: none
// @return type: double
double line::area() const
{
    return 0;
}

//!string getShapeType() const
//!Method constant getter that gets shape type "Line"
// @param Passed: none
// @return type: string
std::string line::getShapeType() const
{
    return "Line";
}

//!string getPoints() const
//!Method that gets the points of the line
// @param Passed: none
// @return type: string
std::string line::getPoints() const
{
    std::string returnString = "";
    returnString += "2\n";//!indicate number of nodes to read
    for (int i = 0; i < 2; i++)
    {
        returnString += std::to_string(points[i]->x()) + " " + std::to_string(points[i]->y()) + "\n";
    }
    return returnString;
}

//!int numberOfNodes() const
//!Method that counts number of nodes two too perserve shape
// @param Passed: none
// @return type: int
int line::numberOfNodes() const
{
    return 2;
}

//!void moveNode(int index, int offsetX, int offsetY)
//!Method that moves the nodes of a line
// @param Passed: int, int, int
// @return type: none
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
