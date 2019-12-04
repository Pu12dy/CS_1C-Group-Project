#include "canvas.h"

canvas::canvas(QWidget *parent) : QWidget(parent)
{
    //set background to white
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);


    //in actual project, need to pass in vector filled with info from text
    shape* sh1 = new rectangle(1,10,10,50,100, "blue", 3, "dash dot line", "round cap", "round join");
    shape* sh2 = new line();
    shape* sh3 = new text("Memory is leaking...");
    shape* sh4 = new rectangle(3,40,200, 100,120, Qt::yellow, 5, Qt::DashLine, Qt::FlatCap, Qt::MiterJoin);

    vectShape.push_back(sh1);
    vectShape.push_back(sh2);
    vectShape.push_back(sh3);
    vectShape.push_back(sh4);

    qDebug() << vectShapeParsed.size();
    vectShapeParsed = parseShapes("shapes.txt");
    qDebug() << vectShapeParsed.size();

}

void canvas::addShape(shape *p)
{
    //use whichever vector we decide
    vectShapeParsed.push_back(p);
}

void canvas::addNewLine(int shapeID, int x1, int y1, int x2, int y2)
{
    //NEED TO DELETE POINTED TO DATA!!
    shape* temp = new line(shapeID, x1, y1, x2, y2);
    addShape(temp);
}

void canvas::addNewRect(int shapeID, int x, int y, int l, int w)
{
    //NEED TO DELETE POINTED TO DATA!!
    shape* temp = new rectangle(shapeID, x, y, l, w);
    addShape(temp);
}


void canvas::paintEvent(QPaintEvent *event){
//    for(int i = 0; i < vectShape.size(); i++){
//        vectShape[i]->draw(this);
//    }

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


