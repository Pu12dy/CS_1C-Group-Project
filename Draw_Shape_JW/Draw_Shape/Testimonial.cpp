#include "Testimonial.h"

// class constructor
Testimonial::Testimonial()
{
    this->userName = " ";
    this->testimonialText = " ";
    this->rating = " ";
}
// class destructor
Testimonial::~Testimonial(){}
// class overloaded constructor
Testimonial::Testimonial(const QString& userNameRhs, const QString& testimonialTxtRhs, const QString& ratingRhs)
{
    this->userName = userNameRhs;
    this->testimonialText= testimonialTxtRhs;
    this->rating = ratingRhs;
}
// getter to get user name
QString Testimonial::getUserName() { return userName; }
// setter to set the user name passed by const ref
void Testimonial::setUserName(const QString &userNameIn) { this->userName = userNameIn;}
// getter to get the testimonial text
QString Testimonial::getTestimonialText() { return testimonialText; }
// setter to set the testimonial text passed by const ref
void Testimonial::setTestimonialText(const QString& testTxtIn) { this->testimonialText = testTxtIn; }
// getter to get the rating from the user
QString Testimonial::getRating() { return rating; }
// setter to set the rating passed by const ref
void Testimonial::setRating(const QString& ratingIn) {this->rating = ratingIn;}
