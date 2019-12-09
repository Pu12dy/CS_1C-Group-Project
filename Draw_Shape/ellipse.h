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
    virtual ~ellipse() override; // Destructor

    void draw(QPaintDevice *toDraw) override; // Draws the shape
    void moveShape(int offsetX, int offsetY) override; // Moves the center of the shape
    void changeShapeSize(int newSize) override;
    double perimeter() const override;// Calculates the perimeters
    double area() const override;	 // Calculates the area (PI * a * b = area)
    std::string getShapeType() const override;
    void makeSquareOrCircle() override;
};

#endif /* ellipse_h */
