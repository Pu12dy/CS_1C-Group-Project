#include "viewtestimonials.h"
#include "ui_viewtestimonials.h"

//! viewTestimonials(QWidget *parent)
//! Constructor
//! Creates the Testimonials Window
viewTestimonials::viewTestimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewTestimonials)
{
    ui->setupUi(this);
    this->setWindowTitle("Testimonials");
    ui->username->setPlaceholderText("Your Name");
    ui->rating->setPlaceholderText("Out of 5");
    refreshTestimonial();


}

//! void refreshTestimonial()
//! Updates the Window with the latest testimonials
void viewTestimonials::refreshTestimonial()
{
    QFile file("Testimonials.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    ui->priorTestimonials->setText(in.readAll());
    file.close();
}

//! ~viewTestimonials()
//! Destructor
viewTestimonials::~viewTestimonials()
{

    for (int i = 0; i < testimonials.size(); i++)
    {
        delete testimonials[i];
    }
    delete ui;
}

//! void addTestimonial(const QString userName, const QString rating, const QString testimonialTxt)
//! Opens the file where the testimonials are kept to display to the screen
void viewTestimonials::addTestimonial(const QString userName, const QString rating, const QString testimonialTxt)
{
    QFile file("Testimonials.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&file);
    out << "Name: " << userName; // << qSetFieldWidth(20)
    out << "\nRating: "<< rating << "/5\n";
    out << "Review:\n" << testimonialTxt << "\n\n";
    file.close();
    refreshTestimonial();
}


//! void on_addTestimonial_clicked()
//! Adds a testimonial to the file
void viewTestimonials::on_addTestimonial_clicked()
{
    QString username = ui->username->text();
    QString rating = ui->rating->text();
    QString userTestimonial = ui->userTestimonial->toPlainText();

    addTestimonial(username, rating, userTestimonial);
    ui->username->clear();
    ui->rating->clear();
    ui->userTestimonial->clear();
}


