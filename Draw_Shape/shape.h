#ifndef SHAPE_H
#define SHAPE_H

//#include "text.h"
#include <QWidget>
#include <QPainter>
#include <string>
#include <QDebug>

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
    void setShapeID(int num);
    int getShapeID();
//    void setPen(const QPen& pen);
//    void setBrush(const QBrush& brush);
//    void setText(const text& text);

    virtual void moveShape(QPoint offsetX, QPoint offsetY);
    virtual void moveShape(int offsetX, int offsetY);

    virtual void setPenColor(std::string color);
    virtual void setPenColor(const QColor& color);

    virtual void setPenWidth(int penWidth);

    virtual void setPenStyle(std::string style);
    virtual void setPenStyle(Qt::PenStyle style);

    virtual void setPenCapStyle(std::string style);
    virtual void setPenCapStyle(Qt::PenCapStyle style);

    virtual void setPenJoinStyle(std::string style);
    virtual void setPenJoinStyle(Qt::PenJoinStyle style);

    virtual void setBrushColor(std::string color);
    virtual void setBrushColor(const QColor& color);

    virtual void setBrushStyle(std::string style);
    virtual void setBrushStyle(Qt::BrushStyle style);

    virtual void setTextString(std::string text);
    virtual void setTextColor(std::string textColor);
    virtual void setTextAlignment(std::string textAlign);
    virtual void setTextPointSize(int textPointSize);
    virtual void setTextFontFamily(std::string textFont);
    virtual void setTextFontStyle(std::string textFStyle);
    virtual void setTextFontWeight(std::string textFWeight);

//    bool operator==(const shape &rightSide);
//    bool operator<(const shape &rightSide);
//    shape& operator=(const shape &rightSide);

private:
    int shapeID;
    QPainter painter;
    QPen pen;
    QBrush brush;

protected:
    std::string textString;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlignment;
    int textPointSize;
    std::string textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;
};

#endif // SHAPE_H