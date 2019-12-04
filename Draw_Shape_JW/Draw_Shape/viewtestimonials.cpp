#include "viewtestimonials.h"
#include "ui_viewtestimonials.h"

viewTestimonials::viewTestimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewTestimonials)
{
    ui->setupUi(this);
}

viewTestimonials::~viewTestimonials()
{
    delete ui;
}

void viewTestimonials::addTestimonial(Testimonial* newTestimonial)
{
    testimonials.push_back(newTestimonial);
}


