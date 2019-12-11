#include "report.h"
#include "ui_report.h"

//! Report(QWidget *parent)
//! Constructor
//! Populates the list of selectable reports
//! Parses the shape in from the text file
Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);

    ui->report_list->addItem("Select");
    ui->report_list->addItem("All Shapes");
    ui->report_list->addItem("Only Shapes With Area");
    ui->report_list->addItem("Only Shapes With Perimeter");

    getShapes();


}

//! ~Report()
//! Destructor
Report::~Report()
{
    delete ui;
}

//! void writeReportToFile(ReportType type)
//! Everytime report is ran, the report file
//! is modified
//! Modification is done based which selection is picked
void Report::writeReportToFile(ReportType type)
{

    //! First sort the shapes
    switch (type)
    {
    case ReportType::AllShapes:
        selection_sort(shapes.begin(), shapes.end(), Cmp_by_id());
        break;
    case ReportType::HasArea:
        selection_sort(shapes.begin(), shapes.end(), Cmp_by_area());
        break;
    case ReportType::HasPerimeter:
        selection_sort(shapes.begin(), shapes.end(), Cmp_by_perimeter());
        break;
    }

    //! Write the shapes to the report file
    QFile file("Report.txt");
    QTextStream out(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    for (int i = 0; i < shapes.size(); i++)
    {
        switch (type)
        {
        case ReportType::AllShapes:
            writeShapeProperties(out, shapes[i]);
            break;
        case ReportType::HasArea:
            if (shapes[i]->area() > 0)
            {
                writeShapeProperties(out, shapes[i]);
            }
            break;
        case ReportType::HasPerimeter:
            if (shapes[i]->perimeter() > 0)
            {
                writeShapeProperties(out, shapes[i]);
            }
            break;
        }
    }
    file.close();
}

//! void writeShapeProperties(QTextStream& out, shape* i)
//! Writes the shape's properties to the file
//! Not all properties are written for each project.
void Report::writeShapeProperties(QTextStream& out, shape* i)
{
    std::string shapeType = i->getShapeType();

    if (shapeType == "Line" || shapeType == "Polyline") // Lines
    {
        out << QString::fromStdString(i->getShapeType()) << "\n";
        out << QString::number(i->getShapeID()) << "\n";
        out << "PenColor: " << QString::fromStdString(getPenColorString(i)) << "\n";
        out << "PenWidth: " << QString::number(i->getQPen().QPen::width()) << "\n";
        out << "PenStyle: " << QString::fromStdString(getPenStyleString(i)) << "\n";
        out << "PenCap: " << QString::fromStdString(getPenCapString(i)) << "\n";
        out << "PenJoin: " << QString::fromStdString(getPenJoinString(i)) << "\n";
    }
    else if (shapeType == "Rectangle" || shapeType == "Square") // Rectangle
    {
        out << QString::fromStdString(i->getShapeType()) << "\n";
        out << QString::number(i->getShapeID()) << "\n";
        out << "Area: " << QString::number(i->area()) << "\n";
        out << "Perimeter: " << QString::number(i->perimeter()) << "\n";
        out << "PenColor: " << QString::fromStdString(getPenColorString(i)) << "\n";
        out << "PenWidth: " << QString::number(i->getQPen().QPen::width()) << "\n";
        out << "PenStyle: " << QString::fromStdString(getPenStyleString(i)) << "\n";
        out << "PenCap: " << QString::fromStdString(getPenCapString(i)) << "\n";
        out << "PenJoin: " << QString::fromStdString(getPenJoinString(i)) << "\n";
        out << "BrushColor: " << QString::fromStdString(getBrushColorString(i)) << "\n";
        out << "BrushStyle: " << QString::fromStdString(getBrushStyleString(i)) << "\n";

    }
    else if (shapeType == "Ellipse" || shapeType == "Circle") // Ellipse
    {
        out << QString::fromStdString(i->getShapeType()) << "\n";
        out << QString::number(i->getShapeID()) << "\n";
        out << "Area: " << QString::number(i->area()) << "\n";
        out << "Perimeter: " << QString::number(i->perimeter()) << "\n";
        out << "PenColor: " << QString::fromStdString(getPenColorString(i)) << "\n";
        out << "PenWidth: " << QString::number(i->getQPen().QPen::width()) << "\n";
        out << "PenStyle: " << QString::fromStdString(getPenStyleString(i)) << "\n";
        out << "PenCap: " << QString::fromStdString(getPenCapString(i)) << "\n";
        out << "PenJoin: " << QString::fromStdString(getPenJoinString(i)) << "\n";
        out << "BrushColor: " << QString::fromStdString(getBrushColorString(i)) << "\n";
        out << "BrushStyle: " << QString::fromStdString(getBrushStyleString(i)) << "\n";
    }
    else if (shapeType == "Text") // Text
    {
        out << QString::fromStdString(i->getShapeType()) << "\n";
        out << QString::number(i->getShapeID()) << "\n";
        out << QString::fromStdString(i->getTextString()) << "\n";
        out << "TextColor: " << QString::fromStdString(i->getTextColorString()) << "\n";
        out << "TextAlignment: " << QString::fromStdString(i->getTextAlignmentString()) << "\n";
        out << "TextPointSize: " << QString::fromStdString(i->getTextPointSize()) << "\n";
        out << "TextFontFamily: " << QString::fromStdString(i->getTextFontFamilyString()) << "\n";
        out << "TextFontStyle: " << QString::fromStdString(i->getTextFontStyleString()) << "\n";
        out << "TextFontWeight: " << QString::fromStdString(i->getTextFontWeightString()) << "\n";
    }
    else if (shapeType == "Polygon") //Polygon
    {
        out << QString::fromStdString(i->getShapeType()) << "\n";
        out << QString::number(i->getShapeID()) << "\n";
        out << "Area: " << QString::number(i->area()) << "\n";
        out << "Perimeter: " << QString::number(i->perimeter()) << "\n";
        out << "PenColor: " << QString::fromStdString(getPenColorString(i)) << "\n";
        out << "PenWidth: " << QString::number(i->getQPen().QPen::width()) << "\n";
        out << "PenStyle: " << QString::fromStdString(getPenStyleString(i)) << "\n";
        out << "PenCap: " << QString::fromStdString(getPenCapString(i)) << "\n";
        out << "PenJoin: " << QString::fromStdString(getPenJoinString(i)) << "\n";
        out << "BrushColor: " << QString::fromStdString(getBrushColorString(i)) << "\n";
        out << "BrushStyle: " << QString::fromStdString(getBrushStyleString(i)) << "\n";
    }
}

//! void getShapes()
//! Loads the shapes from text file
void Report::getShapes()
{
    shapes = parseShapes("shapes.txt");
}

//! void readReportFromFile()
//! Reads from the report file and displays to the text browser box
void Report::readReportFromFile()
{
    QFile file("Report.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    ui->reportDisplay->setText(in.readAll());
    file.close();
}

//! void on_report_list_currentIndexChanged(int index)
//! Triggers when a new report type is selected
void Report::on_report_list_currentIndexChanged(int index)
{
    switch (index)
    {
    case 1:
        ui->reportDisplay->clear();
        writeReportToFile(ReportType::AllShapes);
        readReportFromFile();
        break;
    case 2:
        ui->reportDisplay->clear();
        writeReportToFile(ReportType::HasArea);
        readReportFromFile();
        break;
    case 3:
        ui->reportDisplay->clear();
        writeReportToFile(ReportType::HasPerimeter);
        readReportFromFile();
        break;
    default:
        break;
    }
}
