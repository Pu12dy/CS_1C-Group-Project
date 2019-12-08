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
    void moveShape(int offsetX, int offsetY);
    double perimeter() const override;
    double area() const override;    
    std::string getShapeType();

    virtual char getShapeCharIdentifier();
    virtual std::string getXYCoords();
    std::string getTextString();

    text(int shapeID, int x, int y, const char *str);
    text(int shapeID, int x, int y, const char *str, std::string textColor, std::string textAlignment, int textPointSize, std::string textFontFamily, std::string textFontStyle, std::string textFontWeight);

private:
    QString *str;
    int x; //x position
    int y; //y position
};

#endif // TEXT_H
