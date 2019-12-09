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
    // Matt use this constructor in parser
    text(int shapeID, int x, int y, int l, int w, std::string textString, std::string textColor, std::string textAlignment, int textPointSize, std::string textFontFamily,
         std::string textFStyle, std::string textFWeight);
    ~text() override;
    void draw(QPaintDevice *toDraw) override;

    void setTextString(std::string text) override;
    void moveShape(int offsetX, int offsetY) override;
    void changeShapeSize(int newSize) override;
    std::string getShapeType() const override;
    double perimeter() const override;
    double area() const override;
    void setTextAlignment(std::string textAlign) override;
    std::string getTextString() const override;
    std::string getTextAlignmentString() const override;
    std::string getXYCoords() const override;
    std::string getLengthWidth() const override;// Of the box


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
