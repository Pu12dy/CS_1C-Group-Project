#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Circle.h"
#include "line.h"
#include "Rectangle.h"
#include "vector.h"

void parseShape(std::string fileName);
Vector<Shape*> parseShapes(std::string fileName);
Shape* createShape(std::fstream& file, std::string shapeType);

#endif
