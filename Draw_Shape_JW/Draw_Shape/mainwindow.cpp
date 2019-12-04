#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < ui->widget->numberOfShapes();i++)
    {
        ui->selectShape->addItem(QString::fromStdString(std::to_string(ui->widget->get(i)->getShapeID())));
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionLog_In_triggered()
{
    login logWindow;
    logWindow.setModal(true);
    logWindow.exec();
}


void MainWindow::on_newShape_clicked()
{
    NewShape newShapeWindow;
    newShapeWindow.setModal(true);
    newShapeWindow.exec();
}

void MainWindow::on_actionContact_Us_triggered()
{
    ContactUs contact;
    contact.setModal(true);
    contact.exec();
}

void MainWindow::on_actionTestimonials_triggered()
{
    viewTestimonials testimonials;
    testimonials.setModal(true);
    testimonials.exec();
}
