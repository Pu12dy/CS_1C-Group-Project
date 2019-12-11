#include "canvas.h"

//! canvas(QWidget *parent)
//! Constructor for the module that draws the shape
//! Background is white but can be changed by modifying
//! the enum pal.setColor
//! This module assigns the shape id. This is necessary to maintain
//! continuity if shapes get deleted
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

//! ~canvas()
//! Destructor
//! Deletes the saved shapes because they are dynamically allocated
canvas::~canvas()
{
    saveShapes("shapes.txt", vectShape);//save shapes to file
    for (int i = 0; i < vectShape.size(); i++) {
        delete vectShape[i];
    }
}

//! void assignShapeID()
//! Assigns the shape ids starting from 100
void canvas::assignShapeID()
{
    for(int i = 0; i < vectShape.size(); i++)
    {
       vectShape[i]->setShapeID(100 + i);
    }
}

//! void paintEvent(QPaintEvent *event)
//! This method draws the shapes onto the module
//! Does so by going through the vector of shapes
//! and calling each shape's draw method
void canvas::paintEvent(QPaintEvent *event){

    for(int i = 0; i < vectShape.size(); i++){
        vectShape[i]->draw(this);
    }
}

//! shape* canvas::get(int a) const
//! Gets the shape, used so mainwindow can call const functions
//! from each shape
shape* canvas::get(int a) const
{
    return vectShape[a];
}

//! int numberOfShapes()
//! Returns the number of shapes on screen
int canvas::numberOfShapes()
{
    return vectShape.size();
}


//! void moveShape(int shapeIndex, int offSetX, int offSetY)
//! Calls the shape specified by shapeIndex's move function
void canvas::moveShape(int shapeIndex, int offSetX, int offSetY)// Need to add limits to moving the shape, prevent shape from exiting screen
{
    vectShape[shapeIndex]->moveShape(offSetX,offSetY);//call the shape's native
    this->update();
}

//! void setPenColor(int shapeIndex, std::string color)
//! Calls the shape specified by shapeIndex's setPenColor function
void canvas::setPenColor(int shapeIndex, std::string color)
{
    vectShape[shapeIndex]->setPenColor(color);//call the shape's native
    this->update();
}

//! void setPenWidth(int shapeIndex, int penWidth)
//! Calls the shape specified by shapeIndex's setPenWidth function
void canvas::setPenWidth(int shapeIndex, int penWidth)
{
    vectShape[shapeIndex]->setPenWidth(penWidth);//call the shape's native
    this->update();
}

//! void setPenStyle(int shapeIndex, std::string style)
//! Calls the shape specified by shapeIndex's setPenStyle function
void canvas::setPenStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setPenStyle(style);//call the shape's native
    this->update();
}

//! void setPenCapStyle(int shapeIndex, std::string style)
//! Calls the shape specified by shapeIndex's setPenCapStyle function
void canvas::setPenCapStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setPenCapStyle(style);//call the shape's native
    this->update();
}

//! void setPenJoinStyle(int shapeIndex, std::string style)
//! Calls the shape specified by shapeIndex's setPenJoinStyle function
void canvas::setPenJoinStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setPenJoinStyle(style);//call the shape's native
    this->update();
}

//! void setBrushColor(int shapeIndex, std::string color)
//! Calls the shape specified by shapeIndex's setBrushColor function
void canvas::setBrushColor(int shapeIndex, std::string color)
{
    vectShape[shapeIndex]->setBrushColor(color);//call the shape's native
    this->update();
}

//! void setBrushStyle(int shapeIndex, std::string style)
//! Calls the shape specified by shapeIndex's setBrushStyle function
void canvas::setBrushStyle(int shapeIndex, std::string style)
{
    vectShape[shapeIndex]->setBrushStyle(style);//call the shape's native
    this->update();
}

//! void setTextString(int shapeIndex, std::string text)
//! Calls the shape specified by shapeIndex's setTextString function
void canvas::setTextString(int shapeIndex, std::string text)
{
    vectShape[shapeIndex]->setTextString(text);//call the shape's native
    this->update();
}

