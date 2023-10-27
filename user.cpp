#include "user.h"

User::User(QString name, QString password, int balance)
    : name_(name), password_(password), balance_(balance)        //the contructors of the class
{
}

QString User::getName() const               //what the getters do
{
    return name_;
}

QString User::getPassword() const
{
    return password_;
}

int User::getBalance() const
{
    return balance_;
}

void User::setBalance(int balance)                //since the balance could be modified
{
    balance_ = balance;
}
