#include "foodmenu.h"
#include "ui_foodmenu.h"
#include "food.h"
#include "payment.h"
#include "ui_payment.h"


FoodMenu::FoodMenu(int balance, QWidget *parent) :
    QDialog(parent),         //to get the balance of the user signed in
    ui(new Ui::FoodMenu)
{
    ui->setupUi(this);
    ui->priceLabel->setText("0");
    ui->Balance->setText(QString::number(balance));
    ui->iteams->setText("0");
    ui->Alert->setText("");
    num_items=0;price=0;i=0;j=0;i_chicken=0;i_meat=0;num_chicken=0;num_meat=0;total_price=0;curr=balance;
    //initializes everything as 0 or empty, just like in the previous window
}

FoodMenu::~FoodMenu(){
    delete ui;
}

void FoodMenu::on_Chicken_options_currentIndexChanged(int index)
{
    QString selectedItem = ui->Chicken_options->itemText(index);

    for ( i = 0; i < 3; i++) {
        if (chicken[i].getName() == selectedItem) {    //checks the name of the item selected and compares it to the one in the array above
            price = chicken[i].getPrice();             //assigns its price to int price
            break;i_chicken++;
        }
    }
    ui->priceLabel->setText(QString::number(price));    //puts the price of the item selected in the priceLabel

}

void FoodMenu::on_Meat_options_currentIndexChanged(int index)
{
    QString selectedItem = ui->Meat_options->itemText(index);

    for (j = 0; j < 3; j++) {
        if (meat[j].getName() == selectedItem) {        //checks the name of the item selected and compares it to the one in the array above
            price = meat[j].getPrice();                 //assigns its price to int price
            break;i_meat++;
        }
    }
    ui->priceLabel->setText(QString::number(price));    //puts the price of the item selected in the priceLabel

}


void FoodMenu::on_pushButton_clicked()                     //when the button is pushed
{
    if(price==0){
        ui->Alert->setText("Please select items first");  }//you get the error message
    else{ num_items++;ui->iteams->setText(QString::number(num_items));total_price+=price;
        if(i_chicken==1){ordered_chicken[num_chicken]=chicken[i];num_chicken++;i_chicken--;
        }
        else{ordered_meat[num_meat]=meat[j];num_meat++;i_meat--;}
    }
}


void FoodMenu::on_pushButton_2_clicked()
{
       payment payy(curr,total_price,ordered_chicken,ordered_meat, num_chicken,num_meat);
       payy.setModal(true);
       payy.exec();
}

