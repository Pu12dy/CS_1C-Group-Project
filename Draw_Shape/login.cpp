#include "login.h"
#include "ui_login.h"
#include <QtDebug>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);
    this->setWindowTitle("Login");
    users = getUsers();
    if (users.size() == 0)
    {
        users.push_back(new User("admin", "admin", true));
    }

}

login::~login()
{
    saveUsersToFile();
    for (int i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
    delete ui;
}

void login::on_pushButton_Login_clicked()
{

    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    if (checkCorrectLogin(username, password))
    {
        emit userIsAdmin();// Right now all users are admin
        this->close();
    }
    else
    {
        QMessageBox::information(this, "Error", "Username and Password is not Correct");
    }

}

bool login::checkCorrectLogin(QString username, QString password)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->correctLogin(username, password))
        {
            return true;
        }
    }
    return false;
}
void login::saveUsersToFile()
{
    QFile file("Users.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for (int i = 0; i < users.size(); i++)
    {
        out << users[i]->getName()<< "\n";
        out << users[i]->getPassword()<< "\n"; //
        if (users[i]->adminStatus())
        {
            out << "true";
        }
        else
        {
            out << "false";
        }

        if(i + 1 != users.size())
        {
            out<<"\n";
        }
    }
    file.close();
}

Vector<User*> login::getUsers()
{
    Vector<User*>fromFile;

    QFile file("Users.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.exists())
    {
        return fromFile;
    }

    QTextStream in(&file);
    QString username;
    QString password;
    QString adminText;
    bool isAdmin;
    while (!in.atEnd())
    {
        in >> username;
        in >> password;
        in >> adminText;
        if ( adminText == "true")
        {
            isAdmin = true;
        }
        else
        {
            isAdmin = false;
        }
        qDebug() << "Added user from file to vector.";
        fromFile.push_back(new User(username, password, isAdmin));
    }
    file.close();
    return fromFile;
}

void login::on_pushButton_NewAccount_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if(checkCorrectLogin(username, password))
    {
        QMessageBox::information(this, "Error", "User Already Exists!!");
    }
    else
    {
        users.push_back(new User(username, password, true));
    }

    saveUsersToFile();
    ui->lineEdit_Username->clear();
    ui->lineEdit_Password->clear();


}
