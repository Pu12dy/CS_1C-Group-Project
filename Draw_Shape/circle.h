#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QPoint>
#include <string>

class circle : public shape
{
private:
    int x1;
    int y1;
    int r; // radius
    int shapeId;

public:
    circle();
    circle(int shapeId, int x1, int y1, int r);
    circle(int shapeId, int x1, int y1, int r, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    circle(int shapeId, int x, int y, int r, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle);


    void draw(QPaintDevice *toDraw); // Draws the shape
    void moveShape(int offsetX, int offsetY); // Moves the center of the shape
    //int perimeter(); // Calculates the perimeters
    double area();	 // Calculates the area (PI * a * b = area)
};

#endif // CIRCLE_H
