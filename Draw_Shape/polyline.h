#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "line.h"
#include <QPoint>
#include <QLineF>
#include <QtMath>
#include "vector.h"

//!polyline class derives from abstract base class shape
class polyline : public shape
{
public:
	//!class constructor for polyline
    polyline();
	//!class alternate constructor for polyline
	//!two arguments passed of type int an type Vector
    polyline(int shapeID, Vector<QPoint*> p1);

    // Matt use this constructor in parser
	//!Class alternate constructor for polyline
	//@param Passed: int, Vector, string, int, string, string, string
    polyline(int shapeID, Vector<QPoint*> p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
	//!Class destructor for polyline
	//!this is on overriden virtual destructor
    virtual ~polyline() override;
	
	//!Overriden draw method for the polyline class
    void draw(QPaintDevice *toDraw) override;
	//!Overriden move shape method for the polyline class
    void moveShape(int offsetX, int offsetY) override;
	//!Overriden change shape size method for the polyline class
    void changeShapeSize(int newSize) override;
	//!Overriden perimeter method for the polyline class
    double perimeter() const override; //! Calculates the perimeters
	//!Overriden area method for the polyline class
    double area() const override;//! Calculates the area
	//!Overriden get shape type method for the polyline class
    std::string getShapeType() const override;
	//!Overriden move node method for the polyline class
    void moveNode(int index, int offsetX, int offsetY) override;
	//!Overriden number of nodes method for the polyline class
    int numberOfNodes() const override;
	//!Overriden add node method for the polyline class
    void addNode(int index) override;
	//!Overriden remove node method for the polyline class
    void removeNode(int index) override;
	//!Overriden get points method for the polyline class
    std::string getPoints() const override;

private:
	//!private data member of type Vector name lines; line pointer
    Vector<line*> lines;
	//!private data member of type Vector named points; Qpoint pointer
	Vector<QPoint*> points;
};

#endif // POLYLINE_H
