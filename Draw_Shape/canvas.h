#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "text.h"
#include "vector.h"

class canvas : public QWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void drawVect();

private:
    Vector<shape*> vectShape;
    Vector<shape*>* vPointer; //testing with pointer

signals:

public slots:
};

#endif // CANVAS_H
