#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login), admin(new User("admin", "admin", true))//, guest( new User("guest", "guest", false))
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    if (admin->correctLogin(username, password))
    {
        QMessageBox::information(this, "Login", "Username and Password is Correct");
    }
    else
    {
        QMessageBox::information(this, "Error", "Username and Password is not Correct");
    }
}
