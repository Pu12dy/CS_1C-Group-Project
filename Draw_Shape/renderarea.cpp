#include "renderarea.h"
#include <QPainter>
#include "shape.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = RECTANGLE;

}
