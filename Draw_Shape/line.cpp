#include "line.h"

line::line() : line(0,0,100,10)
{

}

line::line(int x1, int y1, int x2, int y2)
{
    //setShapeID(shapeID);
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    p1.setX(x1);
    p1.setY(y1);
    p2.setX(x2);
    p2.setY(y2);

}

void line::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().drawLine(p1,p2);
    getQPainter().end();
}

