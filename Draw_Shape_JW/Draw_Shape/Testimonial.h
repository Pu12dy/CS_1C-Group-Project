#ifndef TESTIMONIAL_H
#define TESTIMONIAL_H

#include <QString>
using namespace std;


class Testimonial
{
public:
	// class constructor
    Testimonial();
	// class destructor
    ~Testimonial();
	// class overloaded constructor
    Testimonial(const QString& userNameRhs, const QString& testimonialTxtRhs, const QString& ratingRhs);
	// setter to set user id passed by const ref
    QString getUserName();
	// setter to set the user name passed by const ref
    void setUserName(const QString &userNameIn);
	// getter to get the testimonial text
    QString getTestimonialText();
	// setter to set the testimonial text passed by const ref
    void setTestimonialText(const QString& testTxtIn);
	// getter to get the rating from the user
    QString getRating();
	// setter to set the rating passed by const ref
    void setRating(const QString& ratingIn);
private:
    QString userName;
    QString testimonialText;
    QString rating;
};

#endif
