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
    int length;
    int width;
    std::string textAlignProp;
};

#endif // TEXT_H
