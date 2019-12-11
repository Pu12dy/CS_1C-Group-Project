#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include "shapeParser.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "text.h"
#include "vector.h"
#include "ellipse.h"
#include "polyline.h"
#include "polygon.h"
#include "extraCredit.h"
#include <QFile>
#include <QTextStream>

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    //! Report(QWidget *parent)
    //! Constructor
    //! Populates the list of selectable reports
    //! Parses the shape in from the text file
    explicit Report(QWidget *parent = nullptr);

    //! ~Report()
    //! Destructor
    ~Report();

    //! ReportType Enum
    //! ReportType:: AllShapes
    //! ReportType:: HasArea
    //! ReportType:: HasPerimeter
    enum ReportType
    {
        AllShapes,
        HasArea,
        HasPerimeter
    };


private slots:
    void on_report_list_currentIndexChanged(int index);
private:
    Ui::Report *ui;

    //! Vector<shape*> shapes
    //! Vector of shape pointers
    //! Holds all the shapes
    Vector<shape*> shapes;

    //! void writeReportToFile(ReportType type)
    //! Everytime report is ran, the report file
    //! is modified
    //! Modification is done based which selection is picked
    void writeReportToFile(ReportType type);

    //! void writeShapeProperties(QTextStream& out, shape* i)
    //! Writes the shape's properties to the file
    //! Not all properties are written for each project.
    void writeShapeProperties(QTextStream& out, shape* i);

    //! void readReportFromFile()
    //! Reads from the report file and displays to the text browser box
    void readReportFromFile();

    //! void getShapes()
    //! Loads the shapes from text file
    void getShapes();
};

#endif // REPORT_H
