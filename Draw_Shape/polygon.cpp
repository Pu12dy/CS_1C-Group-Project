#include "polygon.h"

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
