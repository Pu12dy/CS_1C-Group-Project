#include "polygon.h"
#include <QLineF>
#include <QtMath>

polygon::polygon()
{
    setShapeID(117);
    // Tester QPoints for polyline
    vector<QPoint> p1;
    QPoint point;

    point.setX(150);
    point.setY(250);
    p1.push_back(point);

    point.setX(200);
    point.setY(300);
    p1.push_back(point);

    point.setX(300);
    point.setY(275);
    p1.push_back(point);

    point.setX(200);
    point.setY(150);
    p1.push_back(point);

    for (int i = 0; i < p1.size() - 1; ++i)
    {
        line *temp = new line(117, p1[i], p1[i + 1]);
        lines.push_back(temp);
    }
    line *temp = new line(117, p1[0], p1[p1.size() - 1]);
    lines.push_back(temp);
}

polygon::polygon(int shapeID, vector<QPoint> p1)
{
    setShapeID(shapeID);
    for (int i = 0; i < p1.size() - 1; ++i)
    {
        line *temp = new line(shapeID, p1[i], p1[i + 1]);
        lines.push_back(temp);
    }
    line *temp = new line(117, p1[0], p1[p1.size() - 1]);
    lines.push_back(temp);
}

polygon::polygon(int shapeID, vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin)
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
    for (int i = 0; i < lines.size(); ++i)
    {
        lines[i]->draw(toDraw);
    }
}

 void polygon::moveShape(int offsetX, int offsetY)
 {
     for (int i = 0; i < lines.size(); ++i)
     {
         lines[i]->moveShape(offsetX, offsetY);
     }
 }

 double polygon::perimeter() const
 {
     int result = 0;
     for (int i = 0; i < lines.size(); ++i)
     {
       result += QLineF(lines[i]->getP1(), lines[i]->getP2()).length();
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
 std::string polygon::getShapeType()
 {
     return "Polygon";
 }
