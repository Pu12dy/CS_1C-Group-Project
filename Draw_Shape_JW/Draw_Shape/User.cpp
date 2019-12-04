#include "User.h"

User::User(): User("guest", "guest", false)
{}

User::User(QString username, QString password, bool isAdmin): username{username}, password{password}, isAdmin{isAdmin}
{

}

QString User::getName()
{
    return username;
}

void User::changePassword(QString password)
{
    this->password = password;
}

bool User::adminStatus()
{
    return isAdmin;
}

bool User::correctLogin(QString username, QString password)
{
    return (this->password == password) && (this->username == username);
}
