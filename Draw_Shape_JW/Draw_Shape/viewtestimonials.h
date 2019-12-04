#ifndef VIEWTESTIMONIALS_H
#define VIEWTESTIMONIALS_H

#include <QDialog>
#include "vector.h"
#include "Testimonial.h"

namespace Ui {
class viewTestimonials;
}

class viewTestimonials : public QDialog
{
    Q_OBJECT

public:
    explicit viewTestimonials(QWidget *parent = 0);
    ~viewTestimonials();
    void addTestimonial(Testimonial* newTestimonial);

private:
    Ui::viewTestimonials *ui;
    Vector<Testimonial*>testimonials;

};

#endif // VIEWTESTIMONIALS_H
