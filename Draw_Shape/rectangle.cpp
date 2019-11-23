#include "rectangle.h"

rectangle::rectangle() : rectangle(0,0,10,10)
{

}

rectangle::rectangle(int x, int y, int l, int w){
    x1 = x;
    y1 = y;
    length = l;
    width = w;

    setPenColor(Qt::blue);
    setBrushColor(Qt::green);
    setBrushStyle(Qt::SolidPattern);
}

void rectangle::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().setBrush(getQBrush());
    getQPainter().drawRect(x1,y1,length,width);
    getQPainter().end();
}
