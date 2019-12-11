#ifndef USER_H
#define USER_H

#include<QString>

//!Class user: stores user login data
class User
{
private:
	//!Private data member of type QString: username
    QString username;
	//!Private data member of type Qstring: password
    QString password;
	//!Private data member of type bool: isAdmin
    bool isAdmin;
public:
	//!Class constructor for user
    User();
	//!Class alternate constructor for user
    User(QString username, QString password, bool isAdmin);
	//!Class destructor for user
    ~User();
	//!QString method for getName
	//! gets username
    QString getName();
	//!QString method for getPassword
	//!gets password
    QString getPassword();
	//!void method for changePassword
	//!Allows user to change password
    void changePassword(QString password);
	//!bool method for adminStatus
	//!returns true if admin false if not
    bool adminStatus();
	//!bool method for correctLogin
	//!returns true if username and password correct and false if not
    bool correctLogin(QString username, QString password);

};

#endif
