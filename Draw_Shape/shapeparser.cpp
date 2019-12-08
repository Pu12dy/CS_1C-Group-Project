#include "shapeParser.h"
#include"exceptions.h"

// To Do:
// Seg fault, check when the createShape function stops creating the singular shape...
// Parse shapes from text file into dynamic shape objects of correct data type.

const int MAX_DIMENSIONS = 8;

void parseShape(std::string fileName) // Does not parse shapes, just reads from the file
{
  std::fstream file;
  file.open(fileName, std::ios::in);

  std::string line;

  if (file.fail()) // Error opening file, returning nullptr.
  {
    std::cout << "Error opening file (" << fileName << ")!\n";
    return;
  }

  std::cout << "Here is what is in the file: \n";
  while (!file.eof())
  {
    while (std::getline(file, line))
    {
      std::cout << line << '\n';
    }
  }
  std::cout << '\n';
  file.close();
}

// =============================================================================

Vector<shape*> parseShapes(std::string fileName)
{
  Vector<shape*> vectorOfShapes;
  std::fstream file;
  file.open(fileName, std::ios::in);

  shape* shapeObj = nullptr;
  int count = 0;
  std::string shapeType;


  if (file.fail())
  {
      throw fileNotFound();
  }
  else
  {
      while (!file.eof())
      {
          file >> shapeType;
          const char* c = shapeType.c_str();
          qDebug() << "shapeType: " << c;
          shapeObj = createShape(file, shapeType);
          vectorOfShapes.push_back(shapeObj);
          ++count;


      }
  }

  file.close();

  return vectorOfShapes;
}

// =============================================================================

shape* createShape(std::fstream& file, std::string shapeType)
{
  int shapeID = 0;
  int shapeValues[MAX_DIMENSIONS] = {0};
  shape* shapeP = nullptr;
  int count = 0;

  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  string penColor;
  int penWidth;
  string penStyle;
  string penCapStyle;
  string penJoinStyle;
  string brushColor;
  string brushStyle;

  string property;

  file >> shapeID;
  /*
  while (file >> shapeValues[count])
  {
    ++ count;
  }
  */

  if (shapeType == "Line")
  {
    file >> x1 >> y1 >> x2 >> y2;
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
    shapeP = new line(shapeID, x1, y1, x2, y2, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
  }

  else if (shapeType == "Rectangle")
  {
    file >> x1 >> y1 >> x2 >> y2;
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
    shapeP = new rectangle(shapeID, x1, y1, x2, y2, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
  }
  else
  {
    file >> x1 >> y1 >> x2;
    //shapeP = new Circle(shapeID, x1, y1, x2);
  }


  return shapeP;
}

// =======================================

void getPenBrushProperties(std::fstream& file, std::string& property, std::string& penColor,int& penWidth, std::string& penStyle,
                           std::string& penCapStyle, std::string& penJoinStyle, std::string& brushColor, std::string& brushStyle)
{
    getline(file, property, ' ');
    getline(file, penColor);
    getline(file, property, ' ');
    file >> penWidth;
    getline(file, property, ' ');
    getline(file, penStyle);
    getline(file, property, ' ');
    getline(file, penCapStyle);
    getline(file, property, ' ');
    getline(file, penJoinStyle);
    getline(file, property, ' ');
    getline(file, brushColor);
    getline(file, property, ' ');
    getline(file, brushStyle);
}

