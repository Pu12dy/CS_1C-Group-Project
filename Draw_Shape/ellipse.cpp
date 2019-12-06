#include "ellipse.h"

Ellipse::Ellipse() : Ellipse(131,100,100,200,30)
{

}

Ellipse::Ellipse(int shapeID,int x1, int y1, int a, int b)
{
    setShapeID(shapeID);
    this->x1 = x1;
    this->y1 = y1;
    this->a = a;
    this->b = b;
}
Ellipse::Ellipse(int shapeId, int x1, int y1, int a, int b,
        std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) : Ellipse(shapeId,x1,y1,a,b)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

void Ellipse::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawEllipse(QRect(x1,y1,a,b));
    getQPainter().end();
}

double Ellipse::area()
{
    return PI * a * b;
}
