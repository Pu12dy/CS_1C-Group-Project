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
    ~text() override;
    void draw(QPaintDevice *toDraw) override;

    void setTextString(std::string text) override;
    void moveShape(int offsetX, int offsetY) override;
    std::string getShapeType() const override;
    double perimeter() const override;
    double area() const override;


private:
    QString *str;
    int x; //x position
    int y; //y position
    int length;
    int width;
    QRect rectText;
    std::string textAlignProp;
};

#endif // TEXT_H
