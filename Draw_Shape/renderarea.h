#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <Qbrush>
#include <Qpen>
#include <QPixmap>
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { LINE, POLYLINE, POLYGON, RECTANGLE,
                 ELLIPSE, TEXT };
    RenderArea(QWidget *parent = 0);
    Qsize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:

private:
    Shape shape;
    QPen pen;
    QBrush brush;

};

#endif // RENDERAREA_H
