#include "Testimonial.h"

//! Testimonial()
//! Class constructor
Testimonial::Testimonial()
{
    this->userName = "";
    this->testimonialText = "";
    this->rating = "";
}

//! ~Testimonial()
//! Class destructor
Testimonial::~Testimonial()
{

}

//! Testimonial(const QString userNameRhs, const QString testimonialTxtRhs, const QString ratingRhs)
//! Class overloaded constructor
Testimonial::Testimonial(const QString userNameRhs, const QString testimonialTxtRhs, const QString ratingRhs)
{
    this->userName = userNameRhs;
    this->testimonialText= testimonialTxtRhs;
    this->rating = ratingRhs;
}

//! QString getUserName()
//! Getter to get user name
QString Testimonial::getUserName() { return userName; }

//! void setUserName(const QString &userNameIn)
//! Setter to set the user name passed by const ref
void Testimonial::setUserName(const QString &userNameIn) { this->userName = userNameIn;}

//! QString getTestimonialText()
//! Getter to get the testimonial text
QString Testimonial::getTestimonialText() { return testimonialText; }

//! void setTestimonialText(const QString testTxtIn)
//! Setter to set the testimonial text passed by const ref
void Testimonial::setTestimonialText(const QString testTxtIn) { this->testimonialText = testTxtIn; }

//! QString getRating()
//! Getter to get the rating from the user
QString Testimonial::getRating() { return rating; }

//! void setRating(const QString ratingIn)
//! Setter to set the rating passed by const ref
void Testimonial::setRating(const QString ratingIn) {this->rating = ratingIn;}
