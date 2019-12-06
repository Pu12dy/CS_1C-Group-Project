#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < ui->widget->numberOfShapes();i++)// Populate shapes into shape selector
    {
        ui->selectShape->addItem(QString::fromStdString(std::to_string(ui->widget->get(i)->getShapeID())));
    }

    //Populating the pen color drop down box
    ui->penColor_list->addItem("Select");
    ui->penColor_list->addItem("White");
    ui->penColor_list->addItem("Black");
    ui->penColor_list->addItem("Red");
    ui->penColor_list->addItem("Green");
    ui->penColor_list->addItem("Blue");
    ui->penColor_list->addItem("Cyan");
    ui->penColor_list->addItem("Magenta");
    ui->penColor_list->addItem("Yellow");
    ui->penColor_list->addItem("Gray");

    //Populating Pen Style
    ui->penStyle_list->addItem("Select");
    ui->penStyle_list->addItem("No Pen");
    ui->penStyle_list->addItem("Solid Line");
    ui->penStyle_list->addItem("Dash Line");
    ui->penStyle_list->addItem("Dot Line");
    ui->penStyle_list->addItem("Dash Dot Line");
    ui->penStyle_list->addItem("Dash Dot Dot Line");


    //Populating Pen Cap Style
    ui->penCapStyle_list->addItem("Select");
    ui->penCapStyle_list->addItem("Flat Cap");
    ui->penCapStyle_list->addItem("Square Cap");
    ui->penCapStyle_list->addItem("Round Cap");

    //Populationg Pen Join Style
    ui->penJoinStyle_list->addItem("Select");
    ui->penJoinStyle_list->addItem("MiterJoin");
    ui->penJoinStyle_list->addItem("BevelJoin");
    ui->penJoinStyle_list->addItem("RoundJoin");

    //Populating the brush color drop down box
    ui->brushColor_list->addItem("Select");
    ui->brushColor_list->addItem("White");
    ui->brushColor_list->addItem("Black");
    ui->brushColor_list->addItem("Red");
    ui->brushColor_list->addItem("Green");
    ui->brushColor_list->addItem("Blue");
    ui->brushColor_list->addItem("Cyan");
    ui->brushColor_list->addItem("Magenta");
    ui->brushColor_list->addItem("Yellow");
    ui->brushColor_list->addItem("Gray");

    //Populating the brush style drop down box
    ui->brushStyle_list->addItem("Select");
    ui->brushStyle_list->addItem("SolidPattern");
    ui->brushStyle_list->addItem("HorPattern");
    ui->brushStyle_list->addItem("VerPattern");
    ui->brushStyle_list->addItem("NoBrush");


    //ui->adminFuncs->setVisible(false);


}


MainWindow::~MainWindow()
{
    //delete logWindow;
    //delete activeShape;
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionLog_In_triggered()
{
    login logWindow;
    connect(&logWindow, &login::userIsAdmin, this, &MainWindow::userIsAdmin);
    logWindow.setModal(true);
    logWindow.exec();
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

void MainWindow::userIsAdmin()
{

    QMessageBox::information(this, "Login", "Username and Password is Correct");
    ui->adminFuncs->setVisible(true);

}

void MainWindow::on_actionLogout_triggered()
{
    ui->adminFuncs->setVisible(false);
}

void MainWindow::on_moveShape_clicked()
{
    int offSetX = ui->offSetX_lineEdit->text().toInt();
    int offSetY = ui->offSetY_lineEdit->text().toInt();
    ui->widget->moveShape(ui->selectShape->currentIndex(), offSetX, offSetY);
    ui->offSetX_lineEdit->clear();
    ui->offSetY_lineEdit->clear();

}

void MainWindow::on_changePen_clicked()
{
    if  (ui->penColor_list->currentIndex() > 0)// Change pen color
    {
        ui->widget->setPenColor(ui->selectShape->currentIndex(), ui->penColor_list->currentText().toLower().toStdString());
    }

    // Change pen width
    if (ui->penWidth_lineEdit->text().toInt() >= 0 && ui->penWidth_lineEdit->text().toInt() <= 20 )
    {
        ui->widget->setPenWidth(ui->selectShape->currentIndex(), ui->penWidth_lineEdit->text().toInt());
    }

    // Change pen style
    if (ui->penStyle_list->currentIndex() > 0)
    {
        ui->widget->setPenStyle(ui->selectShape->currentIndex(), ui->penStyle_list->currentText().toLower().toStdString());
    }

    // Change pen cap style
    if (ui->penCapStyle_list->currentIndex() > 0)
    {
        ui->widget->setPenCapStyle(ui->selectShape->currentIndex(), ui->penCapStyle_list->currentText().toLower().toStdString());
    }

    //Change pen join Style
    if (ui->penJoinStyle_list->currentIndex() > 0)
    {
        ui->widget->setPenCapStyle(ui->selectShape->currentIndex(), ui->penJoinStyle_list->currentText().toLower().toStdString());
    }
}

void MainWindow::on_changeBrush_clicked()
{
    //Change brush color
    if (ui->brushColor_list->currentIndex() > 0)
    {
        ui->widget->setBrushColor(ui->selectShape->currentIndex(), ui->brushColor_list->currentText().toLower().toStdString());
    }

    //Change brush Style
    if (ui->brushStyle_list->currentIndex() > 0)
    {
        ui->widget->setBrushStyle(ui->selectShape->currentIndex(), ui->brushStyle_list->currentText().toLower().toStdString());
    }
}
