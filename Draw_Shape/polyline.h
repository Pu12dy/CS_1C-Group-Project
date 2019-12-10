#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "line.h"
#include <QPoint>
#include <QLineF>
#include <QtMath>
#include "vector.h"

class polyline : public shape
{
public:
    polyline();
    polyline(int shapeID, Vector<QPoint*> p1);

    // Matt use this constructor in parser
    polyline(int shapeID, Vector<QPoint*> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    virtual ~polyline() override;
    void draw(QPaintDevice *toDraw) override;
    void moveShape(int offsetX, int offsetY) override;
    void changeShapeSize(int newSize) override;
    double perimeter() const override; // Calculates the perimeters
    double area() const override;// Calculates the area
    std::string getShapeType() const override;
    void moveNode(int index, int offsetX, int offsetY) override;
    int numberOfNodes() const override;
    void addNode(int index) override;
    void removeNode(int index) override;
    std::string getPoints() const override;

private:
    Vector<line*> lines;
    Vector<QPoint*> points;
};

#endif // POLYLINE_H
