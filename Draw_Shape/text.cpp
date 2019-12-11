#include "text.h"

//!A constructor for the text class
//!Initializes a shape to be created specifically a text
text::text() : text(100, 120,240,400,100, "Text Goes Here", "red", "align right", 20, "courier", "styleitalic", "thin")
{

}
//!alternate constructor for text class
text::text(const char *str)
{
    this->str = new QString(str);
    setPenColor(Qt::green);
    x = 200;
    y = 50;
}
//!alternate constructor for text class
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
    setTextPointSize(textPointSize);
    setTextFontFamily(textFontFamily);
    setTextFontStyle(textFStyle);
    setTextFontWeight(textFWeight);
    textAlignProp = textAlignment;

}
//!destructor for the text class
text::~text(){}
//!ovveriden draw method for the text class
//!Derived from shape base class
//!A method that returns no data and one argument is passed of type QPaintDevice
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
//!Constant overriden setTextAlignment  method for the text class
//!Derived from the shape base class
void text::setTextAlignment(std::string textAlign)
{
    textAlignProp = textAlign;
}
//!ovveriden virtual getTextAlignment method for the text class
//!Derived from shape base class
std::string text::getTextAlignmentString() const
{
    return textAlignProp;
}
//!ovveriden setTextString method for the text class
//!Derived from shape base class
void text::setTextString(std::string text)
{
    delete str;
    str = new QString(QString::fromStdString(text));
}
//!ovveriden virtual getTextString method for the text class
//!Derived from shape base class
std::string text::getTextString() const
{
    return str->toStdString();
}
//!overriden moveShape method for the text class
//!Derived from the shape base class
//!Method allows user to move existing text using X and Y
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
//!Overriden change shape size method for the text class
//!Derived from the shape base class
//!allows user to change size of text
void text::changeShapeSize(int newSize)
{
    setTextPointSize(newSize);
}
//!ovveriden draw getShapeType for the text class
//!Derived from shape base class
//!no arguments passed, returns a string "text"
std::string text::getShapeType() const
{
    return "Text";
}
//!constant overriden perimeter method for the text class
//!Derived from the shape base class
double text::perimeter() const
{
    return 0.0;
}
//!Constant overriden area method for the text class
//!Derived from the shape base class
double text::area() const
{
    return 0.0;
}
//!ovveriden virtual getXYcoords method for the text class
//!Derived from shape base class
std::string text::getXYCoords() const
{
    return std::to_string(x) + " " + std::to_string(y);
}
//!ovveriden virtual getLengthWidth method for the text class
//!Derived from shape base class
std::string text::getLengthWidth() const
{
    return std::to_string(length) + " " + std::to_string(width);
}
