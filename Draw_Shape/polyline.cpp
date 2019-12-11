#include "polyline.h"

//!A constructor for the polyline class
//!Initializes a shape to be created specifically a polyline
//!creates new points of X and Y in order to form a polyline
//!Calls function QPoint within function points.push_back
polyline::polyline()
{
    setShapeID(116);
    //! Tester QPoints for polyline
    points.push_back(new QPoint(50, 150));
    points.push_back(new QPoint(100, 250));
    points.push_back(new QPoint(150, 150));
    points.push_back(new QPoint(200, 250));
}

//!A constructor for the polyline class
//!Two arguments passed no returning value
//!Arguments passed are of type int and type Vector
polyline::polyline(int shapeID, Vector<QPoint*> p1)
{
    setShapeID(shapeID);
    points = p1;
}
//!A constructor for the polyline class
//!polyline(int shapeID, Vector<QPoint*> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
/*!
There are nine arguments passed including the member initialization list which calls
polyline(shapeID, p1)
The areguments passed are of type int, Vector, string, int, string, string,
string, string, and string
*/
polyline::polyline(int shapeID, Vector<QPoint*> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
    : polyline(shapeID, p1)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

//!A destructor for the polyline class
//!Deletes all the points stored (existing polyline data)
polyline::~polyline()
{
    for(int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
}

//!A normal member function of the polyline class
//!void draw(QPaintDevice *toDraw)
//!A method that returns no data and one argument is passed of type QPaintDevice
//!Calls on vector class to create new points and store the data
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

//!A normal member function of the polyline class moveShape
//!This method has two argument passed of type int and no value returned
//!Method allow user to move a existing polyline shape using points X and Y
void polyline::moveShape(int offsetX, int offsetY)
{
    for(int i = 0; i < points.size(); ++i)
    {
       points[i]->setX(points[i]->x()+offsetX);
       points[i]->setY(points[i]->y()+offsetY);
    }
}

//!Method: void changeShapeSize(int newSize)
//!Method allows user to change shape size
//@Param Passed: int
//@return type: none
void polyline::changeShapeSize(int newSize)
{
    if (newSize > 0)
         {
             for (int i = 0; i < points.size(); ++i)
             {
                 points[i]->setX(points[i]->x() * (newSize/5));
                 points[i]->setY(points[i]->y() * (newSize/5));
              }
         }
         else
         {
             for (int i = 0; i < points.size(); ++i)
             {
                 points[i]->setX(points[i]->x() / qFabs(newSize / 5));
                 points[i]->setY(points[i]->y() / qFabs(newSize / 5));
             }
         }
}

//!Method name: double perimeter() const
//!Method calculates the perimeter of polyline
//@param Passed: none
//@return type: double
double polyline::perimeter() const
{
    return 0;
}

//!Method name: double area() const
//!Method calculates the area of a polyline
//@param Passed: none
//@return type: double
double polyline::area() const
{
    return 0;
}

//!A normal memeber function string getShapeType() const
//!A method that is a getter used to get the shape type "Polyline"
//!Method has no arguments passed and returns a value of type string
//!Returning value specified as "Polyline" and is constant
std::string polyline::getShapeType() const
{
    return "Polyline";
}

//!A normal memeber function void moveNode(int index, int offsetX, int offSetY)
//!A method that has three arguments of type int passed and returns no value
//!Allows user to move the shape polyline
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

//!A normal member function int numberOfNodes() const
//!This method has no arguments and returns a constant value of type int
//!Method calls on the size() function (specifically: points.size())
int polyline::numberOfNodes() const
{
    return points.size();
}

//!A normal memeber function void addNode(int index)
//!This method has one argument passed of type in and returns no value
//!Method calls on the insert() function
void polyline::addNode(int index)
{
    points.insert(&points[index], new QPoint(points[index]->x() + 10, points[index]->y() + 10));
}

//!A normal memeber function void removeNode(int index)
//!Function that removes nodes from an existing polyline shape
void polyline::removeNode(int index)
{
    points.erase(&points[index]);
}
//!A normal memeber function string getPoints() const
//!This method has no arguments passed and returns a value of type string
// @return string
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
