#include "shape.h"

shape::shape()
{
    shapeID = 101;
}

shape::~shape()
{

}

shape::shape(const shape &source)
{

}


QPainter& shape::getQPainter()
{
    return painter;
}

QPen& shape::getQPen()
{
    return pen;
}

QBrush& shape::getQBrush()
{
    return brush;
}

QFont& shape::getQFont()
{
    return tFont;
}


void shape::draw(QPaintDevice *toDraw)
{

}


//int Shape::getShapeID() // Returns shapeID
//{
//    return shapeID;
//}

void shape::setShapeID(int num)
{
    shapeID = num;
}

int shape::getShapeID() const
{
    return shapeID;
}

std::string shape::getID() const
{
    return std::to_string(getShapeID());
}

std::string shape::getShapeName() const
{
    return getShapeType() + " " + getID();
}

//void shape::setPen(const QPen& pen)
//{
//    this->pen = pen;
//}

//void shape::setBrush(const QBrush& brush)
//{
//    this->brush = brush;
//}

//void shape::setText(const Text& text)
//{
//    this-text = text;
//}


void shape::setPenColor(std::string color){
    if(color == "white")
        pen.setColor(Qt::white);
    else if(color == "black")
        pen.setColor(Qt::black);
    else if(color == "red")
        pen.setColor(Qt::red);
    else if(color == "green")
        pen.setColor(Qt::green);
    else if(color == "blue")
        pen.setColor(Qt::blue);
    else if(color == "magenta")
        pen.setColor(Qt::magenta);
    else if(color == "yellow")
        pen.setColor(Qt::yellow);
    else if(color == "gray")
        pen.setColor(Qt::gray);
    else if(color == "cyan")
        pen.setColor(Qt::cyan);
    else
        pen.setColor(Qt::black);
}

void shape::setPenColor(const QColor& color){
    pen.setColor(color);
}

void shape::setPenWidth(int penWidth){
    pen.setWidth(penWidth);
}

void shape::setPenStyle(std::string style){
    if(style == "solid line")
        pen.setStyle(Qt::SolidLine);
    else if(style == "no pen")
        pen.setStyle(Qt::NoPen);
    else if(style == "dash line")
        pen.setStyle(Qt::DashLine);
    else if(style == "dot line")
        pen.setStyle(Qt::DotLine);
    else if(style == "dash dot line")
        pen.setStyle(Qt::DashDotLine);
    else if(style == "dash dot dot line")
        pen.setStyle(Qt::DashDotDotLine);
    else
        pen.setStyle(Qt::SolidLine);
}

void shape::setPenStyle(Qt::PenStyle style){
    pen.setStyle(style);
}

void shape::setPenCapStyle(std::string style){
    if(style == "square cap")
        pen.setCapStyle(Qt::SquareCap);
    else if(style == "flat cap")
        pen.setCapStyle(Qt::FlatCap);
    else if(style == "round cap")
        pen.setCapStyle(Qt::RoundCap);
}

void shape::setPenCapStyle(Qt::PenCapStyle style){
    pen.setCapStyle(style);
}

void shape::setPenJoinStyle(std::string style){
    if(style == "bevel join")
        pen.setJoinStyle(Qt::BevelJoin);
    else if(style == "miter join")
        pen.setJoinStyle(Qt::MiterJoin);
    else if(style == "round join")
        pen.setJoinStyle(Qt::RoundJoin);
}

void shape::setPenJoinStyle(Qt::PenJoinStyle style){
    pen.setJoinStyle(style);
}

void shape::setBrushColor(std::string color){
    if(color == "white")
        brush.setColor(Qt::white);
    else if(color == "black")
        brush.setColor(Qt::black);
    else if(color == "red")
        brush.setColor(Qt::red);
    else if(color == "green")
        brush.setColor(Qt::green);
    else if(color == "blue")
        brush.setColor(Qt::blue);
    else if(color == "magenta")
        brush.setColor(Qt::magenta);
    else if(color == "yellow")
        brush.setColor(Qt::yellow);
    else if(color == "gray")
        brush.setColor(Qt::gray);
    else if(color == "cyan")
        brush.setColor(Qt::cyan);
    else
        brush.setColor(Qt::black);
}

void shape::setBrushColor(const QColor& color){
    brush.setColor(color);
}

