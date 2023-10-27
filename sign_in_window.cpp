#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include "user.h"
#include "foodmenu.h"
Sign_in_window::Sign_in_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Sign_in_window)
{
    ui->setupUi(this);
    ui->balanceLabel->setText("0");                   //initial value of balance
    ui->Password->setEchoMode(QLineEdit::Password);   //this would make the password as "*" when iputted by the user
    ui->Message->setText("");                         //to hide the error message at first
}


Sign_in_window::~Sign_in_window()
{
    delete ui;
}


void Sign_in_window::on_SIgnbutton_clicked()
{
    QString username = ui->Username->text();         //connecting the username in the ui so we could use it in the loop
    QString password = ui->Password->text();
    for(int i=0; i<3; i++){
        if(users[i].getName() == username && users[i].getPassword() != password){   //checks if the name is correct and if the password is wrong
            ui->Message->setText("Name is correct, but Password is not correct");   //would just print the error
            return;
        }
        else if(users[i].getName() == username && users[i].getPassword() == password){  //if both password and username is correct then it would do the following
            int balance=users[i].getBalance();
            ui->Message->setText("Signed in succesfully");                              //display the successful message
            ui->balanceLabel->setText(QString::number(users[i].getBalance()));          //change the balance to the balance of the username inputed, the i connects the name with balance
            FoodMenu foodmenu(balance);
            foodmenu.setModal(true);
            foodmenu.exec();                                   //would open a new dialog
            return;
        }
        else if(users[i].getName() != username){       //if the name is not correct in the first place then simply display the following message
            ui->Message->setText("Name does not exist");
        }
    }
    }

