#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include <QPoint>
#include <string>

class line : public shape
{
public:
    line();
    line(int shapeID, int x1, int y1, int x2, int y2);
    line(int shapeID, int x1, int y1, int x2, int y2, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin);
    line(int shapeID, int x1, int y1, int x2, int y2, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin,
         std::string bColor, std::string bStyle);
	line(int shapeID, QPoint p1, QPoint p2);

    void draw(QPaintDevice *toDraw); // Draws the shape
    void moveShape(int offsetX, int offsetY);
    //void moveShape(QPoint offsetX, QPoint offsetY);
//    void move(int offsetX, int offsetY);// Moves the center of the shape
//    int perimeter();// Calculates the perimeters
//    double area();// Calculates the area

private:
    QPoint p1;
    QPoint p2;
    int x1;
    int y1;
    int x2;
    int y2;

};

#endif // LINE_H
