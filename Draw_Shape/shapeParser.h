#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"
//#include "Circle.h"
#include "line.h"
#include "rectangle.h"
#include "vector.h"

#include <QDebug>

void parseShape(std::string fileName);
Vector<shape*> parseShapes(std::string fileName);
shape* createShape(std::fstream& file, std::string shapeType);
void getPenBrushProperties(std::fstream& file, std::string& property, std::string& penColor,int& penWidth, std::string& penStyle,
                           std::string& penCapStyle, std::string& penJoinStyle, std::string& brushColor, std::string& brushStyle);

#endif
