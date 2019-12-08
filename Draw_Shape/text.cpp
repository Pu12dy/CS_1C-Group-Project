#include "text.h"

text::text() : text("default")
{

}

text::text(const char *str){
    this->str = new QString(str);
    setPenColor(Qt::green);
    x = 200;
    y = 50;
}

text::text(int x, int y, int l, int w, std::string textString, std::string textColor, std::string textAlignment, int textPointSize, std::string textFontFamily,
     std::string textFStyle, std::string textFWeight)
{
    this->str = new QString(textString.c_str());
    this->x = x; //x position
    this->y = y; //y position
    length = l;
    width = w;
    setTextColor(textColor);
    //textAlignmentP = setTextAlign(textAlignment);
    setTextPointSize(textPointSize);
    setTextFontFamily(textFontFamily);
    setTextFontStyle(textFStyle);
    setTextFontWeight(textFWeight);
    textAlignProp = textAlignment;

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

void text::setTextString(std::string text)
{
    delete str;
    str = new QString(text.c_str());
}



void text::moveShape(int offsetX, int offsetY)
{
    x += offsetX;
    y += offsetY;
}

void text::changeShapeSize(int newSize)
{
    this->textPointSize = this->textPointSize + newSize;
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
