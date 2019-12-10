#include "polygon.h"
#include <QLineF>
#include <QtMath>>

//!A constructor for the polygon class
//!Initializes a shape to be created specifically a polygon
//!creates new points of X and Y in order to form a polygon
//!Calls function QPoint within function points.push_back
polygon::polygon()
{
    setShapeID(118);
    points.push_back(new QPoint(150, 250));
    points.push_back(new QPoint(200, 300));
    points.push_back(new QPoint(300, 275));
    points.push_back(new QPoint(200, 150));
}

//!A constructor for the polygon class
//!Two arguments passed no returning value
//! arguments passed are of type int and type Vector
polygon::polygon(int shapeID, Vector<QPoint*> p1)
{
   setShapeID(shapeID);
   points = p1;
}

//!A constructor for the polygon class
/*!
There are nine arguments passed including the member initialization list which calls
polygon(shapeID, p1)
The areguments passed are of type int, Vector, string, int, string, string,
string, string, and string
*/
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

//!A destructor for the polygon class
//!Deletes all the points stored (existing polygon data)
polygon::~polygon()
{
    for(int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
}
//!A normal member function of the polygon class
//!A method that returns no data and one argument is passed of type QPaintDevice
//!Calls on vector classs to create new points and store the data
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
//!A normal meember function of the polygon class moveShape
//!This method has two argument passed of type int and no value returned
//!Method allow user to move a existing polygon shape using points X and Y
void polygon::moveShape(int offsetX, int offsetY)
{
 for(int i = 0; i < points.size(); ++i)
 {
    points[i]->setX(points[i]->x()+offsetX);
    points[i]->setY(points[i]->y()+offsetY);
 }
}

//!Method name: perimeter() const
//!A regular memeber function that has no arguments and returns a value of type double
//!member function is const
//!Calculates the perimeter of an existing polygon for the user
double polygon::perimeter() const
{
 int result = 0;
 for(int i = 0; i < points.size()-1; ++i)
 {
     result += QLineF(points[i]->x(), points[i]->y(), points[i+1]->x(), points[i+1]->y()).length();
 }
 return result;
}

//!A regular memeber function that has no arguments and returns a value of type double
//!member function is const
//! create array of x and y coordinates of each vertex in counterclockwise order
//! repeat the coordinates of the first point in last element of array
//! Multiply the x coordinate of each vertex by the y coordinate of the next vertex.
//! Add the results.
//! Multiply the y coordinate of each vertex by the x coordinate of the next vertex.
//! Again, add these results
//! Subtract the sum of the second products from the sum of the first products.
//! Divide this difference by 2 to get the area of the polygon
double polygon::area() const
{


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


//!A normal memeber function string getShapeType() const
//!A method that is a getter used to get the shape type "Polygon"
//!Method has no arguments passed and returns a value of type string
//!Returning value specified as "Polygon" and is constant
std::string polygon::getShapeType() const
{
 return "Polygon";
}

//!A normal memeber function void moveNode(int index, int offsetX, int offSetY)
//!A method that has three arguments of type int passed and returns no value
//!Allows user to move the shape polygon
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

//!A normal member function int numberOfNodes() const
//!This method has no arguments and returns a constant value of type int
//!Method calls on the size() function (specifically: points.size())
int polygon::numberOfNodes() const
{
    return points.size();
}

//!A normal memeber function void addNode(int index)
//!This method has one argument passed of type in and returns no value
//!Method calls on the insert() function
void polygon::addNode(int index)
{
    points.insert(&points[index], new QPoint(points[index]->x() + 10, points[index]->y() + 10));
}
//!A normal memeber function void removeNode(int index)
//!Function that removes nodes from an existing polygon shape
void polygon::removeNode(int index)
{
    points.erase(&points[index]);
}

//!A normal memeber function string getPoints() const
//!This method has no arguments passed and returns a value of type string
// @return string
std::string polygon::getPoints() const
{
    std::string returnString = "";
    returnString += std::to_string(numberOfNodes()) + "\n";//!indicate number of nodes to read
    for (int i = 0; i < numberOfNodes(); i++)
    {
        returnString += std::to_string(points[i]->x()) + " " + std::to_string(points[i]->y()) + "\n";
    }
    return returnString;
}
//!A normal function method void changeShapeSize(int newSize)
//!Method that changes the size of polygon
void polygon::changeShapeSize(int newSize)
{
     if (newSize > 0)
     {
         for (int i = 0; i < points.size(); ++i)
         {
             points[i]->setX(points[i]->x() * (newSize / 5));
             points[i]->setY(points[i]->y() * (newSize / 5));

             //Ensuring shape does not move out of screen
             if (QLineF(*points[i],*points[i]).x1() < 0)
                 points[i]->setX(0);
             else if (QLineF(*points[i],*points[i]).x1() > 950)
                 points[i]->setX(950);
             if (QLineF(*points[i],*points[i]).y1() < 0)
                  points[i]->setY(0);
             else if (QLineF(*points[i],*points[i]).y1() > 450)
                 points[i]->setY(450);
          }
     }
     else
     {
         for (int i = 0; i < points.size(); ++i)
         {
             points[i]->setX(points[i]->x() / qFabs(newSize / 5));
             points[i]->setY(points[i]->y() / qFabs(newSize / 5));

             //Ensuring shape does not move out of screen
             if (QLineF(*points[i],*points[i]).x1() < 0)
                 points[i]->setX(0);
             else if (QLineF(*points[i],*points[i]).x1() > 950)
                 points[i]->setX(950);
             if (QLineF(*points[i],*points[i]).y1() < 0)
                  points[i]->setY(0);
             else if (QLineF(*points[i],*points[i]).y1() > 450)
                 points[i]->setY(450);
         }
     }
 }
