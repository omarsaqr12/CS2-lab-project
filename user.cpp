#include "user.h"

User::User(QString name, QString password, int balance)
    : name_(name), password_(password), balance_(balance) {}

QString User::getName() const { return name_; }
QString User::getPassword() const { return password_; }
int User::getBalance() const { return balance_.amount(); }
bool User::recharge(int amount) { return balance_.recharge(amount); }
bool User::purchase(int total) { return balance_.purchase(total); }
