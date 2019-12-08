#include "text.h"

text::text() : text("default")
{

}

text::text(const char *str){
    this->str = new QString(str);
    setPenColor(Qt::green);
}

void text::draw(QPaintDevice *toDraw){
    getQPainter().begin(toDraw);
    getQPainter().setPen(getQPen());
    getQPainter().drawText(200,50,*str);
    getQPainter().end();
}

void text::setTextString(std::string text)
{
    textString = text;
}

void text::setTextColor(std::string color)
{
    if(color == "white")
        textColor = Qt::white;
    else if(color == "black")
        textColor = Qt::black;
    else if(color == "red")
        textColor = Qt::red;
    else if(color == "green")
        textColor = Qt::green;
    else if(color == "blue")
        textColor = Qt::blue;
    else if(color == "magenta")
        textColor = Qt::magenta;
    else if(color == "yellow")
        textColor = Qt::yellow;
    else if(color == "gray")
        textColor = Qt::gray;
    else
        textColor = Qt::black;
}

void text::setTextAlignment(std::string textAlign)
{
    if(textAlign == "AlignLeft")
        textAlignment = Qt::AlignLeft;
    else if(textAlign == "AlignRight")
        textAlignment = Qt::AlignRight;
    else if(textAlign == "AlignTop")
        textAlignment = Qt::AlignTop;
    else if(textAlign == "AlignBottom")
        textAlignment = Qt::AlignBottom;
    else if(textAlign == "AlignCenter")
        textAlignment = Qt::AlignCenter;
    else
        textAlignment = Qt::AlignCenter;
}

void text::setTextPointSize(int textPointSize)
{
    this->textPointSize = textPointSize;
}

void text::setTextFontFamily(std::string textFont)
{
    textFontFamily = textFont;
}

void text::setTextFontStyle(std::string textFStyle)
{
    if(textFStyle == "StyleNormal")
        textFontStyle = QFont::StyleNormal;
    else if(textFStyle == "StyleItalic")
        textFontStyle = QFont::StyleItalic;
    else if(textFStyle == "StyleOblique")
        textFontStyle = QFont::StyleOblique;
    else
        textFontStyle = QFont::StyleNormal;
}

void text::setTextFontWeight(std::string textFWeight)
{
    if(textFWeight == "Thin")
        textFontWeight = QFont::Thin;
    else if(textFWeight == "Light")
        textFontWeight = QFont::Light;
    else if(textFWeight == "Normal")
        textFontWeight = QFont::Normal;
    else if(textFWeight == "Bold")
        textFontWeight = QFont::Bold;
    else
        textFontWeight = QFont::Normal;
}

void text::moveShape(int offsetX, int offsetY)
{
    x += offsetX;
    y += offsetY;
}

double text::perimeter() const
{
    return 0;
}
double text::area() const
{
    return 0;
}

std::string text::getShapeType()
{
    return "Text";
}
