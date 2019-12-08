#include "shapeParser.h"
#include"exceptions.h"

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
      while (!file.peek() == file.eof())
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
  shape* shapeP = nullptr;

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
  string textStr;

  string textColor;
  string textAlignment;
  string textFontFamily;
  string textFontStyle;
  string textFontWeight;
  int textPointSize;

  file >> shapeID;

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
  else if (shapeType == "Ellipse")
  {
    file >> x1 >> y1 >> x2 >> y2;
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
    shapeP = new ellipse(shapeID, x1, y1, x2, y2, penColor, penWidth, penStyle, penCapStyle, penJoinStyle); // When using added constructor to change brushColor and brushStyle, canvas is entirely black
  }
  else if (shapeType == "Text")
  {
    file >> x1 >> y1;
    file.ignore();
    getline(file, textStr);
    const char *textStrCP = textStr.c_str();
    getTextProperties(file, property, textColor, textAlignment, textPointSize, textFontFamily, textFontStyle, textFontWeight);
    shapeP = new text(shapeID, x1, y1, textStrCP, textColor, textAlignment, textPointSize, textFontFamily, textFontStyle, textFontWeight);
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

// =======================================

void getTextProperties(std::fstream& file, std::string& property, std::string& textColor, std::string& textAlignment, int& textPointSize,
                       std::string& textFontFamily, std::string& textFontStyle, std::string& textFontWeight)
{
    getline(file, property, ' ');
    getline(file, textColor);
    getline(file, property, ' ');
    getline(file, textAlignment);
    getline(file, property, ' ');
    file >> textPointSize;
    getline(file, property, ' ');
    getline(file, textFontFamily);
    getline(file, property, ' ');
    getline(file, textFontStyle);
    getline(file, property, ' ');
    getline(file, textFontWeight);
}

// =======================================

void saveShapes(std::string fileName, Vector<shape*> vectorOfShapes)
{
    std::fstream file;
    file.open(fileName, std::ios::out);
    char shapeType;

    for (int i = 0; i < vectorOfShapes.size(); ++ i)
    {
        shapeType = vectorOfShapes[i]->getShapeCharIdentifier();

        if (shapeType == 'L') // Line
        {
            file << "Line\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords();
            file << "PenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
            file << "BrushColor: " << getBrushColorString(vectorOfShapes[i]) << "\n";
            file << "BrushStyle: " << getBrushStyleString(vectorOfShapes[i]) << "\n";

        }
        else if (shapeType == 'R') // Rectangle
        {
            file << "Rectangle\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords();
            file << "abcPenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
            file << "BrushColor: " << getBrushColorString(vectorOfShapes[i]) << "\n";
            file << "BrushStyle: " << getBrushStyleString(vectorOfShapes[i]) << "\n";

        }
        else if (shapeType == 'E') // Ellipse
        {
            file << "Ellipse\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords();
            file << "PenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
            file << "BrushColor: " << getBrushColorString(vectorOfShapes[i]) << "\n";
            file << "BrushStyle: " << getBrushStyleString(vectorOfShapes[i]) << "\n";
        }
        else if (shapeType == 'T') // Text
        {
            file << "Text\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords() << "\n";
            file << dynamic_cast<text*>(vectorOfShapes[i])->getTextString() << "\n";
            file << "TextColor: " << vectorOfShapes[i]->getTextColorString() << "\n";
            file << "TextAlignment: " << vectorOfShapes[i]->getTextAlignmentString() << "\n";
            file << "TextPointSize: " << vectorOfShapes[i]->getTextPointSize() << "\n";
            file << "TextFontFamily: " << vectorOfShapes[i]->getTextFontFamilyString() << "\n";
            file << "TextFontStyle: " << vectorOfShapes[i]->getTextFontStyleString() << "\n";
            file << "TextFontWeight: " << vectorOfShapes[i]->getTextFontWeightString() << "\n";
        }
    }

    file.close();
}

// ============================================================================

std::string getPenColorString(shape* obj)
{
    if (obj->getQPen().QPen::color() == Qt::white)
    {
        return "white";
    }
    else if(obj->getQPen().QPen::color() == Qt::black)
    {
        return "black";
    }
    else if(obj->getQPen().QPen::color() == Qt::red)
    {
        return "red";
    }
    else if(obj->getQPen().QPen::color() == Qt::green)
    {
        return "green";
    }
    else if(obj->getQPen().QPen::color() == Qt::blue)
    {
        return "blue";
    }
    else if(obj->getQPen().QPen::color() == Qt::magenta)
    {
        return "magenta";
    }
    else if(obj->getQPen().QPen::color() == Qt::yellow)
    {
        return "yellow";
    }
    else if(obj->getQPen().QPen::color() == Qt::gray)
    {
        return "gray";
    }
    else
    {
        return "black";
    }
}

// ============================================================================

std::string getPenStyleString(shape* obj)
{
    if (obj->getQPen().QPen::style() == Qt::SolidLine)
    {
        return "solid line";
    }
    else if (obj->getQPen().QPen::style() == Qt::DashLine)
    {
        return "dash line";
    }
    else if (obj->getQPen().QPen::style() == Qt::DotLine)
    {
        return "dot line";
    }
    else if (obj->getQPen().QPen::style() == Qt::DashDotLine)
    {
        return "dash dot line";
    }
    else if (obj->getQPen().QPen::style() == Qt::DashDotDotLine)
    {
        return "dash dot dot line";
    }
    else if (obj->getQPen().QPen::style() == Qt::CustomDashLine)
    {
        return "custom dash line";
    }
    else
    {
        "solid line";
    }
}

// ============================================================================

std::string getPenCapString(shape* obj)
{
    if (obj->getQPen().QPen::capStyle() == Qt::SquareCap)
    {
        return "square cap";
    }
    else if (obj->getQPen().QPen::capStyle() == Qt::FlatCap)
    {
        return "flat cap";
    }
    else if (obj->getQPen().QPen::capStyle() == Qt::RoundCap)
    {
        return "round cap";
    }
    else
    {
        "square cap";
    }
}

// ============================================================================

std::string getPenJoinString(shape* obj)
{
    if (obj->getQPen().QPen::joinStyle() == Qt::BevelJoin)
    {
        return "bevel join";
    }
    else if (obj->getQPen().QPen::joinStyle() == Qt::MiterJoin)
    {
        return "miter join";
    }
    else if (obj->getQPen().QPen::joinStyle() == Qt::RoundJoin)
    {
        return "round join";
    }
    else
    {
        "bevel join";
    }
}

// ============================================================================

std::string getBrushColorString(shape* obj)
{
    if (obj->getQBrush().QBrush::color() == Qt::white)
    {
        return "white";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::black)
    {
        return "black";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::red)
    {
        return "red";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::green)
    {
        return "green";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::blue)
    {
        return "blue";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::magenta)
    {
        return "magenta";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::yellow)
    {
        return "yellow";
    }
    else if(obj->getQBrush().QBrush::color() == Qt::gray)
    {
        return "gray";
    }
    else
    {
        return "black";
    }
}

// ============================================================================

std::string getBrushStyleString(shape* obj)
{
    if (obj->getQBrush().QBrush::style() == Qt::SolidPattern)
    {
        return "SolidPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense1Pattern)
    {
        return "Dense1Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense2Pattern)
    {
        return "Dense2Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense3Pattern)
    {
        return "Dense3Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense4Pattern)
    {
        return "Dense4Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense5Pattern)
    {
        return "Dense5Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense6Pattern)
    {
        return "Dense6Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::Dense7Pattern)
    {
        return "Dense7Pattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::HorPattern)
    {
        return "HorPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::VerPattern)
    {
        return "VerPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::CrossPattern)
    {
        return "CrossPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::BDiagPattern)
    {
        return "BDiagPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::FDiagPattern)
    {
        return "FDiagPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::DiagCrossPattern)
    {
        return "DiagCrossPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::LinearGradientPattern)
    {
        return "LinearGradientPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::RadialGradientPattern)
    {
        return "RadialGradientPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::ConicalGradientPattern)
    {
        return "ConicalGradientPattern";
    }
    else if (obj->getQBrush().QBrush::style() == Qt::TexturePattern)
    {
        return "TexturePattern";
    }
    else
    {
        return "NoBrush";
    }
}

// ============================================================================




