#ifndef PAYMENT_H
#define PAYMENT_H
#include "foodmenu.h"
#include "ui_foodmenu.h"
#include "food.h"
#include <QDialog>

namespace Ui {
class payment;
}

class payment : public QDialog
{
    Q_OBJECT

public:
    explicit payment(int balan,int tot,Food *aar,Food *arr, int ch, int ma, QWidget *parent = nullptr);
    ~payment(); int pay; int tota; Food *aa; Food *ab; int num_chic; int num_mea;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::payment *ui;
};

#endif // PAYMENT_H
