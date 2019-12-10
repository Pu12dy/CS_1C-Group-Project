#include "mainwindow.h"
#include "ui_mainwindow.h"

//! Mainwindow constructor.
/*!
 * The constructor creates a default empty window for the user to edit
 * This is done by using the drop down boxes to select shape/text, shape/text color,
 * size, style, and many other editing options.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /*!
    \Populates the pen color drop down box
    \Adds options to the pen color list
    */
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

    /*!
    \Populates Pen Style
    \Adds options to select the pen style
    */
    ui->penStyle_list->addItem("Select");
    ui->penStyle_list->addItem("No Pen");
    ui->penStyle_list->addItem("Solid Line");
    ui->penStyle_list->addItem("Dash Line");
    ui->penStyle_list->addItem("Dot Line");
    ui->penStyle_list->addItem("Dash Dot Line");
    ui->penStyle_list->addItem("Dash Dot Dot Line");

    /*!
    \Populates Pen Cap Style
    \Adds options to select cap style
    */
    ui->penCapStyle_list->addItem("Select");
    ui->penCapStyle_list->addItem("Flat Cap");
    ui->penCapStyle_list->addItem("Square Cap");
    ui->penCapStyle_list->addItem("Round Cap");

    /*!
    \Populates Pen Join Style
    */
    ui->penJoinStyle_list->addItem("Select");
    ui->penJoinStyle_list->addItem("Miter Join");
    ui->penJoinStyle_list->addItem("Bevel Join");
    ui->penJoinStyle_list->addItem("Round Join");

    /*!
    \Populates the brush color drop down box
    \Adds options to choose brush color
    */
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

    /*!
    \Populates the brush style drop down box
    \Adds options to choose brush style
    */
    ui->brushStyle_list->addItem("Select");
    ui->brushStyle_list->addItem("Solid Pattern");
    ui->brushStyle_list->addItem("Hor Pattern");
    ui->brushStyle_list->addItem("Ver Pattern");
    ui->brushStyle_list->addItem("No Brush");
    /*!
    \Populates the text color drop down box
    \Adds option to choose text's color
    */
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

    /*!
    \Populates the text alignment drop down box
    \Adds option to align text
    */
    ui->textAlignment_list->addItem("Select");
    ui->textAlignment_list->addItem("Align Left");
    ui->textAlignment_list->addItem("Align Right");
    ui->textAlignment_list->addItem("Align Top");
    ui->textAlignment_list->addItem("Align Bottom");
    ui->textAlignment_list->addItem("Align Center");

    /*!
    \Populates the text font style drop down box
    \Adds the option to choose font style: normal, Italic, Oblique
    */
    ui->textFontStyle_list->addItem("Select");
    ui->textFontStyle_list->addItem("Style Normal");
    ui->textFontStyle_list->addItem("Style Italic");
    ui->textFontStyle_list->addItem("Style Oblique");

    /*!
    \Populates the text font weight drop down box
    \Adds option to change the text weight: thin,light,normal,bold
    */
    ui->textFontWeight_list->addItem("Select");
    ui->textFontWeight_list->addItem("Thin");
    ui->textFontWeight_list->addItem("Light");
    ui->textFontWeight_list->addItem("Normal");
    ui->textFontWeight_list->addItem("Bold");

    /*!
    \Populates the text font family drop down box
    \Adds option to specify the font family: Comic Sans MS,Courier,Helvetica,Times
    */
    ui->textFontFamily_list->addItem("Select");
    ui->textFontFamily_list->addItem("Comic Sans MS");
    ui->textFontFamily_list->addItem("Courier");
    ui->textFontFamily_list->addItem("Helvetica");
    ui->textFontFamily_list->addItem("Times");

    /*!
    \Populates the create new shape drop down box
    \Adds option to choose and create a new shape
    \Options:Rectangle, Line, Ellipse, Polyline, Polygon, Text
    */
    ui->createNewShape_list->addItem("Select");
    ui->createNewShape_list->addItem("Rectangle");
    ui->createNewShape_list->addItem("Line");
    ui->createNewShape_list->addItem("Ellipse");
    ui->createNewShape_list->addItem("Polyline");
    ui->createNewShape_list->addItem("Polygon");
    ui->createNewShape_list->addItem("Text");

    updateShapeSelectList();
    on_selectShape_activated(0);

    //!obsures user interface to require the user to login
    ui->adminFuncs->setVisible(false);
    ui->additionalSettings_groupbox->setVisible(false);


}

//!~MainWindow()
/*!
 * deletes the pointer ui that generates the visual interface
 */
MainWindow::~MainWindow()
{
    delete ui;
}

//! A void member that takes no arguments and returns no values
//! Call on quit to exit Qt application
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

