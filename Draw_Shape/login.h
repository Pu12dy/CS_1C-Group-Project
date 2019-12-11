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

//!Class login namespace Ui
namespace Ui {
//!Class login
class login;
}

//!class login inheritance from QDialog
class login : public QDialog
{
    Q_OBJECT

public:
	//!constructor for login class
    explicit login(QWidget *parent = 0);
	//!destructor for login class
    ~login();

private slots:
	//!Private method on_pushButton_Login_clicked
    void on_pushButton_Login_clicked();

	//!Private method on_pushButton_NewAccount_clicked
    void on_pushButton_NewAccount_clicked();

signals:
	
	//!Method user is admin
    void userIsAdmin();

private:
	//!Private data member of type login pointer; ui
    Ui::login *ui;
	//!Private data member of type Vector
    Vector<User*>users;
	//!Private method to check if it's the correct login
    bool checkCorrectLogin(QString username, QString password);
	//!Private method that saves the users information
    void saveUsersToFile();
	//!Private data method that gets stored user information from vector
    Vector<User*> getUsers();
};

#endif // LOGIN_H
