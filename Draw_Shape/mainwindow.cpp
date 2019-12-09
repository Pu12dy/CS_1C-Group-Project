#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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
    ui->brushStyle_list->addItem("Solid Pattern");
    ui->brushStyle_list->addItem("Hor Pattern");
    ui->brushStyle_list->addItem("Ver Pattern");
    ui->brushStyle_list->addItem("No Brush");

    //Populating the text color drop down box
    ui->textColor_list->addItem("Select");
    ui->textColor_list->addItem("White");
    ui->textColor_list->addItem("Black");
    ui->textColor_list->addItem("Red");
    ui->textColor_list->addItem("Green");
    ui->textColor_list->addItem("Blue");
    ui->textColor_list->addItem("Cyan");
    ui->textColor_list->addItem("Magenta");
    ui->textColor_list->addItem("Yellow");
    ui->textColor_list->addItem("Gray");

    //Populating the text alignment drop down box
    ui->textAlignment_list->addItem("Select");
    ui->textAlignment_list->addItem("Align Left");
    ui->textAlignment_list->addItem("Align Right");
    ui->textAlignment_list->addItem("Align Top");
    ui->textAlignment_list->addItem("Align Bottom");
    ui->textAlignment_list->addItem("Align Center");

    //Populating the text font style drop down box
    ui->textFontStyle_list->addItem("Select");
    ui->textFontStyle_list->addItem("Style Normal");
    ui->textFontStyle_list->addItem("Style Italic");
    ui->textFontStyle_list->addItem("Style Oblique");

    //Populating the text font weight drop down box
    ui->textFontWeight_list->addItem("Select");
    ui->textFontWeight_list->addItem("Thin");
    ui->textFontWeight_list->addItem("Light");
    ui->textFontWeight_list->addItem("Normal");
    ui->textFontWeight_list->addItem("Bold");

    //Populating the text font family drop down box
    ui->textFontFamily_list->addItem("Select");
    ui->textFontFamily_list->addItem("Comic Sans MS");
    ui->textFontFamily_list->addItem("Courier");
    ui->textFontFamily_list->addItem("Helvetica");
    ui->textFontFamily_list->addItem("Times");

    // Populating the create new shape drop down box
    ui->createNewShape_list->addItem("Select");
    ui->createNewShape_list->addItem("Rectangle");
    ui->createNewShape_list->addItem("Line");
    ui->createNewShape_list->addItem("Ellipse");
    ui->createNewShape_list->addItem("Polyline");
    ui->createNewShape_list->addItem("Polygon");
    ui->createNewShape_list->addItem("Text");

    updateShapeSelectList();
    on_selectShape_activated(0);

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
    if (ui->selectShape->currentIndex() > 0)
    {
        if  (ui->penColor_list->currentIndex() > 0)// Change pen color
        {
            ui->widget->setPenColor(ui->selectShape->currentIndex() - 1, ui->penColor_list->currentText().toLower().toStdString());
        }

        // Change pen width
        if (ui->penWidth_lineEdit->text().toInt() >= 0 && ui->penWidth_lineEdit->text().toInt() <= 20 )
        {
            ui->widget->setPenWidth(ui->selectShape->currentIndex() - 1, ui->penWidth_lineEdit->text().toInt());
        }

        // Change pen style
        if (ui->penStyle_list->currentIndex() > 0)
        {
            ui->widget->setPenStyle(ui->selectShape->currentIndex() - 1, ui->penStyle_list->currentText().toLower().toStdString());
        }

        // Change pen cap style
        if (ui->penCapStyle_list->currentIndex() > 0)
        {
            ui->widget->setPenCapStyle(ui->selectShape->currentIndex() - 1, ui->penCapStyle_list->currentText().toLower().toStdString());
        }

        //Change pen join Style
        if (ui->penJoinStyle_list->currentIndex() > 0)
        {
            ui->widget->setPenCapStyle(ui->selectShape->currentIndex() - 1, ui->penJoinStyle_list->currentText().toLower().toStdString());
        }
    }

}

void MainWindow::on_changeBrush_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
    {
        //Change brush color
        if (ui->brushColor_list->currentIndex() > 0)
        {
            ui->widget->setBrushColor(ui->selectShape->currentIndex() - 1, ui->brushColor_list->currentText().toLower().toStdString());
        }

        //Change brush Style
        if (ui->brushStyle_list->currentIndex() > 0)
        {
            ui->widget->setBrushStyle(ui->selectShape->currentIndex() - 1, ui->brushStyle_list->currentText().toLower().toStdString());
        }
    }

}