//! A void member function that takes no argument and returns no values
//! Method opens Login Dialog
void MainWindow::on_actionLog_In_triggered()
{
    login logWindow;
    connect(&logWindow, &login::userIsAdmin, this, &MainWindow::userIsAdmin);
    logWindow.setModal(true);
    logWindow.exec();
}

//!A normal member function that takes no arguments and returns no values
//!Method opens the Contact Us Dialog
void MainWindow::on_actionContact_Us_triggered()
{
    ContactUs contact;
    contact.setModal(true);
    contact.exec();
}

//!A void member function that takes no arguments and returns no values
//!Method opens Testimonials Dialog
void MainWindow::on_actionTestimonials_triggered()
{
    viewTestimonials testimonials;
    testimonials.setModal(true);
    testimonials.exec();
}

//!A void member function that takes no arguments and returns no values
//!Method allows user to have admin level access within the Qt environment
void MainWindow::userIsAdmin()
{

    QMessageBox::information(this, "Login", "Username and Password is Correct");
    ui->adminFuncs->setVisible(true);
    ui->additionalSettings_groupbox->setVisible(true);

}

//!A void member functions that takes no arguments and returns no values
//!Method allows a user to log out
//!Once the action of logging out is carried out all administrative functions
//!are hidden
void MainWindow::on_actionLogout_triggered()
{
    ui->adminFuncs->setVisible(false);
    ui->additionalSettings_groupbox->setVisible(false);
}

//!void MainWindow::on_moveShape_clicked()
//!Method allows user to move shape by entering in values X and Y
//!Method calls moveShape() from canvas.h
void MainWindow::on_moveShape_clicked()
{
    int offSetX = ui->offSetX_lineEdit->text().toInt();
    int offSetY = ui->offSetY_lineEdit->text().toInt();
    ui->widget->moveShape(ui->selectShape->currentIndex() - 1, offSetX, offSetY);
    ui->offSetX_lineEdit->clear();
    ui->offSetY_lineEdit->clear();
}

//!void on_changePen_clicked()
//!Method may call any of these methods from canvas.h
//!setPenColor()
//!setPenWidth()
//!setPenStyle()
//!setPenCapStyle()
//!setPenCapStyle()
void MainWindow::on_changePen_clicked()
{
    //!If shape selector is on "Select", function will do nothing
    if (ui->selectShape->currentIndex() > 0)
    {
        //!Change pen color
        if  (ui->penColor_list->currentIndex() > 0)
        {
            ui->widget->setPenColor(ui->selectShape->currentIndex() - 1, ui->penColor_list->currentText().toLower().toStdString());
        }

        //! Change pen width
        if (ui->penWidth_lineEdit->text().toInt() >= 0 && ui->penWidth_lineEdit->text().toInt() <= 20 )
        {
            ui->widget->setPenWidth(ui->selectShape->currentIndex() - 1, ui->penWidth_lineEdit->text().toInt());
        }

        //! Change pen style
        if (ui->penStyle_list->currentIndex() > 0)
        {
            ui->widget->setPenStyle(ui->selectShape->currentIndex() - 1, ui->penStyle_list->currentText().toLower().toStdString());
        }

        //! Change pen cap style
        if (ui->penCapStyle_list->currentIndex() > 0)
        {
            ui->widget->setPenCapStyle(ui->selectShape->currentIndex() - 1, ui->penCapStyle_list->currentText().toLower().toStdString());
        }

        //!Change pen join Style
        if (ui->penJoinStyle_list->currentIndex() > 0)
        {
            ui->widget->setPenCapStyle(ui->selectShape->currentIndex() - 1, ui->penJoinStyle_list->currentText().toLower().toStdString());
        }
    }

}

//!void on_changeBrush_clicked()
//!Method may call any of these methods from canvas.h
//!setBrushColor()
//!setBrushStyle()
//!Method updates brush attributes for selected shape
void MainWindow::on_changeBrush_clicked()
{
    //!If shape selector is on "Select", function will do nothing
    if (ui->selectShape->currentIndex() > 0)
    {
        //!Change brush color
        if (ui->brushColor_list->currentIndex() > 0)
        {
            ui->widget->setBrushColor(ui->selectShape->currentIndex() - 1, ui->brushColor_list->currentText().toLower().toStdString());
        }

        //!Change brush Style
        if (ui->brushStyle_list->currentIndex() > 0)
        {
            ui->widget->setBrushStyle(ui->selectShape->currentIndex() - 1, ui->brushStyle_list->currentText().toLower().toStdString());
        }
    }

}

