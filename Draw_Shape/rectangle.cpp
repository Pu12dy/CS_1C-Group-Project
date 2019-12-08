#include "rectangle.h"

rectangle::rectangle() : rectangle(99,400,30,100,150)
{

}

rectangle::rectangle(int shapeID, int x, int y, int l, int w)
{
    setShapeID(shapeID);
    x1 = x;
    y1 = y;
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
    getQPainter().drawRect(x1,y1,length,width);
    getQPainter().end();
}

void rectangle::moveShape(int offsetX, int offsetY)
{
    x1 += offsetX;
    y1 += offsetY;
}

double rectangle::perimeter() const
{
    return (length * 2) + (width * 2);
}

double rectangle::area() const
{
    return length * width;
}

std::string rectangle::getShapeType()
{
    return "Rectangle";
}

char rectangle::getShapeCharIdentifier()
{
    return 'R';
}

std::string rectangle::getXYCoords()
{
    std::string coords = std::to_string(this->x1);
    coords.append(" ");
    coords.append(std::to_string(this->y1));
    coords.append(" ");
    coords.append(std::to_string(this->length));
    coords.append(" ");
    coords.append(std::to_string(this->width));
    coords.append("\n");

    return coords;
}
