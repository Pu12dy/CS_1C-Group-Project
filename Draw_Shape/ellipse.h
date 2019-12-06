#ifndef ELLIPSE_h
#define ELLIPSE_h

#include "shape.h"
#include <QPoint>
#include <string>


class Ellipse : public shape
{
private:
    int x1; // point x for center of ellipse
    int y1; // point y for center of ellipse
    int a;  // semi major axis (width/radius)
    int b;  // semi minor axis (height/radius)
    int shapeID;
    const double PI = 3.1415;

public:
    Ellipse();  // Default Constructor
    Ellipse(int shapeId, int x1, int y1, int a, int b); // Overload Constructor
    Ellipse(int shapeId, int x1, int y1, int a, int b, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
   // ~Ellipse(); // Destructor

    void draw(QPaintDevice *toDraw); // Draws the shape
    //void move(int x, int y); // Moves the center of the shape
    //int perimeter(); // Calculates the perimeters
    double area();	 // Calculates the area (PI * a * b = area)
};

#endif /* ELLIPSE_h */