//!void on_changeText_clicked()
//!Method may call any of these methods from canvas.h
//!setTextString()
//!setTextColor()
//!setTextAlignment()
//!setTextPointSize()
//!setTextPointSize()
//!setTextFontFamily()
//!setTextFontWeight()
//!setTextFontStyle()
//!Method updates text attributes for selected shape
void MainWindow::on_changeText_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
    {
        //!Change text string
        if (ui->textString_lineEdit->text() != "")
        {
            ui->widget->setTextString(ui->selectShape->currentIndex() - 1, ui->textString_lineEdit->text().toStdString());
        }

        //!Change text color
        if (ui->textColor_list->currentIndex() > 0)
        {
            ui->widget->setTextColor(ui->selectShape->currentIndex() - 1, ui->textColor_list->currentText().toLower().toStdString());
        }

        //!Change text alignment
        if (ui->textAlignment_list->currentIndex() > 0)
        {
            ui->widget->setTextAlignment(ui->selectShape->currentIndex() - 1, ui->textAlignment_list->currentText().toLower().toStdString());
        }

        //!Change text point size
        if (ui->textPointSize_lineEdit->text().toInt() > 0 && ui->textPointSize_lineEdit->text().toInt() <= 50 )
        {
            ui->widget->setTextPointSize(ui->selectShape->currentIndex() - 1, ui->textPointSize_lineEdit->text().toInt());
        }

        //!Change text font family
        if (ui->textFontFamily_list->currentIndex() > 0)
        {
            ui->widget->setTextFontFamily(ui->selectShape->currentIndex() - 1, ui->textFontFamily_list->currentText().toLower().toStdString());
        }
        //!Change text font weight
        if (ui->textFontWeight_list->currentIndex() > 0)
        {
            ui->widget->setTextFontWeight(ui->selectShape->currentIndex() - 1, ui->textFontWeight_list->currentText().toLower().toStdString());
        }
        //!Change text font style
        if (ui->textFontStyle_list->currentIndex() > 0)
        {
            ui->widget->setTextFontStyle(ui->selectShape->currentIndex() - 1, ui->textFontStyle_list->currentText().toLower().toStdString());
        }
    }
}

//!void on_moveUp_button_clicked()
//!Method implements the button called up
//!Method calls the moveShape method from canvas.h
//!to move currently selected shape up 10 pixels
void MainWindow::on_moveUp_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, 0, -50);
}

//!void on_moveLeft_button_clicked()
//!Method implements the button called left
//!Method calls the moveShape method from canvas.h
//!to move currently selected shape let 10 pixels
void MainWindow::on_moveLeft_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, -50, 0);
}

//!void on_moveRight_button_clicked()
//!Method implements the button called right
//!Method calls the moveShape method from canvas.h
//!to move currently selected shape right 10 pixels
void MainWindow::on_moveRight_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, 50, 0);
}

//!void on_moveDown_button_clicked()
//!Method implements the button called down
//!Method calls the moveShape method from canvas.h
//!to move currently selected shape down 10 pixels
void MainWindow::on_moveDown_button_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->moveShape(ui->selectShape->currentIndex() - 1, 0, 50);
}

//!void on_createNewShape_Button_clicked()
//!Method implements button Ok in the create a shape field
//!Method calls addShape method from canvas and passes in the
//!active shape name from createNewShape_list QComboBox
void MainWindow::on_createNewShape_Button_clicked()
{
   ui->widget->addShape(ui->createNewShape_list->currentIndex());
   updateShapeSelectList();
}

//!void updateShapeSelectList()
//!Helper method to update the list of selectable shapes
void MainWindow::updateShapeSelectList()
{
    ui->selectShape->clear();//! Clears list of objects so list can be rewritten
    ui->selectShape->addItem("Select");//! Adds placeholder 1st item
    for (int i = 0; i < ui->widget->numberOfShapes();i++)//! Populate shapes into shape selector by calling method getShapeName()
    {
        ui->selectShape->addItem(QString::fromStdString(std::string(ui->widget->get(i)->getShapeName())));
    }
}

//!void on_selectShape_activated(int index)
//!- index is integer value holding the current
//!  active selection in the selectShape QComboBox
//!Obscures certain functions based on the shape selected
//!Not the same action as logging out but the same effect
//!Functionalities are greyed out not invisible
void MainWindow::on_selectShape_activated(int index)
{
    //!Disable all functions if "Select" is active
    if (index == 0)
    {
        ui->penSettings->setEnabled(false);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(false);
    }
    //!Functions to show if shape selected is a Text type
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Text")
    {
        ui->penSettings->setEnabled(false);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(true);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->shapeSize_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(false);
    }
    //!Functions to show if shape selected is a Line type
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Line")
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(true);
        ui->addNode_box->setEnabled(false);
        updateNodeList(index - 1);
    }
    //!Functions to show if shape selected is a Polyline type
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Polyline")
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(false);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(true);
        ui->shapeSize_groupbox->setEnabled(true);
        ui->addNode_box->setEnabled(true);
        ui->nodeSelect_list->clear();
        updateNodeList(index - 1);
    }
    //!Functions to show if shape selected is a Polygon type
    else if (QString::fromStdString(ui->widget->get(index - 1)->getShapeType()) == "Polygon")
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(true);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(true);
        ui->shapeSize_groupbox->setEnabled(true);
        ui->addNode_box->setEnabled(true);
        ui->nodeSelect_list->clear();
        updateNodeList(index - 1);

    }
    //!Functions to show if shape selected any other type
    else
    {
        ui->penSettings->setEnabled(true);
        ui->brushSettings->setEnabled(true);
        ui->textSettings->setEnabled(false);
        ui->additionalSettings_groupbox->setEnabled(true);
        ui->adjPolys_box->setEnabled(false);
        ui->shapeSize_groupbox->setEnabled(true);
    }
}

