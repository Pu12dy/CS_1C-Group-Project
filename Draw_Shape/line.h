#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include <QPoint>
#include <string>

class line : public shape
{
public:
    line();
    line(int shapeID, Vector<QPoint*> points, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    line(int shapeID, int x1, int y1, int x2, int y2);
    virtual ~line() override;

    void draw(QPaintDevice *toDraw) override; // Draws the shape
    void moveShape(int offsetX, int offsetY) override;
    void changeShapeSize(int newSize) override;
    const QPoint getP1() const;
    const QPoint getP2() const;
    double perimeter() const override;// Calculates the perimeters
    double area() const override;// Calculates the area
    std::string getShapeType() const override;
    std::string getPoints() const override;
    int numberOfNodes() const override;
    void moveNode(int index, int offsetX, int offsetY) override;

private:
    Vector<QPoint*> points;

};

#endif // LINE_H
