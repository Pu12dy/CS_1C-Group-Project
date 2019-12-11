#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "vector.h"
#include "text.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"

#include <QDebug>

//!Function that acts as the Master to the parser that will call additional utility parser functions, ultimately returning a vector of shape pointer objects from the text file.
Vector<shape*> parseShapes(std::string fileName);
//!Function that ultimately parses the text file for one shape pointer object and returns that pointer.
shape* createShape(std::fstream& file, std::string shapeType);
//!Function that acts as the Master to saving a vector of shape pointers. This will call multiple save utility functions to evenutally overwrite the shapes.txt file for persistence after every execution.
void saveShapes(std::string fileName, Vector<shape*> vectorOfShapes);
//!Function that acts as a utility to the saveShapes function. Gets the pen brush properties from shape pointers and writes them to the .txt file for saving.
void getPenBrushProperties(std::fstream& file, std::string& property, std::string& penColor,int& penWidth, std::string& penStyle,
                           std::string& penCapStyle, std::string& penJoinStyle, std::string& brushColor, std::string& brushStyle);
//!Function that acts as a utility to the saveShapes function. Gets the text properties from the shape pointer vector and writes them to the .txt file for saving.
void getTextProperties(std::fstream& file, std::string& property, std::string& textColor, std::string& textAlignment, int& textPointSize,
                       std::string& textFontFamily, std::string& textFontStyle, std::string& textFontWeight);
//!Function that acts as a utility to the parseShapes function. Will get dimensions from the txt file for the parser to then use this data.
void getDimensions(std::fstream& file, int& x, int& y, double& a, double &b);
//!Function that acts as a utility to the parseShapes function. This function will be called in the createShapes function when needing to parse a polygon or polyline.
void parsePoints(std::fstream& file, Vector<QPoint*>& points);
//!Function that acts as a utility to the saveShapes function. This function will get the pen brush properties, but without the brush properties.
void getPenBrushProperties(std::fstream& file, std::string& property, std::string& penColor,int& penWidth, std::string& penStyle,
                           std::string& penCapStyle, std::string& penJoinStyle);
//!Function that acts as a utility to the saveShapes function. This will return a string of the shape pointer objects penColor.
std::string getPenColorString(shape* obj);
//!Function that acts as a utility to the saveShapes function. This will return a string of the shape pointer objects penStyle.
std::string getPenStyleString(shape* obj);
//!Function that acts as a utility to the saveShapes function. This will return a string of the shape pointer objects penCap.
std::string getPenCapString(shape* obj);
//!Function that acts as a utility to the saveShapes function. This will return a string of the shape pointer objects penJoin.
std::string getPenJoinString(shape* obj);
//!Function that acts as a utility to the saveShapes function. This will return a string of the shape pointer objects brushColor.
std::string getBrushColorString(shape* obj);
//!Function that acts as a utility to the saveShapes function. This will return a string of the shape pointer objects brushStyle.
std::string getBrushStyleString(shape* obj);


#endif
