#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"
//#include "Circle.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"
#include "text.h"
#include "vector.h"

#include <QDebug>

void parseShape(std::string fileName);
Vector<shape*> parseShapes(std::string fileName);
shape* createShape(std::fstream& file, std::string shapeType);
void getPenBrushProperties(std::fstream& file, std::string& property, std::string& penColor,int& penWidth, std::string& penStyle,
                           std::string& penCapStyle, std::string& penJoinStyle, std::string& brushColor, std::string& brushStyle);

void saveShapes(std::string fileName, Vector<shape*> vectorOfShapes);
std::string getPenColorString(shape* obj);
std::string getPenStyleString(shape* obj);
std::string getPenCapString(shape* obj);
std::string getPenJoinString(shape* obj);
std::string getBrushColorString(shape* obj);
std::string getBrushStyleString(shape* obj);
void getTextProperties(std::fstream& file, std::string& property, std::string& textColor, std::string& textAlignment, int& textPointSize,
                       std::string& textFontFamily, std::string& textFontStyle, std::string& textFontWeight);



#endif
