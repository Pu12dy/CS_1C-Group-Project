#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QWidget>

// Need to include Qt
// Base class Shape

class Shape
{
private:
    int shapeID;
    QPainter qObject;
    QPen pen;
    QBrush brush;

public:
    Shape();// Default Constructor
    ~Shape();// Destructor

    Shape(const Shape &source);
    virtual void draw() = 0;// Draws the shape
    virtual void move() = 0;// Moves the center of the shape
    virtual int perimeter() = 0;// Calculates the perimeters
    virtual double area() = 0;// Calculates the area
    int getShapeID();
    void setShapeID(int num);
    void setPen(const QPen& pen);
    void setBrush(const QBrush& brush);
    void setText(const Text& text);


    bool operator==(const Shape &rightSide);
    bool operator<(const Shape &rightSide);
    Shape& operator=(const Shape &rightSide);
};

#endif
