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
    text(int x, int y, int l, int w, std::string textString, std::string textColor, std::string textAlignment, int textPointSize, std::string textFontFamily,
         std::string textFStyle, std::string textFWeight);
    virtual ~text();
    void draw(QPaintDevice *toDraw) override;

    void setTextString(std::string text) override;
    void moveShape(int offsetX, int offsetY) override;


private:
    QString *str;
    int x; //x position
    int y; //y position
    int length;
    int width;
    std::string textAlignProp;
};

#endif // TEXT_H
