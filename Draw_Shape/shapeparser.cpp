#include "shapeParser.h"
#include"exceptions.h"

// =============================================================================

Vector<shape*> parseShapes(std::string fileName)
{
  Vector<shape*> vectorOfShapes;
  std::fstream file;
  file.open(fileName, std::ios::in);

  shape* shapeObj = nullptr;
  int count = 0;
  std::string shapeType;


  if (!file.is_open())
  {
      //throw fileNotFound();
       return vectorOfShapes;
  }
  else
  {
      while (!file.peek() == file.eof())
      {
          std::getline(file, shapeType, '\n');
          shapeObj = createShape(file,shapeType);
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

  int x = 0;
  int y = 0;
  int a = 0;
  int b = 0;
  std::string idString;
  std::string xString;
  std::string yString;
  std::string aString;
  std::string bString;
  std::string penColor;
  int penWidth;
  std::string penStyle;
  std::string penCapStyle;
  std::string penJoinStyle;
  std::string brushColor;
  std::string brushStyle;

  std::string property;
  std::string textStr;

  std::string textColor;
  std::string textAlignment;
  std::string textFontFamily;
  std::string textFontStyle;
  std::string textFontWeight;
  int textPointSize;

  std::getline(file, idString);
  shapeID = std::stoi(idString);

  if (shapeType == "Line")
  {
      Vector<QPoint*> points;
      parsePoints(file, points);
      getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
      shapeP = new line(shapeID, points, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
  }
  else if (shapeType == "Rectangle" || shapeType == "Square")
  {
    getDimensions(file, x, y, a , b);
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
    shapeP = new rectangle(shapeID, x, y, a, b, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
  }
  else if (shapeType == "Ellipse" || shapeType == "Circle")
  {
    getDimensions(file, x, y, a , b);
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
    shapeP = new ellipse(shapeID, x, y, a, b, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle); // When using added constructor to change brushColor and brushStyle, canvas is entirely black
  }
  else if (shapeType == "Text")
  {
    getDimensions(file, x, y, a , b);
    std::getline(file, textStr, '\n');
    getTextProperties(file, property, textColor, textAlignment, textPointSize, textFontFamily, textFontStyle, textFontWeight);
    shapeP = new text(shapeID, x, y, a, b, textStr, textColor, textAlignment, textPointSize, textFontFamily, textFontStyle, textFontWeight);
  }
  else if (shapeType == "Polygon")
  {
    Vector<QPoint*> points;
    parsePoints(file, points);
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
    shapeP = new polygon(shapeID, points, penColor, penWidth, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle);
  }
  else if (shapeType == "Polyline")
  {
    Vector<QPoint*> points;
    parsePoints(file, points);
    getPenBrushProperties(file, property, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
    shapeP = new polyline(shapeID, points, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
  }

  return shapeP;
}

// =======================================

void parsePoints(std::fstream& file, Vector<QPoint*>& points)
{
    std::string numNodes;
    std::string xString;
    std::string yString;

    getline(file, numNodes, '\n');

    for (int i = 0; i < std::stoi(numNodes); i++)
    {
        getline(file, xString, ' ');
        getline(file, yString, '\n');
        points.push_back(new QPoint(std::stoi(xString), std::stoi(yString)));
    }

}

void getDimensions(std::fstream& file, int& x, int& y, int& a, int &b)
{
    std::string xString;
    std::string yString;
    std::string aString;
    std::string bString;

    getline(file, xString, ' ');
    x = std::stoi(xString);

    getline(file, yString, '\n');
    y = std::stoi(yString);

    getline(file, aString, ' ');
    a = std::stoi(aString);

    getline(file, bString, '\n');
    b = std::stoi(bString);
}

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

void getPenBrushProperties(std::fstream& file, std::string& property, std::string& penColor,int& penWidth, std::string& penStyle,
                           std::string& penCapStyle, std::string& penJoinStyle)
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
    std::string shapeType;

    for (int i = 0; i < vectorOfShapes.size(); ++ i)
    {
        shapeType = vectorOfShapes[i]->getShapeType();

        if (shapeType == "Line" || shapeType == "Polyline") // Line
        {
            file << vectorOfShapes[i]->getShapeType() << "\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getPoints();
            file << "PenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
        }
        else if (shapeType == "Rectangle" || shapeType == "Square") // Rectangle
        {
            file << vectorOfShapes[i]->getShapeType() << "\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords() << "\n";
            file << vectorOfShapes[i]->getLengthWidth() << "\n";
            file << "PenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
            file << "BrushColor: " << getBrushColorString(vectorOfShapes[i]) << "\n";
            file << "BrushStyle: " << getBrushStyleString(vectorOfShapes[i]) << "\n";

        }
        else if (shapeType == "Ellipse" || shapeType == "Circle") // Ellipse
        {
            file << vectorOfShapes[i]->getShapeType() << "\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords() << "\n";
            file << vectorOfShapes[i]->getLengthWidth() << "\n";
            file << "PenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
            file << "BrushColor: " << getBrushColorString(vectorOfShapes[i]) << "\n";
            file << "BrushStyle: " << getBrushStyleString(vectorOfShapes[i]) << "\n";
        }
        else if (shapeType == "Text") // Text
        {
            file << vectorOfShapes[i]->getShapeType() << "\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getXYCoords() << "\n";
            file << vectorOfShapes[i]->getLengthWidth() << "\n";
            file << vectorOfShapes[i]->getTextString() << "\n";
            file << "TextColor: " << vectorOfShapes[i]->getTextColorString() << "\n";
            file << "TextAlignment: " << vectorOfShapes[i]->getTextAlignmentString() << "\n";
            file << "TextPointSize: " << vectorOfShapes[i]->getTextPointSize() << "\n";
            file << "TextFontFamily: " << vectorOfShapes[i]->getTextFontFamilyString() << "\n";
            file << "TextFontStyle: " << vectorOfShapes[i]->getTextFontStyleString() << "\n";
            file << "TextFontWeight: " << vectorOfShapes[i]->getTextFontWeightString() << "\n";
        }
        else if (shapeType == "Polygon") //Polygon
        {
            file << vectorOfShapes[i]->getShapeType() << "\n";
            file << vectorOfShapes[i]->getShapeID() << "\n";
            file << vectorOfShapes[i]->getPoints();// has built in return line;
            file << "PenColor: " << getPenColorString(vectorOfShapes[i]) << "\n";
            file << "PenWidth: " << vectorOfShapes[i]->getQPen().QPen::width() << "\n";
            file << "PenStyle: " << getPenStyleString(vectorOfShapes[i]) << "\n";
            file << "PenCap: " << getPenCapString(vectorOfShapes[i]) << "\n";
            file << "PenJoin: " << getPenJoinString(vectorOfShapes[i]) << "\n";
            file << "BrushColor: " << getBrushColorString(vectorOfShapes[i]) << "\n";
            file << "BrushStyle: " << getBrushStyleString(vectorOfShapes[i]) << "\n";
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
        return "solid line";
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
        return "square cap";
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
        return "bevel join";
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