//! void setTextColor(int shapeIndex, std::string textColor)
//! Calls the shape specified by shapeIndex's setTextColor function
void canvas::setTextColor(int shapeIndex, std::string textColor)
{
    vectShape[shapeIndex]->setTextColor(textColor);//call the shape's native
    this->update();
}

//! void setTextAlignment(int shapeIndex, std::string textAlign)
//! Calls the shape specified by shapeIndex's setTextAlignment function
void canvas::setTextAlignment(int shapeIndex, std::string textAlign)
{
    vectShape[shapeIndex]->setTextAlignment(textAlign);//call the shape's native
    this->update();
}

//! void setTextPointSize(int shapeIndex, int textPointSize)
//! Calls the shape specified by shapeIndex's setTextPointSize function
void canvas::setTextPointSize(int shapeIndex, int textPointSize)
{
    vectShape[shapeIndex]->setTextPointSize(textPointSize);//call the shape's native
    this->update();
}

//! void setTextFontFamily(int shapeIndex, std::string textFont)
//! Calls the shape specified by shapeIndex's setTextFontFamily function
void canvas::setTextFontFamily(int shapeIndex, std::string textFont)
{
    vectShape[shapeIndex]->setTextFontFamily(textFont);//call the shape's native
    this->update();
}

//! void setTextFontStyle(int shapeIndex, std::string textFStyle)
//! Calls the shape specified by shapeIndex's setTextFontStyle function
void canvas::setTextFontStyle(int shapeIndex, std::string textFStyle)
{
    vectShape[shapeIndex]->setTextFontStyle(textFStyle);//call the shape's native
    this->update();
}

//! void setTextFontWeight(int shapeIndex, std::string textFWeight)
//! Calls the shape specified by shapeIndex's setTextFontWeight function
void canvas::setTextFontWeight(int shapeIndex, std::string textFWeight)
{
    vectShape[shapeIndex]->setTextFontWeight(textFWeight);//call the shape's native
    this->update();
}

//! void addShape(int shape)
//! Adds a new shape to screen by calling each shape's no-arg constructor
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

//! void addShape(shape *p)
//! Adds the newly created shape
//! to the shape vector holding all the shapes
void canvas::addShape(shape *p)
{
    //use whichever vector we decide
    vectShape.push_back(p);
    assignShapeID();
    this->update();
}

//! void changeShapeSize(int shapeIndex, int newSize)
//! Calls the shape specified by shapeIndex's changeShapeSize function
void canvas::changeShapeSize(int shapeIndex, int newSize)
{
    vectShape[shapeIndex]->changeShapeSize(newSize);
    this->update();
}

//! void removeShape(int index)
//! Removes a shape from the vector holding all the shapes
void canvas::removeShape(int index)
{
    vectShape.erase(&vectShape[index]);
    this->update();
}

//! void makeSquareOrCircle(int index)
//! Makes rectangle shapes into squares,
//! ellipse shapes into circles
void canvas::makeSquareOrCircle(int index)
{
    vectShape[index]->makeSquareOrCircle();
    this->update();
}

//! void moveNode(int shapeIndex, int node, int offSetX, int offSetY)
//! Moves the whole shape by the specified x and y pixel amounts
void canvas::moveNode(int shapeIndex, int node, int offSetX, int offSetY)
{
    vectShape[shapeIndex]->moveNode(node, offSetX, offSetY);
    this->update();
}

//! void addNode(int shapeIndex, int node)
//! Adds a node to polyline and polygon shapes
void canvas::addNode(int shapeIndex, int node)
{
    vectShape[shapeIndex]->addNode(node);
    this->update();
}

//! void removeNode(int shapeIndex, int node)
//! Removes a node to polyline and polygon shapes
void canvas::removeNode(int shapeIndex, int node)
{
    vectShape[shapeIndex]->removeNode(node);
    this->update();
}

//! void shapeReport()
//! Sorts the shapes and runs a report showing their perimeter and area
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
