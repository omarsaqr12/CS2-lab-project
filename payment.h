#ifndef PAYMENT_H
#define PAYMENT_H

#include "food.h"
#include "user.h"
#include <QDialog>
#include <QVector>

namespace Ui { class payment; }

class payment : public QDialog {
    Q_OBJECT
public:
    explicit payment(User& user, const QVector<Food>& cart, int total, QWidget* parent = nullptr);
    ~payment() override;
    bool purchased() const { return purchased_; }
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    void refreshBalance();
    Ui::payment* ui;
    User& user_;
    int total_;
    bool purchased_ = false;
};
#endif
