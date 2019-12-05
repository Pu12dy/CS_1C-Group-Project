#include "contactus.h"
#include "ui_contactus.h"

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    this->setWindowTitle("Contact Us");
}

ContactUs::~ContactUs()
{
    delete ui;
}
