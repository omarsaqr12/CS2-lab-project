#include "payment.h"
#include "ui_payment.h"
#include "food.h"

payment::payment(int balan,int totals, Food *aarr, Food *arr,int ch, int ma, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::payment)
{
    pay=balan; tota=totals;
    ui->setupUi(this);
    ui->bal->setText(ui->bal->text() + QString::number(pay));aa=aarr;ab=arr; num_mea=ma,num_chic=ch;


}

payment::~payment()
{
    delete ui;
}

void payment::on_pushButton_clicked()
{
    if(pay<tota){ ui->mes->setText("Sorry, you cann't proceed without recharging your balance");}
    else{
        ui->mes->setText("Purchased succuessfly now you can enjoy your meal"); pay-=tota;
    ui->bal->setText("Your balance is " + QString::number(pay));

    }
}


void payment::on_pushButton_2_clicked()
{
    QString a=ui->rech->text();
    if(a.toInt()<0){ui->rech->setText("Can't enter a ngative value");}
    else{pay+=a.toInt();    ui->bal->setText("Your balance is " + QString::number(pay));}
}

