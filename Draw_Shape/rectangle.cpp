#include "rectangle.h"

//!Default constructor for the rectangle class
rectangle::rectangle() : rectangle(99,400,30,100,150)
{

}
//!Alternate constructor for the rectangle class
rectangle::rectangle(int shapeID, int x, int y, int l, int w)
{
    setShapeID(shapeID);
    this->x = x;
    this->y = y;
    length = l;
    width = w;
}
//!Alternate constructor for the rectangle class
rectangle::rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin) :
    rectangle(shapeID, x, y, l, w)
{
    setPenColor(penColor);
    setPenWidth(penWidth);
    setPenStyle(penStyle);
    setPenCapStyle(penCap);
    setPenJoinStyle(penJoin);
}
//!Alternate constructor for the rectangle class
rectangle::rectangle(int shapeID, int x, int y, int l, int w, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle) :
    rectangle(shapeID, x, y,l,w)
{
    setPenColor(color);
    setPenWidth(penWidth);
    setPenStyle(pStyle);
    setPenCapStyle(pcStyle);
    setPenJoinStyle(pjStyle);
}
//!Alternate constructor for the rectangle class
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
//!Function overriden from the abstract base class shape. Used with QT to draw the shape.
void rectangle::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawRect(x,y,length,width);
    getQPainter().end();
}
//!Function overriden from the abstract base class shape.
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
//!Function overriden from the abstract base class shape.
void rectangle::changeShapeSize(int newSize)
{
    length += newSize;
    width  += newSize;
}
//!Function overriden from the abstract base class shape, returns perimeter of the object.
double rectangle::perimeter() const
{
    return (length * 2) + (width * 2);
}
//!Function overriden from the abstract base class shape, returns area of the object.
double rectangle::area() const
{
    return length * width;
}
//!Function overriden from the abstract base class shape, returns a string of the shape type.
std::string rectangle::getShapeType() const
{
    if (length == width)
    {
        return "Square";
    }
    return "Rectangle";

}
//!Function that will set the length equal to the width. Effectively creating square dimensions.
void rectangle::makeSquareOrCircle()
{
    width = length;
}
//!Function that returns the x and y coordinates of the shape to a string.
std::string rectangle::getXYCoords() const
{
    return std::to_string(x) + " " + std::to_string(y);
}
//!Function that returns the length and width of the shape to a string.
std::string rectangle::getLengthWidth() const
{
    return std::to_string(length) + " " + std::to_string(width);
}
