#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "line.h"
#include <QPoint>
#include "vector.h"

class polygon : public shape
{
public:
    polygon();
    polygon(int shapeID, vector<QPoint> p1);
    void draw(QPaintDevice *toDraw);
//  void move();  // Moves the center of the shape
private:
    vector<line*> lines;
};

#endif // POLYGON_H
