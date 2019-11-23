#include "shape.h"

shape::shape()
{
    shapeID = 101;
}

shape::~shape()
{

}

shape::shape(const shape &source)
{

}


QPainter& shape::getQPainter()
{
    return painter;
}

QPen& shape::getQPen()
{
    return pen;
}

QBrush& shape::getQBrush()
{
    return brush;
}



void shape::draw(QPaintDevice *toDraw)
{

}


//int Shape::getShapeID() // Returns shapeID
//{
//    return shapeID;
//}

//void setShapeID(int num)
//{
//    shapeID = num;
//}

//void setPen(const QPen& pen)
//{
//    this->pen = pen;
//}

//void setBrush(const QBrush& brush)
//{
//    this->brush = brush;
//}

//void setText(const Text& text)
//{
//    this-text = text;
//}


void shape::setPenColor(const QColor& color){
    pen.setColor(color);
}

void shape::setPenStyle(Qt::PenStyle style){
    pen.setStyle(style);
}

void shape::setPenCapStyle(Qt::PenCapStyle style){
    pen.setCapStyle(style);
}

void shape::setPenJoinStyle(Qt::PenJoinStyle style){
    pen.setJoinStyle(style);
}

void shape::setBrushColor(const QColor& color){
    brush.setColor(color);
}

void shape::setBrushStyle(Qt::BrushStyle style){
    brush.setStyle(style);
}
