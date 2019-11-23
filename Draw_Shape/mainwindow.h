#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    void shapeChanged();
//    void penChanged();
//    void brushChanged();

    void on_actionExit_triggered();

    void on_actionLog_In_triggered();

private:
    Ui::MainWindow *ui;
//    QLabel    *penColorLabel;
//    QLabel    *penWidthLabel;
//    QLabel    *penStyleLabel;
//    QLabel    *penCapStyleLabel;
//    QLabel    *penJoinSyleLabel;
//    Qlabel    *brushColorLabel;
//    Qlabel    *brushStyleLabel;

//    QComboBox *penColorComboBox;
//    QSpinBox  *penWidthSpinBox;
//    QComboBox *penStyleComboBox;
//    QComboBox *penCapStyleComboBox;
//    QComboBox *penJoinStyleComboBox;
//    QComboBox *brushColorComboBox;
//    QComboBox *brushStyleComboBox;
};

#endif // MAINWINDOW_H
