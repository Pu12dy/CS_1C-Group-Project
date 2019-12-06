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

void shape::setShapeID(int num)
{
    shapeID = num;
}

int shape::getShapeID()
{
    return shapeID;
}

//void shape::setPen(const QPen& pen)
//{
//    this->pen = pen;
//}

//void shape::setBrush(const QBrush& brush)
//{
//    this->brush = brush;
//}

//void shape::setText(const Text& text)
//{
//    this-text = text;
//}


void shape::setPenColor(std::string color){
    if(color == "white")
        pen.setColor(Qt::white);
    else if(color == "black")
        pen.setColor(Qt::black);
    else if(color == "red")
        pen.setColor(Qt::red);
    else if(color == "green")
        pen.setColor(Qt::green);
    else if(color == "blue")
        pen.setColor(Qt::blue);
    else if(color == "magenta")
        pen.setColor(Qt::magenta);
    else if(color == "yellow")
        pen.setColor(Qt::yellow);
    else if(color == "gray")
        pen.setColor(Qt::gray);
    else
        pen.setColor(Qt::black);
}

void shape::setPenColor(const QColor& color){
    pen.setColor(color);
}

void shape::setPenWidth(int penWidth){
    pen.setWidth(penWidth);
}

void shape::setPenStyle(std::string style){
    if(style == "solid line")
        pen.setStyle(Qt::SolidLine);
    else if(style == "no pen")
        pen.setStyle(Qt::NoPen);
    else if(style == "dash line")
        pen.setStyle(Qt::DashLine);
    else if(style == "dot line")
        pen.setStyle(Qt::DotLine);
    else if(style == "dash dot line")
        pen.setStyle(Qt::DashDotLine);
    else if(style == "dash dot dot line")
        pen.setStyle(Qt::DashDotDotLine);
    else
        pen.setStyle(Qt::SolidLine);
}

void shape::setPenStyle(Qt::PenStyle style){
    pen.setStyle(style);
}

void shape::setPenCapStyle(std::string style){
    if(style == "square cap")
        pen.setCapStyle(Qt::SquareCap);
    else if(style == "flat cap")
        pen.setCapStyle(Qt::FlatCap);
    else if(style == "round cap")
        pen.setCapStyle(Qt::RoundCap);
}

void shape::setPenCapStyle(Qt::PenCapStyle style){
    pen.setCapStyle(style);
}

void shape::setPenJoinStyle(std::string style){
    if(style == "bevel join")
        pen.setJoinStyle(Qt::BevelJoin);
    else if(style == "miter join")
        pen.setJoinStyle(Qt::MiterJoin);
    else if(style == "round join")
        pen.setJoinStyle(Qt::RoundJoin);
}

void shape::setPenJoinStyle(Qt::PenJoinStyle style){
    pen.setJoinStyle(style);
}

void shape::setBrushColor(std::string color){
    if(color == "white")
        brush.setColor(Qt::white);
    else if(color == "black")
        brush.setColor(Qt::black);
    else if(color == "red")
        brush.setColor(Qt::red);
    else if(color == "green")
        brush.setColor(Qt::green);
    else if(color == "blue")
        brush.setColor(Qt::blue);
    else if(color == "magenta")
        brush.setColor(Qt::magenta);
    else if(color == "yellow")
        brush.setColor(Qt::yellow);
    else if(color == "gray")
        brush.setColor(Qt::gray);
    else
        brush.setColor(Qt::black);
}

void shape::setBrushColor(const QColor& color){
    brush.setColor(color);
}

void shape::setBrushStyle(std::string style){
    if(style == "SolidPattern")
        brush.setStyle(Qt::SolidPattern);
    else if(style == "HorPattern")
        brush.setStyle(Qt::HorPattern);
    else if(style == "VerPattern")
        brush.setStyle(Qt::VerPattern);
    else
        brush.setStyle(Qt::NoBrush);
}

void shape::setBrushStyle(Qt::BrushStyle style){
    brush.setStyle(style);
}

void shape::setTextString(std::string text){}
void shape::setTextColor(std::string textColor) {}
void shape::setTextAlignment(std::string textAlign) {}
void shape::setTextPointSize(int textPointSize) {}
void shape::setTextFontFamily(std::string textFont) {}
void shape::setTextFontStyle(std::string textFStyle) {}
void shape::setTextFontWeight(std::string textFWeight) {}

