#include "ellipse.h"

ellipse::ellipse() : ellipse(131,100,100,200,30)
{

}

ellipse::ellipse(int shapeID,int x1, int y1, int a, int b)
{
    setShapeID(shapeID);
    this->x1 = x1;
    this->y1 = y1;
    this->a = a;
    this->b = b;
}
ellipse::ellipse(int shapeId, int x1, int y1, int a, int b,
        std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) : ellipse(shapeId,x1,y1,a,b)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

ellipse::ellipse(int shapeID, int x, int y, int a, int b, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle) :
    ellipse(shapeID, x, y, a, b)
{
    setPenColor(color);
    setPenWidth(penWidth);
    setPenStyle(pStyle);
    setPenCapStyle(pcStyle);
    setPenJoinStyle(pjStyle);
}

ellipse::~ellipse(){}

void ellipse::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawEllipse(QRect(x1,y1,a,b));
    getQPainter().end();
}

void ellipse::moveShape(int offsetX, int offsetY)
{
    x1 += offsetX;
    y1 += offsetY;
}

double ellipse::area()
{
    return PI * a * b;
}
