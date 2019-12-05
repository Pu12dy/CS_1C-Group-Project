#include "polyline.h"
#include "line.h"

polyline::polyline() : polyline(50, 150, 200, 200, 250,
                                    300, 250)
{

}
polyline::polyline(int shapeID, int x1, int y1, int x2, int y2,
         int x3, int y3)
{
    setShapeID(shapeID);
    firstHalf = new line(shapeID, x1, y1, x2, y2);
    secondHalf = new line(shapeID, x2, y2, x3, y3);
}

void polyline::draw(QPaintDevice *toDraw)
{
    firstHalf->draw(toDraw);
    secondHalf->draw(toDraw);
}
