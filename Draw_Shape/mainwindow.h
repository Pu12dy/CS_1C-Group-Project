#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "contactus.h"
#include "viewtestimonials.h"
#include <QMainWindow>
#include "User.h"
#include "shape.h"
#include "report.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Mainwindow constructor.
    /*!
     * The constructor creates a default empty window for the user to edit
     * This is done by using the drop down boxes to select shape/text, shape/text color,
     * size, style, and many other editing options.
     */
    explicit MainWindow(QWidget *parent = 0);
    //!~MainWindow()
    /*!
     * deletes the pointer ui that generates the visual interface
     */
    ~MainWindow();

private slots:

    //! A void member that takes no arguments and returns no values
    //! Call on quit to exit Qt application
    void on_actionExit_triggered();

    //! A void member function that takes no argument and returns no values
    //! Method opens Login Dialog
    void on_actionLog_In_triggered();

    //!A normal member function that takes no arguments and returns no values
    //!Method opens the Contact Us Dialog
    void on_actionContact_Us_triggered();

    //!A void member function that takes no arguments and returns no values
    //!Method opens Testimonials Dialog
    void on_actionTestimonials_triggered();

    //!A void member function that takes no arguments and returns no values
    //!Method allows user to have admin level access within the Qt environment
    void userIsAdmin();

    //!A void member functions that takes no arguments and returns no values
    //!Method allows a user to log out
    //!Once the action of logging out is carried out all administrative functions
    //!are hidden
    void on_actionLogout_triggered();

    //!void MainWindow::on_moveShape_clicked()
    //!Method allows user to move shape by entering in values X and Y
    //!Method calls moveShape() from canvas.h
    void on_moveShape_clicked();

    //!void on_changePen_clicked()
    //!Method may call any of these methods from canvas.h
    //!setPenColor()
    //!setPenWidth()
    //!setPenStyle()
    //!setPenCapStyle()
    //!setPenCapStyle()
    void on_changePen_clicked();

    //!void on_changeBrush_clicked()
    //!Method may call any of these methods from canvas.h
    //!setBrushColor()
    //!setBrushStyle()
    //!Method updates brush attributes for selected shape
    void on_changeBrush_clicked();

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
    void on_changeText_clicked();

    //!void on_moveUp_button_clicked()
    //!Method implements the button called up
    //!Method calls the moveShape method from canvas.h
    //!to move currently selected shape up 10 pixels
    void on_moveUp_button_clicked();

    //!void on_moveLeft_button_clicked()
    //!Method implements the button called left
    //!Method calls the moveShape method from canvas.h
    //!to move currently selected shape let 10 pixels
    void on_moveLeft_button_clicked();

    //!void on_moveRight_button_clicked()
    //!Method implements the button called right
    //!Method calls the moveShape method from canvas.h
    //!to move currently selected shape right 10 pixels
    void on_moveRight_button_clicked();

    //!void on_moveDown_button_clicked()
    //!Method implements the button called down
    //!Method calls the moveShape method from canvas.h
    //!to move currently selected shape down 10 pixels
    void on_moveDown_button_clicked();

    //!void on_createNewShape_Button_clicked()
    //!Method implements button Ok in the create a shape field
    //!Method calls addShape method from canvas and passes in the
    //!active shape name from createNewShape_list QComboBox
    void on_createNewShape_Button_clicked();

    //!void on_selectShape_activated(int index)
    //!- index is integer value holding the current
    //!  active selection in the selectShape QComboBox
    //!Obscures certain functions based on the shape selected
    //!Not the same action as logging out but the same effect
    //!Functionalities are greyed out not invisible
    void on_selectShape_activated(int index);

    //!void on_decreaseSize_clicked()
    //!Method implements - button on shapeSize box
    //!Method calls changeShapeSize from canvas for currently selected shape
    //!Decreases size by 10 pixels
    void on_decreaseSize_clicked();

    //!void on_increaseSize_clicked()
    //!Method implements + button on shapeSize box
    //!Method calls changeShapeSize from canvas for currently selected shape
    //!Increases size by 10 pixels
    void on_increaseSize_clicked();

    //!void on_removeShape_clicked()
    //!Method implements "Remove Shape" button on Additional Functions box
    //!Method calls removeShape from canvas for currently selected shape
    //!Updates selectShape list when done
    void on_removeShape_clicked();

    //!void on_makeSqCir_clicked()
    //!Method implements "Make Square or Circle" button on Additional Functions box
    //!Method calls makeSquareOrCircle from canvas for currently selected shape
    //!Only displayed for shapes of ellipse and rectangle type
    //!Action cannot be undone
    void on_makeSqCir_clicked();

    //!void on_moveNode_up_clicked()
    //!Method implements the button called right
    //!Method calls the moveNode method from canvas.h
    //!to move currently selected node up 10 pixels
    void on_moveNode_up_clicked();

    //!void on_moveNode_left_clicked()
    //!Method implements the button called right
    //!Method calls the moveNode method from canvas.h
    //!to move currently selected node left 10 pixels
    void on_moveNode_left_clicked();

    //!void on_moveNode_down_clicked()
    //!Method implements the button called right
    //!Method calls the moveNode method from canvas.h
    //!to move currently selected node left 10 pixels
    void on_moveNode_down_clicked();

    //!void on_moveNode_left_clicked()
    //!Method implements the button called right
    //!Method calls the moveNode method from canvas.h
    //!to move currently selected node left 10 pixels
    void on_moveNode_right_clicked();

    //!void on_addNode_clicked()
    //!Method implements the button + in the Add Node box
    //!Method calls the addNode method from canvas.h
    //!Only useable for polylines and polygon types
    void on_addNode_clicked();

    //!void on_addNode_clicked()
    //!Method implements the button - in the Add Node box
    //!Method calls the removeNode method from canvas.h
    //!Does not allow less than 3 nodes in order to preserve shape
    //!Only useable for polylines and polygon types
    void on_removeNode_clicked();

    void on_actionShape_Report_triggered();

private:
    //!Pointer member variable that holds the user interface generated by Qt
    Ui::MainWindow *ui;

    //!void updateShapeSelectList()
    //!Helper method to update the list of selectable shapes
    void updateShapeSelectList();

    //!void updateNodeList(int index)
    //!Method implements the button - in the Add Node box
    //!Method calls the removeNode method from canvas.h
    //!Does not allow less than 3 nodes in order to preserve shape
    //!Only useable for polylines and polygon types
    void updateNodeList(int index);
};

#endif // MAINWINDOW_H
