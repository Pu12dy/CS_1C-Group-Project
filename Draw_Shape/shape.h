#ifndef SHAPE_H
#define SHAPE_H

//#include "text.h"
#include <QWidget>
#include <QPainter>
#include <string>
#include <QDebug>
#include <QKeyEvent>

class shape
{
public:
    shape();
    virtual ~shape();
    shape(const shape &source);

    QPainter& getQPainter();
    QPen& getQPen();
    QBrush& getQBrush();
    QFont& getQFont();


    virtual void draw(QPaintDevice *toDraw) = 0;
    virtual double perimeter() const = 0 ;// Calculates the perimeters
    virtual double area() const = 0;// Calculates the area
    virtual std::string getShapeType() const = 0;
    std::string getShapeName() const;
    void setShapeID(int num);
    int getShapeID() const;
    std::string getID() const;
//    void setPen(const QPen& pen);
//    void setBrush(const QBrush& brush);
//    void setText(const text& text);
    virtual void moveShape(int offsetX, int offsetY) = 0;

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

    virtual void setFontProperties(std::string textFont, std::string textFStyle, std::string textFWeight);
    virtual void setTextString(std::string text);
    virtual void setTextColor(std::string textColor);
    Qt::AlignmentFlag setTextAlign(std::string textAlign);
    //virtual void setTextAlignment(std::string textAlign);
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
    QFont tFont;

protected:

};

#endif // SHAPE_H
