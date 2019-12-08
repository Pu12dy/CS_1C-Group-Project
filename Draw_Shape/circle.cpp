#include "circle.h"
/*
circle::circle() : circle(222,300,300,30)
{
    //shapeId = 222;
    //x1 = 90;
    //y1 = 90;
    //r = 30;
}

circle::circle(int shapeId, int x1, int y1, int r)
{
    setShapeID(shapeId);
    this->x1 = x1;
    this->y1 = y1;
    this->r = r;
}

circle::circle(int shapeId, int x1, int y1, int r, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) : circle(shapeId,x1,y1,r)

{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

circle::circle(int shapeID, int x, int y, int r, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle) :
    circle(shapeID, x, y, r)
{
    setPenColor(color);
    setPenWidth(penWidth);
    setPenStyle(pStyle);
    setPenCapStyle(pcStyle);
    setPenJoinStyle(pjStyle);
}

void circle::moveShape(int offsetX, int offsetY)
{
    x1 += offsetX;
    y1 += offsetY;
}

void circle::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawEllipse(QRect(x1,y1,r,r));
    getQPainter().end();
}*/
