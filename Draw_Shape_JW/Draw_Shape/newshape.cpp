#include "newshape.h"
#include "ui_newshape.h"

NewShape::NewShape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewShape)
{
    ui->setupUi(this);
    //For line page
    ui->x1LineInput_line->setPlaceholderText("500");
    ui->x2LineInput_line->setPlaceholderText("500");
    ui->y1LineInput_line->setPlaceholderText("250");
    ui->y2LineInput_line->setPlaceholderText("250");

}

NewShape::~NewShape()
{
    delete ui;
}

void NewShape::on_addLine_clicked()
{

}
