/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <canvas.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLog_In;
    QAction *actionExit;
    QAction *actionContact_Us;
    QAction *actionTestimonials;
    QAction *actionLogout;
    QWidget *centralWidget;
    canvas *widget;
    QGroupBox *adminFuncs;
    QPushButton *moveShape;
    QWidget *layoutWidget;
    QHBoxLayout *moveShape_layout;
    QVBoxLayout *offSetX_layout;
    QLabel *offSet_label;
    QLineEdit *offSetX_lineEdit;
    QVBoxLayout *offSetY_layout;
    QLabel *offSetY_label;
    QLineEdit *offSetY_lineEdit;
    QGroupBox *penSettings;
    QWidget *layoutWidget1;
    QVBoxLayout *penColor_Layout;
    QLabel *penColor_label;
    QComboBox *penColor_list;
    QWidget *layoutWidget2;
    QVBoxLayout *penWidth_layout;
    QLabel *penWidth_label;
    QLineEdit *penWidth_lineEdit;
    QWidget *layoutWidget3;
    QVBoxLayout *penStyle_layout;
    QLabel *penStyle_label;
    QComboBox *penStyle_list;
    QWidget *layoutWidget4;
    QVBoxLayout *penCap_layout;
    QLabel *penCapStyle_label;
    QComboBox *penCapStyle_list;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout;
    QLabel *penJoinStyle_label;
    QComboBox *penJoinStyle_list;
    QPushButton *changePen;
    QGroupBox *brushSettings;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_2;
    QLabel *brushColor_label;
    QComboBox *brushColor_list;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_3;
    QLabel *brushStyle_label;
    QComboBox *brushStyle_list;
    QPushButton *changeBrush;
    QGroupBox *textSettings;
    QWidget *layoutWidget_2;
    QVBoxLayout *textColor_layout;
    QLabel *textColor_label;
    QComboBox *textColor_list;
    QWidget *layoutWidget_3;
    QVBoxLayout *textPointSize_layout;
    QLabel *textPointSize_labe;
    QLineEdit *textPointSize_lineEdit;
    QWidget *layoutWidget_4;
    QVBoxLayout *textAlignment_layout;
    QLabel *textAlignment_label;
    QComboBox *textAlignment_list;
    QWidget *layoutWidget_5;
    QVBoxLayout *textFontFamily_layout;
    QLabel *textFontFamily_label;
    QComboBox *textFontFamily_list;
    QWidget *layoutWidget_6;
    QVBoxLayout *textFontWeight_layout;
    QLabel *textFontWeight_label;
    QComboBox *textFontWeight_list;
    QWidget *layoutWidget_7;
    QVBoxLayout *textFontStyle_layout;
    QLabel *textFontStyle_label;
    QComboBox *textFontStyle_list;
    QPushButton *changeText;
    QWidget *layoutWidget_8;
    QVBoxLayout *textString_layout;
    QLabel *textString_label;
    QLineEdit *textString_lineEdit;
    QPushButton *pushButton;
    QWidget *layoutWidget8;
    QVBoxLayout *selectShape_layout;
    QLabel *selectShape_label;
    QComboBox *selectShape;
    QWidget *layoutWidget9;
    QVBoxLayout *createShape_layout;
    QLabel *createShape_label;
    QComboBox *createNewShape_Box;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1307, 699);
        actionLog_In = new QAction(MainWindow);
        actionLog_In->setObjectName(QString::fromUtf8("actionLog_In"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/login.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionLog_In->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("img/1024px-Oxygen480-actions-application-exit.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionContact_Us = new QAction(MainWindow);
        actionContact_Us->setObjectName(QString::fromUtf8("actionContact_Us"));
        actionTestimonials = new QAction(MainWindow);
        actionTestimonials->setObjectName(QString::fromUtf8("actionTestimonials"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new canvas(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1000, 500));
        widget->setMaximumSize(QSize(1000, 500));
        adminFuncs = new QGroupBox(centralWidget);
        adminFuncs->setObjectName(QString::fromUtf8("adminFuncs"));
        adminFuncs->setGeometry(QRect(1020, 10, 271, 641));
        moveShape = new QPushButton(adminFuncs);
        moveShape->setObjectName(QString::fromUtf8("moveShape"));
        moveShape->setGeometry(QRect(210, 20, 51, 41));
        layoutWidget = new QWidget(adminFuncs);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 20, 120, 43));
        moveShape_layout = new QHBoxLayout(layoutWidget);
        moveShape_layout->setSpacing(6);
        moveShape_layout->setContentsMargins(11, 11, 11, 11);
        moveShape_layout->setObjectName(QString::fromUtf8("moveShape_layout"));
        moveShape_layout->setContentsMargins(0, 0, 0, 0);
        offSetX_layout = new QVBoxLayout();
        offSetX_layout->setSpacing(6);
        offSetX_layout->setObjectName(QString::fromUtf8("offSetX_layout"));
        offSet_label = new QLabel(layoutWidget);
        offSet_label->setObjectName(QString::fromUtf8("offSet_label"));

        offSetX_layout->addWidget(offSet_label);

        offSetX_lineEdit = new QLineEdit(layoutWidget);
        offSetX_lineEdit->setObjectName(QString::fromUtf8("offSetX_lineEdit"));

        offSetX_layout->addWidget(offSetX_lineEdit);


        moveShape_layout->addLayout(offSetX_layout);

        offSetY_layout = new QVBoxLayout();
        offSetY_layout->setSpacing(6);
        offSetY_layout->setObjectName(QString::fromUtf8("offSetY_layout"));
        offSetY_label = new QLabel(layoutWidget);
        offSetY_label->setObjectName(QString::fromUtf8("offSetY_label"));

        offSetY_layout->addWidget(offSetY_label);

        offSetY_lineEdit = new QLineEdit(layoutWidget);
        offSetY_lineEdit->setObjectName(QString::fromUtf8("offSetY_lineEdit"));

        offSetY_layout->addWidget(offSetY_lineEdit);


        moveShape_layout->addLayout(offSetY_layout);

        penSettings = new QGroupBox(adminFuncs);
        penSettings->setObjectName(QString::fromUtf8("penSettings"));
        penSettings->setGeometry(QRect(10, 70, 251, 171));
        layoutWidget1 = new QWidget(penSettings);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 121, 41));
        penColor_Layout = new QVBoxLayout(layoutWidget1);
        penColor_Layout->setSpacing(6);
        penColor_Layout->setContentsMargins(11, 11, 11, 11);
        penColor_Layout->setObjectName(QString::fromUtf8("penColor_Layout"));
        penColor_Layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        penColor_Layout->setContentsMargins(0, 0, 0, 0);
        penColor_label = new QLabel(layoutWidget1);
        penColor_label->setObjectName(QString::fromUtf8("penColor_label"));

        penColor_Layout->addWidget(penColor_label);

        penColor_list = new QComboBox(layoutWidget1);
        penColor_list->setObjectName(QString::fromUtf8("penColor_list"));
        penColor_list->setEditable(false);
        penColor_list->setFrame(true);

        penColor_Layout->addWidget(penColor_list);

        layoutWidget2 = new QWidget(penSettings);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(140, 20, 135, 41));
        penWidth_layout = new QVBoxLayout(layoutWidget2);
        penWidth_layout->setSpacing(6);
        penWidth_layout->setContentsMargins(11, 11, 11, 11);
        penWidth_layout->setObjectName(QString::fromUtf8("penWidth_layout"));
        penWidth_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        penWidth_layout->setContentsMargins(0, 0, 0, 0);
        penWidth_label = new QLabel(layoutWidget2);
        penWidth_label->setObjectName(QString::fromUtf8("penWidth_label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(penWidth_label->sizePolicy().hasHeightForWidth());
        penWidth_label->setSizePolicy(sizePolicy);

        penWidth_layout->addWidget(penWidth_label);

        penWidth_lineEdit = new QLineEdit(layoutWidget2);
        penWidth_lineEdit->setObjectName(QString::fromUtf8("penWidth_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(penWidth_lineEdit->sizePolicy().hasHeightForWidth());
        penWidth_lineEdit->setSizePolicy(sizePolicy1);

        penWidth_layout->addWidget(penWidth_lineEdit);

        layoutWidget3 = new QWidget(penSettings);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 70, 121, 41));
        penStyle_layout = new QVBoxLayout(layoutWidget3);
        penStyle_layout->setSpacing(6);
        penStyle_layout->setContentsMargins(11, 11, 11, 11);
        penStyle_layout->setObjectName(QString::fromUtf8("penStyle_layout"));
        penStyle_layout->setContentsMargins(0, 0, 0, 0);
        penStyle_label = new QLabel(layoutWidget3);
        penStyle_label->setObjectName(QString::fromUtf8("penStyle_label"));

        penStyle_layout->addWidget(penStyle_label);

        penStyle_list = new QComboBox(layoutWidget3);
        penStyle_list->setObjectName(QString::fromUtf8("penStyle_list"));

        penStyle_layout->addWidget(penStyle_list);

        layoutWidget4 = new QWidget(penSettings);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(140, 70, 101, 41));
        penCap_layout = new QVBoxLayout(layoutWidget4);
        penCap_layout->setSpacing(6);
        penCap_layout->setContentsMargins(11, 11, 11, 11);
        penCap_layout->setObjectName(QString::fromUtf8("penCap_layout"));
        penCap_layout->setContentsMargins(0, 0, 0, 0);
        penCapStyle_label = new QLabel(layoutWidget4);
        penCapStyle_label->setObjectName(QString::fromUtf8("penCapStyle_label"));

        penCap_layout->addWidget(penCapStyle_label);

        penCapStyle_list = new QComboBox(layoutWidget4);
        penCapStyle_list->setObjectName(QString::fromUtf8("penCapStyle_list"));

        penCap_layout->addWidget(penCapStyle_list);

        layoutWidget5 = new QWidget(penSettings);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 120, 121, 41));
        verticalLayout = new QVBoxLayout(layoutWidget5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        penJoinStyle_label = new QLabel(layoutWidget5);
        penJoinStyle_label->setObjectName(QString::fromUtf8("penJoinStyle_label"));

        verticalLayout->addWidget(penJoinStyle_label);

        penJoinStyle_list = new QComboBox(layoutWidget5);
        penJoinStyle_list->setObjectName(QString::fromUtf8("penJoinStyle_list"));

        verticalLayout->addWidget(penJoinStyle_list);

        changePen = new QPushButton(penSettings);
        changePen->setObjectName(QString::fromUtf8("changePen"));
        changePen->setGeometry(QRect(140, 120, 101, 41));
        brushSettings = new QGroupBox(adminFuncs);
        brushSettings->setObjectName(QString::fromUtf8("brushSettings"));
        brushSettings->setGeometry(QRect(10, 240, 251, 71));
        layoutWidget6 = new QWidget(brushSettings);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 20, 81, 41));
        verticalLayout_2 = new QVBoxLayout(layoutWidget6);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        brushColor_label = new QLabel(layoutWidget6);
        brushColor_label->setObjectName(QString::fromUtf8("brushColor_label"));

        verticalLayout_2->addWidget(brushColor_label);

        brushColor_list = new QComboBox(layoutWidget6);
        brushColor_list->setObjectName(QString::fromUtf8("brushColor_list"));

        verticalLayout_2->addWidget(brushColor_list);

        layoutWidget7 = new QWidget(brushSettings);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(100, 20, 71, 41));
        verticalLayout_3 = new QVBoxLayout(layoutWidget7);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        brushStyle_label = new QLabel(layoutWidget7);
        brushStyle_label->setObjectName(QString::fromUtf8("brushStyle_label"));

        verticalLayout_3->addWidget(brushStyle_label);

        brushStyle_list = new QComboBox(layoutWidget7);
        brushStyle_list->setObjectName(QString::fromUtf8("brushStyle_list"));

        verticalLayout_3->addWidget(brushStyle_list);

        changeBrush = new QPushButton(brushSettings);
        changeBrush->setObjectName(QString::fromUtf8("changeBrush"));
        changeBrush->setGeometry(QRect(184, 22, 61, 31));
        textSettings = new QGroupBox(adminFuncs);
        textSettings->setObjectName(QString::fromUtf8("textSettings"));
        textSettings->setGeometry(QRect(10, 320, 251, 221));
        layoutWidget_2 = new QWidget(textSettings);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 70, 111, 41));
        textColor_layout = new QVBoxLayout(layoutWidget_2);
        textColor_layout->setSpacing(6);
        textColor_layout->setContentsMargins(11, 11, 11, 11);
        textColor_layout->setObjectName(QString::fromUtf8("textColor_layout"));
        textColor_layout->setContentsMargins(0, 0, 0, 0);
        textColor_label = new QLabel(layoutWidget_2);
        textColor_label->setObjectName(QString::fromUtf8("textColor_label"));

        textColor_layout->addWidget(textColor_label);

        textColor_list = new QComboBox(layoutWidget_2);
        textColor_list->setObjectName(QString::fromUtf8("textColor_list"));

        textColor_layout->addWidget(textColor_list);

        layoutWidget_3 = new QWidget(textSettings);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(130, 20, 111, 41));
        textPointSize_layout = new QVBoxLayout(layoutWidget_3);
        textPointSize_layout->setSpacing(6);
        textPointSize_layout->setContentsMargins(11, 11, 11, 11);
        textPointSize_layout->setObjectName(QString::fromUtf8("textPointSize_layout"));
        textPointSize_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        textPointSize_layout->setContentsMargins(0, 0, 0, 0);
        textPointSize_labe = new QLabel(layoutWidget_3);
        textPointSize_labe->setObjectName(QString::fromUtf8("textPointSize_labe"));
        sizePolicy.setHeightForWidth(textPointSize_labe->sizePolicy().hasHeightForWidth());
        textPointSize_labe->setSizePolicy(sizePolicy);

        textPointSize_layout->addWidget(textPointSize_labe);

        textPointSize_lineEdit = new QLineEdit(layoutWidget_3);
        textPointSize_lineEdit->setObjectName(QString::fromUtf8("textPointSize_lineEdit"));
        sizePolicy1.setHeightForWidth(textPointSize_lineEdit->sizePolicy().hasHeightForWidth());
        textPointSize_lineEdit->setSizePolicy(sizePolicy1);

        textPointSize_layout->addWidget(textPointSize_lineEdit);

        layoutWidget_4 = new QWidget(textSettings);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 120, 111, 41));
        textAlignment_layout = new QVBoxLayout(layoutWidget_4);
        textAlignment_layout->setSpacing(6);
        textAlignment_layout->setContentsMargins(11, 11, 11, 11);
        textAlignment_layout->setObjectName(QString::fromUtf8("textAlignment_layout"));
        textAlignment_layout->setContentsMargins(0, 0, 0, 0);
        textAlignment_label = new QLabel(layoutWidget_4);
        textAlignment_label->setObjectName(QString::fromUtf8("textAlignment_label"));

        textAlignment_layout->addWidget(textAlignment_label);

        textAlignment_list = new QComboBox(layoutWidget_4);
        textAlignment_list->setObjectName(QString::fromUtf8("textAlignment_list"));

        textAlignment_layout->addWidget(textAlignment_list);

        layoutWidget_5 = new QWidget(textSettings);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(130, 70, 111, 41));
        textFontFamily_layout = new QVBoxLayout(layoutWidget_5);
        textFontFamily_layout->setSpacing(6);
        textFontFamily_layout->setContentsMargins(11, 11, 11, 11);
        textFontFamily_layout->setObjectName(QString::fromUtf8("textFontFamily_layout"));
        textFontFamily_layout->setContentsMargins(0, 0, 0, 0);
        textFontFamily_label = new QLabel(layoutWidget_5);
        textFontFamily_label->setObjectName(QString::fromUtf8("textFontFamily_label"));

        textFontFamily_layout->addWidget(textFontFamily_label);

        textFontFamily_list = new QComboBox(layoutWidget_5);
        textFontFamily_list->setObjectName(QString::fromUtf8("textFontFamily_list"));

        textFontFamily_layout->addWidget(textFontFamily_list);

        layoutWidget_6 = new QWidget(textSettings);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 170, 111, 41));
        textFontWeight_layout = new QVBoxLayout(layoutWidget_6);
        textFontWeight_layout->setSpacing(6);
        textFontWeight_layout->setContentsMargins(11, 11, 11, 11);
        textFontWeight_layout->setObjectName(QString::fromUtf8("textFontWeight_layout"));
        textFontWeight_layout->setContentsMargins(0, 0, 0, 0);
        textFontWeight_label = new QLabel(layoutWidget_6);
        textFontWeight_label->setObjectName(QString::fromUtf8("textFontWeight_label"));

        textFontWeight_layout->addWidget(textFontWeight_label);

        textFontWeight_list = new QComboBox(layoutWidget_6);
        textFontWeight_list->setObjectName(QString::fromUtf8("textFontWeight_list"));

        textFontWeight_layout->addWidget(textFontWeight_list);

        layoutWidget_7 = new QWidget(textSettings);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(130, 120, 111, 41));
        textFontStyle_layout = new QVBoxLayout(layoutWidget_7);
        textFontStyle_layout->setSpacing(6);
        textFontStyle_layout->setContentsMargins(11, 11, 11, 11);
        textFontStyle_layout->setObjectName(QString::fromUtf8("textFontStyle_layout"));
        textFontStyle_layout->setContentsMargins(0, 0, 0, 0);
        textFontStyle_label = new QLabel(layoutWidget_7);
        textFontStyle_label->setObjectName(QString::fromUtf8("textFontStyle_label"));

        textFontStyle_layout->addWidget(textFontStyle_label);

        textFontStyle_list = new QComboBox(layoutWidget_7);
        textFontStyle_list->setObjectName(QString::fromUtf8("textFontStyle_list"));

        textFontStyle_layout->addWidget(textFontStyle_list);

        changeText = new QPushButton(textSettings);
        changeText->setObjectName(QString::fromUtf8("changeText"));
        changeText->setGeometry(QRect(130, 170, 111, 41));
        layoutWidget_8 = new QWidget(textSettings);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 20, 111, 41));
        textString_layout = new QVBoxLayout(layoutWidget_8);
        textString_layout->setSpacing(6);
        textString_layout->setContentsMargins(11, 11, 11, 11);
        textString_layout->setObjectName(QString::fromUtf8("textString_layout"));
        textString_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        textString_layout->setContentsMargins(0, 0, 0, 0);
        textString_label = new QLabel(layoutWidget_8);
        textString_label->setObjectName(QString::fromUtf8("textString_label"));
        sizePolicy.setHeightForWidth(textString_label->sizePolicy().hasHeightForWidth());
        textString_label->setSizePolicy(sizePolicy);

        textString_layout->addWidget(textString_label);

        textString_lineEdit = new QLineEdit(layoutWidget_8);
        textString_lineEdit->setObjectName(QString::fromUtf8("textString_lineEdit"));
        sizePolicy1.setHeightForWidth(textString_lineEdit->sizePolicy().hasHeightForWidth());
        textString_lineEdit->setSizePolicy(sizePolicy1);

        textString_layout->addWidget(textString_lineEdit);

        pushButton = new QPushButton(adminFuncs);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 550, 111, 51));
        layoutWidget8 = new QWidget(adminFuncs);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(10, 20, 71, 41));
        selectShape_layout = new QVBoxLayout(layoutWidget8);
        selectShape_layout->setSpacing(6);
        selectShape_layout->setContentsMargins(11, 11, 11, 11);
        selectShape_layout->setObjectName(QString::fromUtf8("selectShape_layout"));
        selectShape_layout->setContentsMargins(0, 0, 0, 0);
        selectShape_label = new QLabel(layoutWidget8);
        selectShape_label->setObjectName(QString::fromUtf8("selectShape_label"));

        selectShape_layout->addWidget(selectShape_label);

        selectShape = new QComboBox(layoutWidget8);
        selectShape->setObjectName(QString::fromUtf8("selectShape"));

        selectShape_layout->addWidget(selectShape);

        layoutWidget9 = new QWidget(adminFuncs);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(20, 550, 111, 51));
        createShape_layout = new QVBoxLayout(layoutWidget9);
        createShape_layout->setSpacing(6);
        createShape_layout->setContentsMargins(11, 11, 11, 11);
        createShape_layout->setObjectName(QString::fromUtf8("createShape_layout"));
        createShape_layout->setContentsMargins(0, 0, 0, 0);
        createShape_label = new QLabel(layoutWidget9);
        createShape_label->setObjectName(QString::fromUtf8("createShape_label"));

        createShape_layout->addWidget(createShape_label);

        createNewShape_Box = new QComboBox(layoutWidget9);
        createNewShape_Box->setObjectName(QString::fromUtf8("createNewShape_Box"));

        createShape_layout->addWidget(createNewShape_Box);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLog_In);
        menuFile->addAction(actionTestimonials);
        menuFile->addAction(actionContact_Us);
        menuFile->addAction(actionLogout);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLog_In->setText(QApplication::translate("MainWindow", "Log In...", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit...", nullptr));
        actionContact_Us->setText(QApplication::translate("MainWindow", "Contact Us", nullptr));
        actionTestimonials->setText(QApplication::translate("MainWindow", "Testimonials", nullptr));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", nullptr));
        adminFuncs->setTitle(QApplication::translate("MainWindow", "Admin Functionalities:", nullptr));
        moveShape->setText(QApplication::translate("MainWindow", "Move", nullptr));
        offSet_label->setText(QApplication::translate("MainWindow", "Offset X", nullptr));
        offSetY_label->setText(QApplication::translate("MainWindow", "Offset Y", nullptr));
        penSettings->setTitle(QApplication::translate("MainWindow", "Pen Settings", nullptr));
        penColor_label->setText(QApplication::translate("MainWindow", "Pen Color", nullptr));
        penWidth_label->setText(QApplication::translate("MainWindow", "Pen Width", nullptr));
        penStyle_label->setText(QApplication::translate("MainWindow", "Pen Style", nullptr));
        penCapStyle_label->setText(QApplication::translate("MainWindow", "Pen Cap Style", nullptr));
        penJoinStyle_label->setText(QApplication::translate("MainWindow", "Pen Join Style", nullptr));
        changePen->setText(QApplication::translate("MainWindow", "Update", nullptr));
        brushSettings->setTitle(QApplication::translate("MainWindow", "Brush Settings", nullptr));
        brushColor_label->setText(QApplication::translate("MainWindow", "Brush Color", nullptr));
        brushStyle_label->setText(QApplication::translate("MainWindow", "Brush Style", nullptr));
        changeBrush->setText(QApplication::translate("MainWindow", "Update", nullptr));
        textSettings->setTitle(QApplication::translate("MainWindow", "Text Settings", nullptr));
        textColor_label->setText(QApplication::translate("MainWindow", "Text Color", nullptr));
        textPointSize_labe->setText(QApplication::translate("MainWindow", "Text Point Size", nullptr));
        textAlignment_label->setText(QApplication::translate("MainWindow", "Text Alignment", nullptr));
        textFontFamily_label->setText(QApplication::translate("MainWindow", "Text Font Family", nullptr));
        textFontWeight_label->setText(QApplication::translate("MainWindow", "Text Font Weight", nullptr));
        textFontStyle_label->setText(QApplication::translate("MainWindow", "Text Font Style", nullptr));
        changeText->setText(QApplication::translate("MainWindow", "Update", nullptr));
        textString_label->setText(QApplication::translate("MainWindow", "Text String", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Remove Shape", nullptr));
        selectShape_label->setText(QApplication::translate("MainWindow", "Select Shape", nullptr));
        createShape_label->setText(QApplication::translate("MainWindow", "Create New Shape", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
