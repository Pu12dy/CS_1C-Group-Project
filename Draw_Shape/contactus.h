#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QDialog>

namespace Ui {
class ContactUs;
}

class ContactUs : public QDialog
{
    Q_OBJECT

public:
    //! ContactUs(QWidget *parent)
    //! Constructor
    //! Makes the Contact Us window
    explicit ContactUs(QWidget *parent = 0);

    //! ~ContactUs()
    //! Destructor
    //! Deletes the ui pointer
    ~ContactUs();

private:
    //! Ui::ContactUs *ui
    //! Holds the ui
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
