#include "text.h"

text::text() : text(100, 120,240,400,100, "Text Goes Here", "red", "align right", 50, "courier", "styleitalic", "thin")
{

}

text::text(const char *str){
    this->str = new QString(str);
    setPenColor(Qt::green);
    x = 200;
    y = 50;

}

text::text(int shapeID, int x, int y, int l, int w, std::string textString, std::string textColor, std::string textAlignment, int textPointSize, std::string textFontFamily,
     std::string textFStyle, std::string textFWeight)
{
    setShapeID(shapeID);
    this->str = new QString(textString.c_str());
    this->x = x; //x position
    this->y = y; //y position
    rectText = QRect(x,y, l, w);
    length = l;
    width = w;
    setTextColor(textColor);
    //textAlignmentP = setTextAlign(textAlignment);
    setTextPointSize(textPointSize);
    setTextFontFamily(textFontFamily);
    setTextFontStyle(textFStyle);
    setTextFontWeight(textFWeight);
    textAlignProp = textAlignment;

}

text::~text(){}

void text::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    //getQPainter().drawText(x,y,*str);
    const QRect rectDraw(x,y,length, width);
    const QString strDraw(*str);
    getQPainter().setFont(getQFont());
    //getQPainter().drawText(rectDraw, Qt::AlignCenter, strDraw);
    getQPainter().drawText(rectDraw, setTextAlign(textAlignProp), strDraw);
    getQPainter().end();
}

void text::setTextAlignment(std::string textAlign)
{
    textAlignProp = textAlign;
}

std::string text::getTextAlignmentString() const
{
    return textAlignProp;
}

void text::setTextString(std::string text)
{
    delete str;
    str = new QString(QString::fromStdString(text));
}

std::string text::getTextString() const
{
    return str->toStdString();
}

void text::moveShape(int offsetX, int offsetY)
{
    x += offsetX;
    y += offsetY;

    //Ensuring shape does not move out of screen
    if (x < 0)
        x = 0;
    else if (x > 950)
        x = 950;
    if (y < 0)
        y = 0;
    else if (y > 450)
        y = 450;

}

void text::changeShapeSize(int newSize)
{
    setTextPointSize(newSize);
    // this->textPointSize = this->textPointSize + newSize;
}

std::string text::getShapeType() const
{
    return "Text";
}

double text::perimeter() const
{
    return 0.0;
}
double text::area() const
{
    return 0.0;
}
std::string text::getXYCoords() const
{
    return std::to_string(x) + " " + std::to_string(y);
}

std::string text::getLengthWidth() const
{
    return std::to_string(length) + " " + std::to_string(width);
}