//!void on_decreaseSize_clicked()
//!Method implements - button on shapeSize box
//!Method calls changeShapeSize from canvas for currently selected shape
//!Decreases size by 10 pixels
void MainWindow::on_decreaseSize_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->changeShapeSize(ui->selectShape->currentIndex() - 1, -10);
}
//!void on_increaseSize_clicked()
//!Method implements + button on shapeSize box
//!Method calls changeShapeSize from canvas for currently selected shape
//!Increases size by 10 pixels
void MainWindow::on_increaseSize_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
        ui->widget->changeShapeSize(ui->selectShape->currentIndex() - 1, 10);
}

//!void on_removeShape_clicked()
//!Method implements "Remove Shape" button on Additional Functions box
//!Method calls removeShape from canvas for currently selected shape
//!Updates selectShape list when done
void MainWindow::on_removeShape_clicked()
{
    if (ui->selectShape->currentIndex() > 0)
    {
        ui->widget->removeShape(ui->selectShape->currentIndex() - 1);
        updateShapeSelectList();
    }

}

//!void on_makeSqCir_clicked()
//!Method implements "Make Square or Circle" button on Additional Functions box
//!Method calls makeSquareOrCircle from canvas for currently selected shape
//!Only displayed for shapes of ellipse and rectangle type
//!Action cannot be undone
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

//!void on_moveNode_up_clicked()
//!Method implements the button called right
//!Method calls the moveNode method from canvas.h
//!to move currently selected node up 10 pixels
void MainWindow::on_moveNode_up_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), 0, -10);
}

//!void on_moveNode_left_clicked()
//!Method implements the button called right
//!Method calls the moveNode method from canvas.h
//!to move currently selected node left 10 pixels
void MainWindow::on_moveNode_left_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), -10, 0);
}

//!void on_moveNode_down_clicked()
//!Method implements the button called right
//!Method calls the moveNode method from canvas.h
//!to move currently selected node left 10 pixels
void MainWindow::on_moveNode_down_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), 0, 10);
}

//!void on_moveNode_left_clicked()
//!Method implements the button called right
//!Method calls the moveNode method from canvas.h
//!to move currently selected node left 10 pixels
void MainWindow::on_moveNode_right_clicked()
{
    ui->widget->moveNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex(), 10, 0);
}

//!void on_addNode_clicked()
//!Method implements the button + in the Add Node box
//!Method calls the addNode method from canvas.h
//!Only useable for polylines and polygon types
void MainWindow::on_addNode_clicked()
{

    ui->widget->addNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex());
    updateNodeList(ui->selectShape->currentIndex() - 1);
}

//!void on_addNode_clicked()
//!Method implements the button - in the Add Node box
//!Method calls the removeNode method from canvas.h
//!Does not allow less than 3 nodes in order to preserve shape
//!Only useable for polylines and polygon types
void MainWindow::on_removeNode_clicked()
{
    if (ui->widget->get(ui->selectShape->currentIndex() - 1)->numberOfNodes() > 3)
    {
        ui->widget->removeNode(ui->selectShape->currentIndex() - 1, ui->nodeSelect_list->currentIndex());
        updateNodeList(ui->selectShape->currentIndex() - 1);
    }

}

//!void updateNodeList(int index)
//!Method implements the button - in the Add Node box
//!Method calls the removeNode method from canvas.h
//!Does not allow less than 3 nodes in order to preserve shape
//!Only useable for polylines and polygon types
void MainWindow::updateNodeList(int index)
{
    ui->nodeSelect_list->clear();
    for (int i = 0; i < ui->widget->get(index)->numberOfNodes(); i++)
    {
        ui->nodeSelect_list->addItem(QString::fromStdString(std::to_string(i+1)));
    }
}
//!void on_actionShape_Report_triggered()
//!Calls shapeReport() from canvas.h
void MainWindow::on_actionShape_Report_triggered()
{
    ui->widget->shapeReport();
    updateShapeSelectList();
}
