#include "ellipse.h"
#include <math.h>

ellipse::ellipse() : ellipse(131,100,100,200,30)
{

}

ellipse::ellipse(int shapeID,int x, int y, int a, int b)
{
    setShapeID(shapeID);
    this->x = x;
    this->y = y;
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
ellipse::ellipse(int shapeId, int x, int y, int a, int b, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle)
    :ellipse(shapeId, x, y, a, b, penColor, penWidth, penStyle, penCap, penJoin)
{
    setBrushColor(bColor);
    setBrushStyle(bStyle);
}

ellipse::~ellipse(){}

void ellipse::draw(QPaintDevice *toDraw)
{
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawEllipse(QRect(x,y,a,b));
    getQPainter().end();
}

void ellipse::moveShape(int offsetX, int offsetY)
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

void ellipse::changeShapeSize(int newSize)
{
    a += newSize;
    b += newSize;
}

double ellipse::perimeter() const
{
    return ((2 * PI) * sqrt(pow(a,2) + pow(b,2) / 2));
}

double ellipse::area() const
{
    return PI * a * b;
}

std::string ellipse::getShapeType() const
{
    if (a == b)
    {
        return "Circle";
    }
    return "Ellipse";
}

void ellipse::makeSquareOrCircle()
{
    b = a;
}

std::string ellipse::getXYCoords() const
{
    return std::to_string(x) + " " + std::to_string(y);
}

std::string ellipse::getLengthWidth() const
{
    return std::to_string(a) + " " + std::to_string(b);
}
