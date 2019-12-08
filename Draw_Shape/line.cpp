#include "line.h"

line::line() : line(100,50,100,100,10)
{

}

line::line(int shapeID, QPoint p1, QPoint p2)
{
    setShapeID(shapeID);
    this->p1 = p1;
    this->p2 = p2;
}

line::line(int shapeID, QPoint p1, QPoint p2, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin,
     std::string bColor, std::string bStyle)
    : line(shapeID, p1.x(), p1.y(), p2.x(), p2.y(), penColor, penWidth, penStyle, penCap, penJoin, bColor, bStyle)
{

}

line::line(int shapeID, int x1, int y1, int x2, int y2)
{
    setShapeID(shapeID);
    p1.setX(x1);
    p1.setY(y1);
    p2.setX(x2);
    p2.setY(y2);
}

line::line(int shapeID, int x1, int y1, int x2, int y2, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) : line(shapeID, x1, y1, x2, y2)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

line::line(int shapeID, int x1, int y1, int x2, int y2, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle)
 : line(shapeID, x1, y1, x2, y2)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
    setBrushColor(bColor);
    setBrushStyle(bStyle);
}

line::~line()
{}

void line::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawLine(p1,p2);
    getQPainter().end();
}

void line::moveShape(int offsetX, int offsetY)
{
    p1.setX(p1.x() + offsetX);
    p1.setY(p1.y() + offsetY);

    p2.setX(p2.x() + offsetX);
    p2.setY(p2.y() + offsetY);
}

const QPoint line::getP1() const
{
    return p1;
}

const QPoint line::getP2() const
{
    return p2;
}

double line::perimeter() const
{
    return 0;
}

double line::area() const
{
    return 0;
}
std::string line::getShapeType()
{
    return "Line";
}
