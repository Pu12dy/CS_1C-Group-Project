#ifndef CANVAS_H
#define CANVAS_H

#include <algorithm>
#include <QWidget>
#include <QDebug>
#include <QString>
#include "shapeParser.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "text.h"
#include "vector.h"
#include "ellipse.h"
#include "polyline.h"
#include "polygon.h"
#include "extraCredit.h"

class canvas : public QWidget
{
    Q_OBJECT
public:


    explicit canvas(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    shape* get(int a);
    int numberOfShapes();

    void addShape(shape* p);//Adds to the vector of shapes
    void addShape(int shape);// Called by mainwindow
    void addNewLine(int shapeID, int x1, int y1, int x2, int y2);
    void addNewRect(int shapeID, int x, int y, int l, int w);
    shape* getActiveShape();
    void moveShape(int shapeIndex, int offSetX, int offSetY);
    void setPenColor(int shapeIndex, std::string color);
    void setPenWidth(int shapeIndex, int penWidth);
    void setPenStyle(int shapeIndex, std::string style);
    void setPenCapStyle(int shapeIndex, std::string style);
    void setPenJoinStyle(int shapeIndex, std::string style);
    void setBrushColor(int shapeIndex, std::string color);
    void setBrushStyle(int shapeIndex, std::string style);
    void setTextFontWeight(int shapeIndex, std::string textFWeight);   
    void setTextString(int shapeIndex, std::string text);
    void setTextColor(int shapeIndex, std::string textColor);
    void setTextAlignment(int shapeIndex, std::string textAlign);
    void setTextPointSize(int shapeIndex, int textPointSize);
    void setTextFontFamily(int shapeIndex, std::string textFont);
    void setTextFontStyle(int shapeIndex, std::string textFStyle);
    void assignShapeID();
    void changeShapeSize(int shapeIndex, int newSize);
    void removeShape(int index);
    void makeSquareOrCircle(int index);
    void moveNode(int shapeIndex, int node, int offSetX, int offSetY);
    void addNode(int shapeIndex, int node);
    void removeNode(int shapeIndex, int node);


private:
    Vector<shape*> vectShape;
    Vector<shape*> vectShapeParsed;

signals:

public slots:
};

#endif // CANVAS_H
