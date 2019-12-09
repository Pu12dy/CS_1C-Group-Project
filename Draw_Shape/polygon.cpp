#include "polygon.h"
#include <QLineF>
#include <QtMath>>

polygon::polygon()
{
    setShapeID(118);
    QPoint point;

    point.setX(150);
    point.setY(250);
    points.push_back(point);

    point.setX(200);
    point.setY(300);
    points.push_back(point);

    point.setX(300);
    point.setY(275);
    points.push_back(point);


    point.setX(200);
    point.setY(150);
    points.push_back(point);
}

polygon::polygon(int shapeID, Vector<QPoint> p1)
{
   setShapeID(shapeID);
   points = p1;
}

polygon::polygon(int shapeID, Vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
    : polygon(shapeID, p1)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

polygon::~polygon(){}

void polygon::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawPolygon(points.getArrayFromVector(), points.size());
    getQPainter().end();
}

 void polygon::moveShape(int offsetX, int offsetY)
 {
     for(int i = 0; i < points.size(); ++i)
     {
        points[i].setX(points[i].x()+offsetX);
        points[i].setY(points[i].y()+offsetY);
     }
 }

 void polygon::changeShapeSize(int newSize)
 {
//     for (int i = 0; i < lines.size(); ++i)
//     {
//         lines[i]->changeShapeSize(newSize);
//     }

 }

 double polygon::perimeter() const
 {
     int result = 0;
//     for (int i = 0; i < lines.size(); ++i)
//     {
//       result += QLineF(lines[i]->getP1(), lines[i]->getP2()).length();
//     }
//     return result;
     for(int i = 0; i < points.size()-1; ++i)
     {

//         QPoint p1(points[i]);
//         QPoint p2(points[i+1]);
         //result += QLineF(p1,p2).length();
         result += QLineF(points[i], points[i+1]).length();
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

//    double area = 0;
//    double total = 0;
//    double valOne = 0;
//    double valTwo = 0;
//    double valThree = 0;
//    double valFour = 0;

//    for (int i = 0; i <= lines.size() - 2; i++)
//    {
//        int d = i + 1;
//        valOne = QLineF(lines[i]->getP1(),lines[i]->getP2()).x1();
//        valThree = QLineF(lines[i]->getP1(),lines[i]->getP2()).y1();

//        for (int j = i; j < d; ++j)
//        {
//            valTwo = QLineF(lines[i]->getP1(),lines[i]->getP2()).y2();
//            valFour = QLineF(lines[i]->getP1(),lines[i]->getP2()).x2();
//        }
//        total += ((valOne * valTwo) - (valThree * valFour));
//    }

   // return qFabs(total / 2);
    return 0;
 }


 std::string polygon::getShapeType() const
 {
     return "Polygon";
 }
