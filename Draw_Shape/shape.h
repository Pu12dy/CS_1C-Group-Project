#ifndef SHAPE_H
#define SHAPE_H

//#include "text.h"
#include <QWidget>
#include <QPainter>
#include <string>
#include "vector.h"
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

    virtual void moveShape(int offsetX, int offsetY) = 0;
    virtual void changeShapeSize(int newSize) = 0;

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
    Qt::AlignmentFlag setTextAlign(std::string textAlign);
    virtual void setTextAlignment(std::string textAlign);
    virtual void setTextPointSize(int textPointSize);
    virtual void setTextFontFamily(std::string textFont);
    virtual void setTextFontStyle(std::string textFStyle);
    virtual void setTextFontWeight(std::string textFWeight);
    virtual void makeSquareOrCircle();
    virtual void moveNode(int index, int offsetX, int offSetY);
    virtual int numberOfNodes() const;
    virtual void addNode(int index);
    virtual void removeNode(int index);

    virtual std::string getTextString() const;
    std::string getTextColorString() const;
    virtual std::string getTextAlignmentString() const;
    std::string getTextPointSize() const;
    std::string getTextFontFamilyString() const;
    std::string getTextFontStyleString() const;
    std::string getTextFontWeightString() const;
    virtual std::string getXYCoords() const;
    virtual std::string getLengthWidth() const;
    virtual std::string getPoints() const;

private:
    int shapeID;
    QPainter painter;
    QPen pen;
    QBrush brush;
    QFont tFont;

// For saving shapes purposes
    std::string textColor;
    std::string textAlignment;
    std::string textFontStyle;

protected:

};

#endif // SHAPE_H
