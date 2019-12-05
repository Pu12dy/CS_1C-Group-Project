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
    enableAdminFunctions = false;
    ui->adminFuncs->setVisible(false);
    logWindow = new login(this);
    connect(logWindow, &login::userIsAdmin, this, &MainWindow::userIsAdmin);

}


MainWindow::~MainWindow()
{
    delete logWindow;
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionLog_In_triggered()
{
    logWindow->setModal(true);
    logWindow->exec();
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

bool MainWindow::adminStatus()
{
    return enableAdminFunctions;
}

void MainWindow::userIsAdmin()
{

    QMessageBox::information(this, "Login", "Username and Password is Correct");
    enableAdminFunctions = true;
    ui->adminFuncs->setVisible(true);

}

void MainWindow::on_actionLogout_triggered()
{
    ui->adminFuncs->setVisible(false);
}
