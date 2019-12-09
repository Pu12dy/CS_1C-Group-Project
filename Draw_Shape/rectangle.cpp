#include "rectangle.h"

rectangle::rectangle() : rectangle(99,400,30,100,150)
{

}

rectangle::rectangle(int shapeID, int x, int y, int l, int w)
{
    setShapeID(shapeID);
    this->x = x;
    this->y = y;
    length = l;
    width = w;

//    setPenColor(Qt::black);
//    setBrushColor(Qt::red);
//    setBrushStyle(Qt::SolidPattern);
}

rectangle::rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) :
    rectangle(shapeID, x, y, l, w)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}

rectangle::rectangle(int shapeID, int x, int y, int l, int w, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle) :
    rectangle(shapeID, x, y,l,w)
{
    setPenColor(color);
    setPenWidth(penWidth);
    setPenStyle(pStyle);
    setPenCapStyle(pcStyle);
    setPenJoinStyle(pjStyle);
}

rectangle::rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle) :
    rectangle(shapeID, x, y, l, w)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
    setBrushColor(bColor);
    setBrushStyle(bStyle);
}

void rectangle::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawRect(x,y,length,width);
    getQPainter().end();
}

void rectangle::moveShape(int offsetX, int offsetY)
{
    x += offsetX;
    y += offsetY;

    //Ensuring shape does not move out of screen
    if (x < 0)
        x = 0;
    else if (x > 950)
        x = 950;
    if (y < 0)
        y = 0;
    else if (y > 450)
        y = 450;
}

void rectangle::changeShapeSize(int newSize)
{
    length += newSize;
    width  += newSize;
}

double rectangle::perimeter() const
{
    return (length * 2) + (width * 2);
}

double rectangle::area() const
{
    return length * width;
}

std::string rectangle::getShapeType() const
{
    if (length == width)
    {
        return "Square";
    }
    return "Rectangle";

}

void rectangle::makeSquareOrCircle()
{
    width = length;
}