void shape::setBrushStyle(std::string style){
    if(style == "solid pattern" || style == "SolidPattern")
        brush.setStyle(Qt::SolidPattern);
    else if(style == "hor pattern" || style == "HorPattern")
        brush.setStyle(Qt::HorPattern);
    else if(style == "ver pattern" || style == "VerPattern")
        brush.setStyle(Qt::VerPattern);
    else
        brush.setStyle(Qt::NoBrush);
}

void shape::setBrushStyle(Qt::BrushStyle style){
    brush.setStyle(style);
}

void shape::setTextString(std::string text){}
void shape::setTextColor(std::string textColor) {
    this->textColor = textColor;
    setPenColor(textColor);
}

void shape::setTextAlignment(std::string textAlign)
{

}

Qt::AlignmentFlag shape::setTextAlign(std::string textAlign)
{
    if(textAlign == "align left" || textAlign == "alignleft" || textAlign == "AlignLeft")
        return Qt::AlignLeft;
    else if(textAlign == "align right" || textAlign == "Align Right" || textAlign == "AlignRight")
        return Qt::AlignRight;
    else if(textAlign == "align top" || textAlign == "Align Top" || textAlign == "AlignTop")
       return Qt::AlignTop;
    else if(textAlign == "align bottom" || textAlign == "Align Bottom" || textAlign == "AlignBottom")
        return Qt::AlignBottom;
    else if(textAlign == "align center" || textAlign == "Align Center" || textAlign == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignLeft;
}
void shape::setTextPointSize(int textPointSize) {
    tFont.setPointSize(textPointSize);
}
void shape::setTextFontFamily(std::string textFont) {
    if(textFont == "courier")
        tFont.setFamily(QString::fromStdString("Courier"));
    else if(textFont == "helvetica")
        tFont.setFamily(QString::fromStdString("Helvetica"));
    else if(textFont == "times")
        tFont.setFamily(QString::fromStdString("Times"));
    else if(textFont == "comic sans ms")
        tFont.setFamily(QString::fromStdString("Comic Sans MS"));

}
void shape::setTextFontStyle(std::string textFStyle) {
    textFontStyle = textFStyle;
    if(textFStyle == "style normal" || textFStyle == "Style Normal" || textFStyle == "StyleNormal")
        tFont.setStyle(QFont::StyleNormal);
    else if(textFStyle == "style italic" || textFStyle == "Style Italic" || textFStyle == "StyleItalic")
        tFont.setStyle(QFont::StyleItalic);
    else if(textFStyle == "style oblique" || textFStyle == "Style Oblique" || textFStyle == "StyleOblique")
        tFont.setStyle(QFont::StyleOblique);
    else
        tFont.setStyle(QFont::StyleNormal); //Default
}
void shape::setTextFontWeight(std::string textFWeight) {
    if(textFWeight == "thin")
        tFont.setWeight(QFont::Thin);
    else if(textFWeight == "light")
        tFont.setWeight(QFont::Light);
    else if(textFWeight == "normal")
        tFont.setWeight(QFont::Normal);
    else if(textFWeight == "bold")
        tFont.setWeight(QFont::Bold);
    else
        tFont.setWeight(QFont::Normal); //Default
}

std::string shape::getTextString() const
{
    return "";// meant to be overriden
}

std::string shape::getTextColorString() const
{
    return textColor;
}

std::string shape::getTextAlignmentString() const
{
    return "";
}

std::string shape::getTextPointSize() const
{
    return std::to_string(tFont.pointSize());
}

std::string shape::getTextFontFamilyString() const
{
    return tFont.family().toStdString();
}

std::string shape::getTextFontStyleString() const
{
    return textFontStyle;
}

std::string shape::getTextFontWeightString() const
{
    switch(tFont.weight())
    {
    case 0:
        return "thin";
    case 25:
        return "light";
    case 50:
        return "normal";
    case 75:
        return "bold";
    default:
        return "normal";
    }
}

std::string shape::getXYCoords() const
{
    return "";
}

std::string shape::getLengthWidth() const
{
    return "";
}

void shape::makeSquareOrCircle()
{

}

void shape::moveNode(int index, int offsetX, int offSetY)
{

}

int shape::numberOfNodes() const
{
    return 0;
}

void shape::addNode(int index)
{

}
void shape::removeNode(int index)
{

}

std::string shape::getPoints() const
{
    return "";
}
