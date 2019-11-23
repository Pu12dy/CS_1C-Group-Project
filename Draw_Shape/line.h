#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include <QPoint>

class line : public shape
{
public:
    line();
    line(int x1, int y1, int x2, int y2);

    void draw(QPaintDevice *toDraw); // Draws the shape
//    void move();// Moves the center of the shape
//    int perimeter();// Calculates the perimeters
//    double area();// Calculates the area

private:

    QPoint p1;
    QPoint p2;
    int x1;
    int y1;
    int x2;
    int y2;

};

#endif // LINE_H
