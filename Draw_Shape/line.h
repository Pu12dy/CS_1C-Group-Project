#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include <QPoint>
#include <string>

//!line class that derives from the abstract base class shape
class line : public shape
{
public:
	
	//!Class constructor for line
	//!Sets default line
    line();
	//!Alternate class constructor for line
	//!Sets shapeID, points, color, width, style, penCap, penJoin
    line(int shapeID, Vector<QPoint*> points, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
	//!Alternate class constructor for line
	//!Sets ShapeID, and three points x1, x2, y2
    line(int shapeID, int x1, int y1, int x2, int y2);
	//!Class destructor for line
	//!Method is virtual and overriden due to abstract base class shape
    virtual ~line() override;

	//!Overriden draw method for the line class
    void draw(QPaintDevice *toDraw) override; //! Draws the shape
	//!Overriden move shape method for the line class
    void moveShape(int offsetX, int offsetY) override;
	
	//!Overriden change shape size method for the line class
    void changeShapeSize(int newSize) override;
	//!Constant get P1 method for line class
    const QPoint getP1() const;
	//!Constant get P2 method for line class
    const QPoint getP2() const;
	//!Overriden perimeter method for the line class
    double perimeter() const override;//! Calculates the perimeters
	//!Overriden area method for the line class
    double area() const override;//! Calculates the area
	
	//!Overriden get shape type method for the line class
    std::string getShapeType() const override;
	//!Overriden get points method for the line class
    std::string getPoints() const override;
	//!Overriden number of nodes method for the line class
    int numberOfNodes() const override;
	//!Overriden move node method for the line class
    void moveNode(int index, int offsetX, int offsetY) override;

private:
	//!private data member of type Vector pointer named points
    Vector<QPoint*> points;

};

#endif // LINE_H
