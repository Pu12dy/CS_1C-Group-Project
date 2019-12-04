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


    void setTextString(std::string text) override;
    void setTextColor(std::string color) override;
    void setTextAlignment(std::string textAlign) override;
    void setTextPointSize(int textPointSize) override;
    void setTextFontFamily(std::string textFont) override;
    void setTextFontStyle(std::string textFStyle) override;
    void setTextFontWeight(std::string textFWeight) override;

private:
    QString *str;
    int x; //x position
    int y; //y position
};

#endif // TEXT_H
