#ifndef TESTIMONIAL_H
#define TESTIMONIAL_H

#include <QString>
#include<QTextEdit>
using namespace std;


class Testimonial
{
public:
    //! Testimonial()
    //! Class constructor
    Testimonial();
    //! ~Testimonial()
    //! Class destructor
    ~Testimonial();
    //! Testimonial(const QString userNameRhs, const QString testimonialTxtRhs, const QString ratingRhs)
    //! Class overloaded constructor
    Testimonial(const QString userNameRhs, const QString testimonialTxtRhs, const QString ratingRhs);
    //! QString getUserName()
    //! Getter to get user name
    QString getUserName();
    //! void setUserName(const QString &userNameIn)
    //! Setter to set the user name passed by const ref
    void setUserName(const QString &userNameIn);
    //! void getTestimonialText()
    //! Getter to get the testimonial text passed by const ref
    QString getTestimonialText();
    //! void setTestimonialText(const QString testTxtIn)
    //! Setter to set the testimonial text passed by const ref
    void setTestimonialText(const QString testTxtIn);
    //! QString getRating()
    //! Getter to get the rating from the user
    QString getRating();
    //! void setRating(const QString ratingIn)
    //! Setter to set the rating passed by const ref
    void setRating(const QString ratingIn);
private:
    QString userName;
    QString testimonialText;
    QString rating;
};

#endif
