#include "canvas.h"

//!
canvas::canvas(QWidget *parent) : QWidget(parent)
{
    //set background to white
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    vectShape = parseShapes("shapes.txt");

    assignShapeID();

}

canvas::~canvas()
{
    saveShapes("shapes.txt", vectShape);//save shapes to file
    for (int i = 0; i < vectShape.size(); i++) {
        delete vectShape[i];
    }
}

void canvas::assignShapeID()
{
    for(int i = 0; i < vectShape.size(); i++)
    {
       vectShape[i]->setShapeID(100 + i);
    }
}



void canvas::addNewLine(int shapeID, int x1, int y1, int x2, int y2)
{
    addShape(new line(shapeID, x1, y1, x2, y2));
}

void canvas::addNewRect(int shapeID, int x, int y, int l, int w)
{
    addShape(new rectangle(shapeID, x, y, l, w));
}

void canvas::paintEvent(QPaintEvent *event){

    for(int i = 0; i < vectShape.size(); i++){
        vectShape[i]->draw(this);
    }
}

shape* canvas::get(int a)
{
    return vectShape[a];
}


int canvas::numberOfShapes()
{
    return vectShape.size();
}

void canvas::moveShape(int shapeIndex, int offSetX, int offSetY)// Need to add limits to moving the shape, prevent shape from exiting screen
{
    vectShape[shapeIndex]->moveShape(offSetX,offSetY);//call the shape's native
    this->update();
}

void canvas::setPenColor(int shapeIndex, std::string color)
{
    vectShape[shapeIndex]->setPenColor(color);//call the shape's native
    this->update();
}

void canvas::setPenWidth(int shapeIndex, int penWidth)
{
    vectShape[shapeIndex]->setPenWidth(penWidth);//call the shape's native
    this->update();
}

void canvas::setPenStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setPenStyle(style);//call the shape's native
    this->update();
}

void canvas::setPenCapStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setPenCapStyle(style);//call the shape's native
    this->update();
}

void canvas::setPenJoinStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setPenJoinStyle(style);//call the shape's native
    this->update();
}

void canvas::setBrushColor(int shapeIndex, std::string color)
{
    vectShape[shapeIndex]->setBrushColor(color);//call the shape's native
    this->update();
}
void canvas::setBrushStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setBrushStyle(style);//call the shape's native
    this->update();
}

void canvas::setTextString(int shapeIndex, std::string text)
{
    vectShape[shapeIndex]->setTextString(text);//call the shape's native
    this->update();
}

void canvas::setTextColor(int shapeIndex, std::string textColor)
{
    vectShape[shapeIndex]->setTextColor(textColor);//call the shape's native
    this->update();
}

void canvas::setTextAlignment(int shapeIndex, std::string textAlign)
{
    vectShape[shapeIndex]->setTextAlignment(textAlign);//call the shape's native
    this->update();
}

void canvas::setTextPointSize(int shapeIndex, int textPointSize)
{
    vectShape[shapeIndex]->setTextPointSize(textPointSize);//call the shape's native
    this->update();
}

void canvas::setTextFontFamily(int shapeIndex, std::string textFont)
{
    vectShape[shapeIndex]->setTextFontFamily(textFont);//call the shape's native
    this->update();
}

void canvas::setTextFontStyle(int shapeIndex, std::string textFStyle)
{
    vectShape[shapeIndex]->setTextFontStyle(textFStyle);//call the shape's native
    this->update();
}

void canvas::setTextFontWeight(int shapeIndex, std::string textFWeight)
{
    vectShape[shapeIndex]->setTextFontWeight(textFWeight);//call the shape's native
    this->update();
}

void canvas::addShape(int shape)
{
    switch (shape)
    {
    case 1:
        addShape(new rectangle());
        break;
    case 2:
        addShape(new line());
        break;
    case 3:
        addShape(new ellipse());
        break;
    case 4:
        addShape(new polyline());
        break;
    case 5:
        addShape(new polygon());
        break;
    case 6:
        addShape(new text());
        break;
    default:
        break;
    }

}

void canvas::addShape(shape *p)
{
    //use whichever vector we decide
    vectShape.push_back(p);
    assignShapeID();
    this->update();
}

void canvas::changeShapeSize(int shapeIndex, int newSize)
{
    vectShape[shapeIndex]->changeShapeSize(newSize);
    this->update();
}

void canvas::removeShape(int index)
{
    vectShape.erase(&vectShape[index]);
    this->update();
}

void canvas::makeSquareOrCircle(int index)
{
    vectShape[index]->makeSquareOrCircle();
    this->update();
}
void canvas::moveNode(int shapeIndex, int node, int offSetX, int offSetY)
{
    vectShape[shapeIndex]->moveNode(node, offSetX, offSetY);
    this->update();
}

void canvas::addNode(int shapeIndex, int node)
{
    vectShape[shapeIndex]->addNode(node);
    this->update();
}
void canvas::removeNode(int shapeIndex, int node)
{
    vectShape[shapeIndex]->removeNode(node);
    this->update();
}

void canvas::shapeReport()
{
    QString report = "";

    // TESTING sort
    selection_sort(vectShape.begin(), vectShape.end(), Cmp_by_id());
    for(int i = 0; i < vectShape.size(); i++)
    {
       report += "ShapeID[" + QString::number(i) + "] " + QString::fromStdString(vectShape[i]->getShapeType()) + " = " + QString::fromStdString(vectShape[i]->getID()) + "\n";
    }

    selection_sort(vectShape.begin(), vectShape.end(), Cmp_by_perimeter());
    // TESTING perimeter
    for(int i = 0; i < vectShape.size(); i++)
    {
       report += "Perimeter[" + QString::number(i) + "] " + QString::fromStdString(vectShape[i]->getShapeType()) + " = " + QString::number(vectShape[i]->perimeter()) + "\n";
    }

   selection_sort(vectShape.begin(), vectShape.end(), Cmp_by_area());
   // TESTING area
    for(int i = 0; i < vectShape.size(); i++)
    {
       report += "Area[" + QString::number(i) + "] " + QString::fromStdString(vectShape[i]->getShapeType()) + " = " + QString::number(vectShape[i]->area()) + "\n";
    }
    QMessageBox::information(this, "Report", report);
}
