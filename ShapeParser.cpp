#include "ShapeParser.h"
#include"Exceptions.h"

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

Vector<Shape*> parseShapes(std::string fileName)
{
  Vector<Shape*> vectorOfShapes;
  std::fstream file;
  file.open(fileName, std::ios::in);

  Shape* shapeObj = nullptr;
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
		  shapeObj = createShape(file, shapeType);
		  vectorOfShapes.push_back(shapeObj);
		  ++count;
	  }
  }

  

  file.close();

  return vectorOfShapes;
}

// =============================================================================

Shape* createShape(std::fstream& file, std::string shapeType)
{
  int shapeID = 0;
  int shapeValues[MAX_DIMENSIONS] = {0};
  Shape* shapeP = nullptr;
  int count = 0;

  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;

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
    shapeP = new line(shapeID, x1, y1, x2, y2);
  }
  else if (shapeType == "Rectangle")
  {
    file >> x1 >> y1 >> x2 >> y2;
    shapeP = new Rectangle(shapeID, x1, y1, x2, y2);
  }
  else
  {
    file >> x1 >> y1 >> x2;
    shapeP = new Circle(shapeID, x1, y1, x2);
  }

  return shapeP;
}
