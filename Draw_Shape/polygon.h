#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "line.h"
#include <QPoint>
#include "vector.h"

class polygon : public shape
{
public:
    polygon();
    polygon(int shapeID, Vector<QPoint* > p1);

    // Matt use this constructor in parser
    polygon(int shapeID, Vector<QPoint* > p1, std::string penColor, int penWidth, std::string penStyle, std::string penCap, std::string penJoin, std::string bColor, std::string bStyle);
    virtual ~polygon() override;
    void draw(QPaintDevice *toDraw) override;
    void moveShape(int offsetX, int offsetY) override;
    double perimeter() const override;
    double area() const override;
    std::string getShapeType() const override;
    void moveNode(int index, int offsetX, int offSetY) override;
    int numberOfNodes() const override;
    void addNode(int index) override;
    void removeNode(int index) override;
    std::string getPoints() const override;
    void changeShapeSize(int newSize) override;

private:
    vector<line*> lines;
    Vector<QPoint* > points;
};

#endif // POLYGON_H
