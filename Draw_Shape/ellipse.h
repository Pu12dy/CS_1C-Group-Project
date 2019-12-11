#ifndef ellipse_h
#define ellipse_h

#include "shape.h"
#include <QPoint>
#include <string>

//! ellipse class that derives from  shape class
class ellipse : public shape
{
private:
    const double PI = 3.1415;

    int x; //! point x for center of ellipse
    int y; //!point y for center of ellipse
    int a;  //! semi major axis (width/radius)
    int b;  //! semi minor axis (height/radius)

public:
	//! Default Constructor
    ellipse();
	//! Overload Constructor
    ellipse(int shapeId, int x, int y, int a, int b);
	//!Overloaded constructor
    ellipse(int shapeId, int x, int y, int a, int b, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
	//!Overloaded constructor
    ellipse(int shapeID, int x, int y, int a, int b, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle);

    // Matt use this constructor in parser
    ellipse(int shapeId, int x, int y, int a, int b, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle);

	//!Virtual constructor for the ellipse class
    virtual ~ellipse() override;
	//! Draws the shape
    void draw(QPaintDevice *toDraw) override;
	//! Moves the center of the shape
    void moveShape(int offsetX, int offsetY) override;
    void changeShapeSize(int newSize) override;
	//! Calculates the perimeters
    double perimeter() const override;
	//! Calculates the area (PI * a * b = area)
    double area() const override;
	//!Get shape type method returns constant string "Ellipse"
    std::string getShapeType() const override;
	//!Method to make square or circle
    void makeSquareOrCircle() override;
	//!Method to retrive stored X and Y cordinates
    std::string getXYCoords() const override;
	//!Method to return length and width
    std::string getLengthWidth() const override;
};

#endif /* ellipse_h */
