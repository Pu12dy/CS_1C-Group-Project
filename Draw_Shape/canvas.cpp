#include "canvas.h"

canvas::canvas(QWidget *parent) : QWidget(parent)
{
    //set background to white
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);


    //in actual project, need to pass in vector filled with info from text
    shape* sh1 = new rectangle();
    shape* sh2 = new line();
    shape* sh3 = new text("Hello");

    vectShape.push_back(sh1);
    vectShape.push_back(sh2);
    vectShape.push_back(sh3);

}

void canvas::drawVect(){
    update();
}

void canvas::paintEvent(QPaintEvent *event){
    for(int i = 0; i < vectShape.size(); i++){
        vectShape[i]->draw(this);
    }

}


