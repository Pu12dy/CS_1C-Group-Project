#ifndef SHAPE_H
#define SHAPE_H

//#include "text.h"
#include <QWidget>
#include <QPainter>

class shape
{
public:
    shape();
    ~shape();
    shape(const shape &source);

    QPainter& getQPainter();
    QPen& getQPen();
    QBrush& getQBrush();

    virtual void draw(QPaintDevice *toDraw) = 0;
//    virtual void move() = 0;// Moves the center of the shape
//    virtual int perimeter() = 0;// Calculates the perimeters
//    virtual double area() = 0;// Calculates the area
//    int getShapeID();
//    void setShapeID(int num);
//    void setPen(const QPen& pen);
//    void setBrush(const QBrush& brush);
//    void setText(const text& text);


    virtual void setPenColor(const QColor& color);
    virtual void setPenStyle(Qt::PenStyle style);
    virtual void setPenCapStyle(Qt::PenCapStyle style);
    virtual void setPenJoinStyle(Qt::PenJoinStyle style);

    virtual void setBrushColor(const QColor& color);
    virtual void setBrushStyle(Qt::BrushStyle style);


//    bool operator==(const shape &rightSide);
//    bool operator<(const shape &rightSide);
//    shape& operator=(const shape &rightSide);

private:
    int shapeID;
    QPainter painter;
    QPen pen;
    QBrush brush;


};

#endif // SHAPE_H
