#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "line.h"
#include <QPoint>

class polyline : public shape
{
public:
    polyline();
    polyline(int shapeID, int x1, int y1, int x2, int y2,
             int x3, int y3);

    void draw(QPaintDevice *toDraw);
    //    void move();// Moves the center of the shape
    //    int perimeter();// Calculates the perimeters
    //    double area();// Calculates the area

private:
    int shapeID;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    line *firstHalf;
    line *secondHalf;
};

#endif // POLYLINE_H
