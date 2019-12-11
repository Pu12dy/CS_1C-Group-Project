#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include <string>
#include <QString>

//!Line class that derives from the ABC shape and overrides the pure virtual functions
class text : public shape
{
public:
	//!default constructor for text class
    text();
	//!alternate constructor for text class
    text(const char *str);
    // Matt use this constructor in parser
	//!alternate constructor for text class
    text(int shapeID, int x, int y, int l, int w, std::string textString, std::string textColor, std::string textAlignment, int textPointSize, std::string textFontFamily,
         std::string textFStyle, std::string textFWeight);
	//!destructor for the text class
	~text() override;
	//!ovveriden draw method for the text class
	//!Derived from shape base class
	void draw(QPaintDevice *toDraw) override;
	//!ovveriden setTextString method for the text class
	//!Derived from shape base class
	void setTextString(std::string text) override;
	//!overriden moveShape method for the text class
	//!Derived from the shape base class
	void moveShape(int offsetX, int offsetY) override;
	//!Overriden change shape size method for the text class
	//!Derived from the shape base class
	void changeShapeSize(int newSize) override;
	//!ovveriden draw getShapeType for the text class
	//!Derived from shape base class
    std::string getShapeType() const override;
	//!constant overriden perimeter method for the text class
	//!Derived from the shape base class
	double perimeter() const override;
	//!Constant overriden area method for the text class
	//!Derived from the shape base class
	double area() const override;
	//!Constant overriden setTextAlignment  method for the text class
	//!Derived from the shape base class
    void setTextAlignment(std::string textAlign) override;
	//!ovveriden virtual getTextString method for the text class
	//!Derived from shape base class
    std::string getTextString() const override;
	//!ovveriden virtual getTextAlignment method for the text class
	//!Derived from shape base class
    std::string getTextAlignmentString() const override;
	//!ovveriden virtual getXYcoords method for the text class
	//!Derived from shape base class
    std::string getXYCoords() const override;
	//!ovveriden virtual getLengthWidth method for the text class
	//!Derived from shape base class
    std::string getLengthWidth() const override;// Of the box


private:
	//! QString pointer str
    QString *str;
	//!x position
    int x;
	//!y position
    int y;
	//! length of text
    int length;
	//! width of text
    int width;
	//! QRect text border
    QRect rectText;
    std::string textAlignProp;
};

#endif // TEXT_H
