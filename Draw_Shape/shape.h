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

	//!Function to access QPainter 
    QPainter& getQPainter();
	//!Function to access QPen
    QPen& getQPen();
	//!Function to access QBrush
    QBrush& getQBrush();
	//!Function to access QFont
    QFont& getQFont();

	//!virtual draw function to be overloaded in the derived classes 
    virtual void draw(QPaintDevice *toDraw) = 0;
	//!virtual function to calculate perimeter of shape, to be overloaded in derived classes
    virtual double perimeter() const = 0 ;// Calculates the perimeters
	//!virtual function to calculate area of shape, to be overloaded in derived classes
    virtual double area() const = 0;// Calculates the area
	//!Function that returns the type of derived shape as std::string
    virtual std::string getShapeType() const = 0;
	//!Function that return shape name as std::string
    std::string getShapeName() const;
	//!Function to set ID for this shape
    void setShapeID(int num);
	//!Function that returns ID of this shape as int
    int getShapeID() const;
	//!Function that returns ID of this shape as std::string
    std::string getID() const;

	//!Function to move shape by certain x and y offset. To be overloaded in derived classes. 
    virtual void moveShape(int offsetX, int offsetY) = 0;
	//!Function to change shape size by a scalar. 
    virtual void changeShapeSize(int newSize) = 0;

	//!Function that takes std::string and set the pen color based on input.
    virtual void setPenColor(std::string color);
	//!Function to set pen color. 
    virtual void setPenColor(const QColor& color);

	//!Function to set pen width
    virtual void setPenWidth(int penWidth);

	//!Functions to set pen style
    virtual void setPenStyle(std::string style);
    virtual void setPenStyle(Qt::PenStyle style);

	//!Functions to set pen cap style
    virtual void setPenCapStyle(std::string style);
    virtual void setPenCapStyle(Qt::PenCapStyle style);

	//!Functions to set pen join Style
    virtual void setPenJoinStyle(std::string style);
    virtual void setPenJoinStyle(Qt::PenJoinStyle style);

	//!Functions to set brush color
    virtual void setBrushColor(std::string color);
    virtual void setBrushColor(const QColor& color);

	//!Functions to set brush style
    virtual void setBrushStyle(std::string style);
    virtual void setBrushStyle(Qt::BrushStyle style);
	//!Function to set text string for text class
    virtual void setTextString(std::string text);
	//!Function to set text color for text class
    virtual void setTextColor(std::string textColor);
	//!Function that return QT::AlignmentFlag enum from corresponding std::string
    Qt::AlignmentFlag setTextAlign(std::string textAlign);
	//!Function to set textAlignment 
    virtual void setTextAlignment(std::string textAlign);
	//!Function to set textPointSize for text class
    virtual void setTextPointSize(int textPointSize);
	//!Function to set textFontFamily for text class
    virtual void setTextFontFamily(std::string textFont);
	//!Function to set textFontStyle for text class
    virtual void setTextFontStyle(std::string textFStyle);
	//!Function to set textFontWeight for text class
    virtual void setTextFontWeight(std::string textFWeight);


	//!Function to make square or circle
    virtual void makeSquareOrCircle();
	//!Function to move a node in polyline, polygon, or line
    virtual void moveNode(int index, int offsetX, int offSetY);
	//!Function that returns number of nodes in polyline or polygon
    virtual int numberOfNodes() const;
	//!Function to add a node in polygon or polyline
    virtual void addNode(int index);
	//!Function to remove a node in polygon or polyline
    virtual void removeNode(int index);

	//!Function that returns the textString from text class
    virtual std::string getTextString() const;
	//!Function that returns the textColorString state as std::string
    std::string getTextColorString() const;
	//!Function that returns textAlignmentString state as std::string
    virtual std::string getTextAlignmentString() const;
	//!Function that returns textPointSize state as std::string
    std::string getTextPointSize() const;
	//!Function that returns textFontFamily state as std::string
    std::string getTextFontFamilyString() const;
	//!Function that returns textFontStyle state as std::string
    std::string getTextFontStyleString() const;
	//!Function that returns textFontWeight state as std::string
    std::string getTextFontWeightString() const;
	//!Function that returns xy coordinate as std::string
    virtual std::string getXYCoords() const;
	//!Function that returns length and width as std::string
    virtual std::string getLengthWidth() const;
	//!Function that returns points as std::string
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