void MainWindow::on_changeText_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
    {
        //Change text string
        if (ui->textString_lineEdit->text() != "")
        {
            ui->widget->setTextString(ui->selectShape->currentIndex() - 1, ui->textString_lineEdit->text().toStdString());
        }

        //Change text color
        if (ui->textColor_list->currentIndex() > 0)
        {
            ui->widget->setTextColor(ui->selectShape->currentIndex() - 1, ui->textColor_list->currentText().toLower().toStdString());
        }

        //Change text alignment
        if (ui->textAlignment_list->currentIndex() > 0)
        {
            ui->widget->setTextAlignment(ui->selectShape->currentIndex() - 1, ui->textAlignment_list->currentText().toLower().toStdString());
        }

        //Change text point size
        if (ui->textPointSize_lineEdit->text().toInt() > 0 && ui->textPointSize_lineEdit->text().toInt() <= 50 )
        {
            ui->widget->setTextPointSize(ui->selectShape->currentIndex() - 1, ui->textPointSize_lineEdit->text().toInt());
        }

        //Change text font family
        if (ui->textFontFamily_list->currentIndex() > 0)
        {
            ui->widget->setTextFontFamily(ui->selectShape->currentIndex() - 1, ui->textFontFamily_list->currentText().toLower().toStdString());
        }
        //Change text font weight
        if (ui->textFontWeight_list->currentIndex() > 0)
        {
            ui->widget->setTextFontWeight(ui->selectShape->currentIndex() - 1, ui->textFontWeight_list->currentText().toLower().toStdString());
        }
        //Change text font style
        if (ui->textFontStyle_list->currentIndex() > 0)
        {
            ui->widget->setTextFontStyle(ui->selectShape->currentIndex() - 1, ui->textFontStyle_list->currentText().toLower().toStdString());
        }
    }


}

void MainWindow::on_moveUp_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, 0, -50);
}

void MainWindow::on_moveLeft_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, -50, 0);
}

void MainWindow::on_moveRight_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, 50, 0);
}

void MainWindow::on_moveDown_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, 0, 50);
}

void MainWindow::on_createNewShape_Button_clicked()
{
   ui->widget->addShape(ui->createNewShape_list->currentIndex());
   updateShapeSelectList();
}

void MainWindow::updateShapeSelectList()
{
    ui->selectShape->clear();
    ui->selectShape->addItem("Select");
    for (int i = 0; i < ui->widget->numberOfShapes();i++)// Populate shapes into shape selector
    {
        ui->selectShape->addItem(QString::fromStdString(std::string(ui->widget->get(i)->getShapeName())));
    }
}

void MainWindow::on_selectShape_activated(int index)
{
    if (index == 0)
    {
        ui->penSettings->setEnabled(false);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(false);
    }
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Text")
    {
        ui->penSettings->setEnabled(false);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(true);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(false);
    }
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Line")
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(false);
    }
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Polyline")
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(true);
        ui->nodeSelect_list->clear();
        for (int i = 0; i < ui->widget->get(index - 1)->numberOfNodes(); i++)
        {
            ui->nodeSelect_list->addItem(QString::fromStdString(std::to_string(i+1)));
        }
    }
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Polygon")
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(true);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(true);
        ui->nodeSelect_list->clear();
        for (int i = 0; i < ui->widget->get(index - 1)->numberOfNodes(); i++)
        {
            ui->nodeSelect_list->addItem(QString::fromStdString(std::to_string(i+1)));
        }
    }
    else
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(true);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(false);
    }
}

void MainWindow::on_decreaseSize_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->changeShapeSize(ui->selectShape->currentIndex() - 1, -10);
}

void MainWindow::on_increaseSize_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->changeShapeSize(ui->selectShape->currentIndex() - 1, 10);
}

void MainWindow::on_removeShape_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
    {
        ui->widget->removeShape(ui->selectShape->currentIndex() - 1);
        updateShapeSelectList();
    }

}

void MainWindow::on_makeSqCir_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
    {
        if (ui->widget->get(ui->selectShape->currentIndex() - 1)->getShapeType() == "Rectangle" || ui->widget->get(ui->selectShape->currentIndex() - 1)->getShapeType() == "Ellipse")
        {
            ui->widget->makeSquareOrCircle(ui->selectShape->currentIndex() - 1);
        }
    }
    updateShapeSelectList();
    on_selectShape_activated(0);
}

void MainWindow::on_moveNode_up_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), 0, -10);
}

void MainWindow::on_moveNode_left_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), -10, 0);
}

void MainWindow::on_moveNode_down_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), 0, 10);
}

void MainWindow::on_moveNode_right_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), 10, 0);
}
