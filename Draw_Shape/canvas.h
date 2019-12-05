#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QDebug>
#include "shapeParser.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "text.h"
#include "vector.h"
#include "polyline.h"

class canvas : public QWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    shape* get(int a);
    int numberOfShapes();

    void addShape(shape* p);
    void addNewLine(int shapeID, int x1, int y1, int x2, int y2);
    void addNewRect(int shapeID, int x, int y, int l, int w);

private:
    Vector<shape*> vectShape;
    Vector<shape*> vectShapeParsed;

signals:

public slots:
};

#endif // CANVAS_H