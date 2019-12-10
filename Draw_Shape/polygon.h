#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "line.h"
#include <QPoint>
#include <QLineF>
#include <QtMath>
#include "vector.h"

//!Polygon class that derives from the ABC shape and overrides the pure virtual functions
class polygon : public shape
{
public:
	//!default constructor for polygon class
    polygon();
	//!alternate constructor for polygon class
    polygon(int shapeID, Vector<QPoint* > p1);
    // Matt use this constructor in parser
	//!alternate constructor for polygon class
    polygon(int shapeID, Vector<QPoint* > p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle);
	//!virtual destructor for the polygon class: overriden
    virtual ~polygon() override;
	//!ovveriden draw method for the polygon class
	//!Derived from shape base class
    void draw(QPaintDevice *toDraw) override;
	//!overriden moveShape method for the polygon class
	//!Derived from the shape base class
    void moveShape(int offsetX, int offsetY) override;
	//!constant overriden perimeter method for the polygon class
	//!Derived from the shape base class
    double perimeter() const override;
	//!Constant overriden area method for the polygon class
	//!Derived from the shape base class
    double area() const override;
	//!Constant overriden getShapeType method for the polygon class
	//!Derived from the shape base class
    std::string getShapeType() const override;
	//!Overriden moveNode method for the polygon class
	//!Derived from the shape base class
    void moveNode(int index, int offsetX, int offSetY) override;
	//!Constant Overriden number of nodes method for the polygon class
	//!Derived from the shape base class
    int numberOfNodes() const override;
	//!Overriden add node method for the polygon class
	//!Derived from the shape base class
    void addNode(int index) override;
	//!Overriden remove node method for the polygon class
	//!Derived from the base class shape
    void removeNode(int index) override;
	//!Constant overriden get points method for the polygon class
	//!Derived from the shape base class
    std::string getPoints() const override;
	//!Overriden change shape size method for the polygon class
	//!Derived from the shape base class
    void changeShapeSize(int newSize) override;

private:
	//!Vector object of line* variable
    vector<line*> lines;
	//!Vector object of QPoint variable
    Vector<QPoint* > points;
};

#endif // POLYGON_H
