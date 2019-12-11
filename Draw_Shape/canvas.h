#ifndef CANVAS_H
#define CANVAS_H

#include <algorithm>
#include <QWidget>
#include <QDebug>
#include <QString>
#include "shapeParser.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "text.h"
#include "vector.h"
#include "ellipse.h"
#include "polyline.h"
#include "polygon.h"
#include "extraCredit.h"
#include <QMessageBox>

class canvas : public QWidget
{
    Q_OBJECT
public:


    //! canvas(QWidget *parent)
    //! Constructor for the module that draws the shape
    //! Background is white but can be changed by modifying
    //! the enum pal.setColor
    //! This module assigns the shape id. This is necessary to maintain
    //! continuity if shapes get deleted
    explicit canvas(QWidget *parent = nullptr);

    //! ~canvas()
    //! Destructor
    //! Deletes the saved shapes because they are dynamically allocated
    ~canvas() override;

    //! void paintEvent(QPaintEvent *event)
    //! This method draws the shapes onto the module
    //! Does so by going through the vector of shapes
    //! and calling each shape's draw method
    void paintEvent(QPaintEvent *event) override;

    //! shape* canvas::get(int a) const
    //! Gets the shape, used so mainwindow can call const functions
    //! from each shape
    shape* get(int a) const;

    //! int numberOfShapes()
    //! Returns the number of shapes on screen
    int numberOfShapes();

    //! void addShape(int shape)
    //! Adds a new shape to screen by calling each shape's no-arg constructor
    void addShape(shape* p);//Adds to the vector of shapes

    //! void addShape(shape *p)
    //! Adds the newly created shape
    //! to the shape vector holding all the shapes
    void addShape(int shape);// Called by mainwindow

    //! void moveShape(int shapeIndex, int offSetX, int offSetY)
    //! Calls the shape specified by shapeIndex's move function
    void moveShape(int shapeIndex, int offSetX, int offSetY);

    //! void setPenColor(int shapeIndex, std::string color)
    //! Calls the shape specified by shapeIndex's setPenColor function
    void setPenColor(int shapeIndex, std::string color);

    //! void setPenWidth(int shapeIndex, int penWidth)
    //! Calls the shape specified by shapeIndex's setPenWidth function
    void setPenWidth(int shapeIndex, int penWidth);

    //! void setPenStyle(int shapeIndex, std::string style)
    //! Calls the shape specified by shapeIndex's setPenStyle function
    void setPenStyle(int shapeIndex, std::string style);

    //! void setPenCapStyle(int shapeIndex, std::string style)
    //! Calls the shape specified by shapeIndex's setPenCapStyle function
    void setPenCapStyle(int shapeIndex, std::string style);

    //! void setPenJoinStyle(int shapeIndex, std::string style)
    //! Calls the shape specified by shapeIndex's setPenJoinStyle function
    void setPenJoinStyle(int shapeIndex, std::string style);

    //! void setBrushColor(int shapeIndex, std::string color)
    //! Calls the shape specified by shapeIndex's setBrushColor function
    void setBrushColor(int shapeIndex, std::string color);

    //! void setBrushStyle(int shapeIndex, std::string style)
    //! Calls the shape specified by shapeIndex's setBrushStyle function
    void setBrushStyle(int shapeIndex, std::string style);

    //! void setTextFontWeight(int shapeIndex, std::string textFWeight)
    //! Calls the shape specified by shapeIndex's setTextFontWeight function
    void setTextFontWeight(int shapeIndex, std::string textFWeight);   

    //! void setTextString(int shapeIndex, std::string text)
    //! Calls the shape specified by shapeIndex's setTextString function
    void setTextString(int shapeIndex, std::string text);

    //! void setTextColor(int shapeIndex, std::string textColor)
    //! Calls the shape specified by shapeIndex's setTextColor function
    void setTextColor(int shapeIndex, std::string textColor);

    //! void setTextAlignment(int shapeIndex, std::string textAlign)
    //! Calls the shape specified by shapeIndex's setTextAlignment function
    void setTextAlignment(int shapeIndex, std::string textAlign);

    //! void setTextPointSize(int shapeIndex, int textPointSize)
    //! Calls the shape specified by shapeIndex's setTextPointSize function
    void setTextPointSize(int shapeIndex, int textPointSize);

    //! void setTextFontFamily(int shapeIndex, std::string textFont)
    //! Calls the shape specified by shapeIndex's setTextFontFamily function
    void setTextFontFamily(int shapeIndex, std::string textFont);

    //! void setTextFontStyle(int shapeIndex, std::string textFStyle)
    //! Calls the shape specified by shapeIndex's setTextFontStyle function
    void setTextFontStyle(int shapeIndex, std::string textFStyle);

    //! void assignShapeID()
    //! Assigns the shape ids starting from 100
    void assignShapeID();

    //! void changeShapeSize(int shapeIndex, int newSize)
    //! Calls the shape specified by shapeIndex's changeShapeSize function
    void changeShapeSize(int shapeIndex, int newSize);

    //! void removeShape(int index)
    //! Removes a shape from the vector holding all the shapes
    void removeShape(int index);

    //! void makeSquareOrCircle(int index)
    //! Makes rectangle shapes into squares,
    //! ellipse shapes into circles
    void makeSquareOrCircle(int index);

    //! void moveNode(int shapeIndex, int node, int offSetX, int offSetY)
    //! Moves the whole shape by the specified x and y pixel amounts
    void moveNode(int shapeIndex, int node, int offSetX, int offSetY);

    //! void addNode(int shapeIndex, int node)
    //! Adds a node to polyline and polygon shapes
    void addNode(int shapeIndex, int node);

    //! void removeNode(int shapeIndex, int node)
    //! Removes a node to polyline and polygon shapes
    void removeNode(int shapeIndex, int node);
    //! void shapeReport()
    //! Sorts the shapes and runs a report showing their perimeter and area
    void shapeReport();


private:
    //! Vector<shape*> vectShape
    //! Vector of shape pointers
    //! Holds all the shape on screen
    Vector<shape*> vectShape;

signals:

public slots:
};

#endif // CANVAS_H
