#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString name, QString password, int balance);

    QString getName() const;
    QString getPassword() const;
    int getBalance() const;
    void setBalance(int balance);

private:
    QString name_;
    QString password_;
    int balance_;
};

#endif // USER_H
