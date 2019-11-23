#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
public:
    rectangle();
    rectangle(int x, int y, int l, int w);
    void draw(QPaintDevice *toDraw);

private:
    int x1;
    int y1;
    int length;
    int width;
};

#endif // RECTANGLE_H
