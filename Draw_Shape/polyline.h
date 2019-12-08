#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "line.h"
#include <QPoint>
#include "vector.h"

class polyline : public shape
{
public:
    polyline();
    polyline(int shapeID, vector<QPoint> p1);
    polyline(int shapeID, vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    virtual ~polyline();
    void draw(QPaintDevice *toDraw);
    void moveShape(int offsetX, int offsetY);
    int perimeter() const; // Calculates the perimeters
    double area() const;// Calculates the area

private:
    vector<line*> lines;
};

#endif // POLYLINE_H
