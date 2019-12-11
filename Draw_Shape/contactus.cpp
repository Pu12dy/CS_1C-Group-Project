#include "contactus.h"
#include "ui_contactus.h"

//! ContactUs(QWidget *parent)
//! Constructor
//! Makes the Contact Us window
ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    this->setWindowTitle("Contact Us");
}

//! ~ContactUs()
//! Destructor
//! Deletes the ui pointer
ContactUs::~ContactUs()
{
    delete ui;
}
