#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
public:
    rectangle();
    rectangle(int shapeID, int x, int y, int l, int w);
    rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    rectangle(int shapeID, int x, int y, int l, int w, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin,
              std::string bColor, std::string bStyle);
    rectangle(int shapeID, int x, int y, int l, int w, const QColor& color, int penWidth, Qt::PenStyle pStyle, Qt::PenCapStyle pcStyle, Qt::PenJoinStyle pjStyle);
    void draw(QPaintDevice *toDraw) override;
    void moveShape(int offsetX, int offsetY) override;
    double perimeter() const override;
    double area() const override;
    std::string getShapeType() const;


private:
    int x;
    int y;
    int length;
    int width;
};

#endif // RECTANGLE_H
