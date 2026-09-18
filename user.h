#ifndef USER_H
#define USER_H

#include "account_balance.h"
#include <QString>

class User {
public:
    User(QString name, QString password, int balance);
    QString getName() const;
    QString getPassword() const;
    int getBalance() const;
    bool recharge(int amount);
    bool purchase(int total);
private:
    QString name_;
    QString password_;
    AccountBalance balance_;
};
#endif
