#include "login.h"
#include "ui_login.h"

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

//!Method name: ~login()
//!Destructor that saves user files and data and deletes execess memory
login::~login()
{
    saveUsersToFile();
    for (int i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
    delete ui;
}

//!Method name: void on_pushButton_Login_clicked()
//!Method allows users to select a login button and lofin to an existing account
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

//!Method name: bool checkCorrectLogin(QString username, QString password)
//!Method check what the user typed in against existing user login information
//!returns true if information passed matches stored information
//!returns false if information passed does not match stored information
//@param Passed: QString, Qstring
//@return type: bool
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

//!Method name: void saveUserFile()
//!Method saves user information to a text file
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

//!Method name: Vector<User*> getUsers()
//!Method gets stored user data (password, username) from the text file where information is stored
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
        fromFile.push_back(new User(username, password, isAdmin));
    }
    file.close();

    return fromFile;
}

//!Method name: void on_pushButton_NewAccount_clicked()
//!Method allows user to choose the option to create a new account
//!Saves new user information to text file
//!If user information already exists an error message is returned
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
