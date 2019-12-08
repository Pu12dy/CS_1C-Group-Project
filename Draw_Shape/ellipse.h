#ifndef ellipse_h
#define ellipse_h

#include "shape.h"
#include <QPoint>
#include <string>


class ellipse : public shape
{
private:
    const double PI = 3.1415;

    int x; // point x for center of ellipse
    int y; // point y for center of ellipse
    int a;  // semi major axis (width/radius)
    int b;  // semi minor axis (height/radius)

public:
    ellipse();  // Default Constructor
    ellipse(int shapeId, int x, int y, int a, int b); // Overload Constructor
    ellipse(int shapeId, int x, int y, int a, int b, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    ellipse(int shapeID, int x, int y, int a, int b, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle);
    virtual ~ellipse(); // Destructor

    void draw(QPaintDevice *toDraw); // Draws the shape
    void moveShape(int offsetX, int offsetY); // Moves the center of the shape
    double perimeter() const;// Calculates the perimeters
    double area() const;	 // Calculates the area (PI * a * b = area)
    std::string getShapeType() const;
};

#endif /* ellipse_h */
