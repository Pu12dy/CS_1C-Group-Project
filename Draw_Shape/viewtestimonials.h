#ifndef VIEWTESTIMONIALS_H
#define VIEWTESTIMONIALS_H

#include <QDialog>
#include "vector.h"
#include "Testimonial.h"
#include <QTextEdit>
#include "shapeParser.h"
#include<QFile>

namespace Ui {
class viewTestimonials;
}

class viewTestimonials : public QDialog
{
    Q_OBJECT

public:
    explicit viewTestimonials(QWidget *parent = 0);
    ~viewTestimonials();


private slots:
    void on_addTestimonial_clicked();

private:
    Ui::viewTestimonials *ui;
    Vector<Testimonial*>testimonials;
    void addTestimonial(const QString userName, const QString rating, const QString testimonialTxt);
    void refreshTestimonial();

};

#endif // VIEWTESTIMONIALS_H
