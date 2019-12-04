#ifndef NEWSHAPE_H
#define NEWSHAPE_H

#include <QDialog>

namespace Ui {
class NewShape;
}

class NewShape : public QDialog
{
    Q_OBJECT

public:
    explicit NewShape(QWidget *parent = 0);
    ~NewShape();

private slots:
    void on_addLine_clicked();

private:
    Ui::NewShape *ui;
};

#endif // NEWSHAPE_H
