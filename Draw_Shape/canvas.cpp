#include "canvas.h"

canvas::canvas(QWidget *parent) : QWidget(parent)
{
    //set background to white
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    QPoint pp1(100,150);
    QPoint pp2(600,220);
    QPoint pp3(160,400);
    QPoint pp4(500,280);

    vector<QPoint> QP;
    QP.push_back(pp1);
    QP.push_back(pp2);
    QP.push_back(pp3);
    QP.push_back(pp4);

    //in actual project, need to pass in vector filled with info from text
    shape* sh1 = new rectangle(1,10,10,50,100, "blue", 3, "dash dot line", "round cap", "round join");
    shape* sh2 = new line();
    shape* sh3 = new text("Memory is leaking...");
    shape* sh4 = new rectangle(3,40,200, 100,120, Qt::yellow, 5, Qt::DashLine, Qt::FlatCap, Qt::MiterJoin);
    shape* sh5 = new polyline();
    shape* sh6 = new polygon(189, QP);

    vectShape.push_back(sh1);
    vectShape.push_back(sh2);
    vectShape.push_back(sh3);
    vectShape.push_back(sh4);
    vectShape.push_back(sh5);
    vectShape.push_back(sh6);

    //qDebug() << vectShapeParsed.size();
    //vectShapeParsed = parseShapes("shapes.txt"); // Commented out because shape parser needs fixing, does not close program gracefully if shapes.txt not found
    //qDebug() << vectShapeParsed.size();

}

void canvas::addShape(shape *p)
{
    //use whichever vector we decide
    vectShapeParsed.push_back(p);
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

    for(int i = 0; i < vectShapeParsed.size(); ++i){
        vectShapeParsed[i]->draw(this);
    }
//    vectShapeParsed[0]->draw(this);


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
