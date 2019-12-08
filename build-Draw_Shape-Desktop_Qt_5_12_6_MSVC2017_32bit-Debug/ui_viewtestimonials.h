/********************************************************************************
** Form generated from reading UI file 'viewtestimonials.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTESTIMONIALS_H
#define UI_VIEWTESTIMONIALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewTestimonials
{
public:
    QTextBrowser *priorTestimonials;
    QLabel *addReviewLabel;
    QTextEdit *userTestimonial;
    QPushButton *addTestimonial;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *getName;
    QLabel *name;
    QLineEdit *username;
    QHBoxLayout *getRating;
    QLineEdit *rating;
    QLabel *label_2;

    void setupUi(QDialog *viewTestimonials)
    {
        if (viewTestimonials->objectName().isEmpty())
            viewTestimonials->setObjectName(QString::fromUtf8("viewTestimonials"));
        viewTestimonials->resize(1000, 738);
        priorTestimonials = new QTextBrowser(viewTestimonials);
        priorTestimonials->setObjectName(QString::fromUtf8("priorTestimonials"));
        priorTestimonials->setGeometry(QRect(10, 10, 971, 401));
        addReviewLabel = new QLabel(viewTestimonials);
        addReviewLabel->setObjectName(QString::fromUtf8("addReviewLabel"));
        addReviewLabel->setGeometry(QRect(10, 420, 111, 31));
        userTestimonial = new QTextEdit(viewTestimonials);
        userTestimonial->setObjectName(QString::fromUtf8("userTestimonial"));
        userTestimonial->setGeometry(QRect(10, 490, 971, 191));
        addTestimonial = new QPushButton(viewTestimonials);
        addTestimonial->setObjectName(QString::fromUtf8("addTestimonial"));
        addTestimonial->setGeometry(QRect(859, 690, 111, 25));
        layoutWidget = new QWidget(viewTestimonials);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 450, 290, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        getName = new QHBoxLayout();
        getName->setObjectName(QString::fromUtf8("getName"));
        name = new QLabel(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));

        getName->addWidget(name);

        username = new QLineEdit(layoutWidget);
        username->setObjectName(QString::fromUtf8("username"));

        getName->addWidget(username);


        horizontalLayout->addLayout(getName);

        getRating = new QHBoxLayout();
        getRating->setObjectName(QString::fromUtf8("getRating"));
        rating = new QLineEdit(layoutWidget);
        rating->setObjectName(QString::fromUtf8("rating"));

        getRating->addWidget(rating);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        getRating->addWidget(label_2);


        horizontalLayout->addLayout(getRating);


        retranslateUi(viewTestimonials);

        QMetaObject::connectSlotsByName(viewTestimonials);
    } // setupUi

    void retranslateUi(QDialog *viewTestimonials)
    {
        viewTestimonials->setWindowTitle(QApplication::translate("viewTestimonials", "Dialog", nullptr));
        addReviewLabel->setText(QApplication::translate("viewTestimonials", "Add Your Review:", nullptr));
        addTestimonial->setText(QApplication::translate("viewTestimonials", "Add Review", nullptr));
        name->setText(QApplication::translate("viewTestimonials", "Name:", nullptr));
        label_2->setText(QApplication::translate("viewTestimonials", "/5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewTestimonials: public Ui_viewTestimonials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTESTIMONIALS_H
