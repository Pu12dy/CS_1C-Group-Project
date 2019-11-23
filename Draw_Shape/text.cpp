#include "text.h"

text::text() : text("default")
{

}

text::text(const char *str){
    this->str = new QString(str);
    setPenColor(Qt::red);
}

void text::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().drawText(50,50,*str);
    getQPainter().end();
}
