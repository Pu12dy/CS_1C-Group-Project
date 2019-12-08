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
    polygon(int shapeID, vector<QPoint> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    virtual ~polygon();
    void draw(QPaintDevice *toDraw) override;
    void moveShape(int offsetX, int offsetY) override;
    void changeShapeSize(int newSize) override;
    double perimeter() const override;
    double area() const override;
    std::string getShapeType();

private:
    vector<line*> lines;
};

#endif // POLYGON_H
