#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include <string>
#include <QString>

class text : public shape
{
public:
    text();
    text(const char *str);
    void draw(QPaintDevice *toDraw);

private:
    QString *str;
    int x; //x position
    int y; //y position
};

#endif // TEXT_H
