#include "line.h"

line::line() : line(100,50,100,100,10)
{

}

line::line(int shapeID, int x1, int y1, int x2, int y2)
{
    setShapeID(shapeID);
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    p1.setX(x1);
    p1.setY(y1);
    p2.setX(x2);
    p2.setY(y2);

}

line::line(int shapeID, int x1, int y1, int x2, int y2, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) : line(shapeID, x1, y1, x2, y2)
{
    const char* penCol = penColor.c_str();
    qDebug() << penCol;

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

line::line(int shapeID, QPoint p1, QPoint p2)
{
	setShapeID(shapeID);
	this->p1 = p1;
	this->p2 = p2;
}

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

