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
    //! viewTestimonials(QWidget *parent)
    //! Constructor
    //! Creates the Testimonials Window
    explicit viewTestimonials(QWidget *parent = 0);

    //! void refreshTestimonial()
    //! Updates the Window with the latest testimonials
    ~viewTestimonials();


private slots:

    //! void on_addTestimonial_clicked()
    //! Adds a testimonial to the file
    void on_addTestimonial_clicked();

private:
    //! Ui::viewTestimonials *ui
    //! Pointer to the window
    Ui::viewTestimonials *ui;

    //! Vector<Testimonial*>testimonials
    //! Vector of testimonial pointers
    //! Holds the testimonials loaded from file
    //! New testimonials
    Vector<Testimonial*>testimonials;

    //! void addTestimonial(const QString userName, const QString rating, const QString testimonialTxt)
    //! Opens the file where the testimonials are kept to display to the screen
    void addTestimonial(const QString userName, const QString rating, const QString testimonialTxt);

    //! void refreshTestimonial()
    //! Updates the Window with the latest testimonials
    void refreshTestimonial();

};

#endif // VIEWTESTIMONIALS_H
