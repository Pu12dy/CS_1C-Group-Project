#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
public:
    //!Default constructor for the rectangle class
    rectangle();
    //!Alternate constructor for the rectangle class
    rectangle(int shapeID, int x, int y, int l, int w);
    //!Alternate constructor for the rectangle class
    rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);    
    //!Alternate constructor for the rectangle class
    rectangle(int shapeID, int x, int y, int l, int w, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle);

    // Matt use this constructor in parser
    //!Alternate constructor for the rectangle class
    rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin,
              std::string bColor, std::string bStyle);
    //!Function overriden from the abstract base class shape. Used with QT to draw the shape.
    void draw(QPaintDevice *toDraw) override;
    //!Function overriden from the abstract base class shape.
    void moveShape(int offsetX, int offsetY) override;
    //!Function overriden from the abstract base class shape.
    void changeShapeSize(int newSize) override;
    //!Function overriden from the abstract base class shape, returns perimeter of the object.
    double perimeter() const override;
    //!Function overriden from the abstract base class shape, returns area of the object.
    double area() const override;
    //!Function overriden from the abstract base class shape, returns a string of the shape type.
    std::string getShapeType() const override;
    //!Function that will set the length equal to the width. Effectively creating square dimensions.
    void makeSquareOrCircle() override;
    //!Function that returns the x and y coordinates of the shape to a string.
    std::string getXYCoords() const override;
    //!Function that returns the length and width of the shape to a string.
    std::string getLengthWidth() const override;


private:
    int x;
    int y;
    int length;
    int width;
};

#endif // RECTANGLE_H
