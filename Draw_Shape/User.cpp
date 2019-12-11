#include "User.h"

User::User(): User("guest", "guest", false)
{}

User::User(QString username, QString password, bool isAdmin): username{username}, password{password}, isAdmin{isAdmin}
{

}

//!class destructor
User::~User()
{

}
//!Method name: QString getName()
//@param Passed: none
//@return type: QString
QString User::getName()
{
    return username;
}

//!Method name: void changePassword(QString password)
//!Method assigns password change to old password
//@param Passed: QString
//@return type: none

void User::changePassword(QString password)
{
    this->password = password;
}

//!Method name: bool adminStatus()
//!Method checks too see if user is admin or not (yes = return true, no = return false)
//@Param Passed: none
//@return: type: bool
bool User::adminStatus()
{
    return isAdmin;
}

//!Method name :bool correctLogin(QString username, QString password)
//!Method compares password with stored password and username with stored username
//@param Passed: QString, QString
//return type: bool
bool User::correctLogin(QString username, QString password)
{
    return (this->password == password) && (this->username == username);
}

//!Method name: Qstring getPassword()
//!Method gets stored password and returns the correct data type
//@para Passed: none
//@return type: QString
QString User::getPassword()
{
    return password;
}
