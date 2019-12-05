#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "User.h"
#include <QLineEdit>
#include <QString>
#include <QMessageBox>
#include "vector.h"
#include <QFile>
#include <QTextStream>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:

    void on_pushButton_Login_clicked();

    void on_pushButton_NewAccount_clicked();

signals:

    void userIsAdmin();

private:
    Ui::login *ui;
    Vector<User*>users;
    bool checkCorrectLogin(QString username, QString password);
    void saveUsersToFile();
    Vector<User*> getUsers();
};

#endif // LOGIN_H
