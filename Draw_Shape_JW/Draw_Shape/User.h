#ifndef USER_H
#define USER_H

#include<QString>

class User
{
private:
    QString username;
    QString password;
    bool isAdmin;
public:
    User();
    User(QString username, QString password, bool isAdmin);
    ~User();
    QString getName();
    void changePassword(QString password);
    bool adminStatus();
    bool correctLogin(QString username, QString password);

};

#endif
