#include "sign_in_window.h"
#include "ui_sign_in_window.h"
#include "foodmenu.h"

Sign_in_window::Sign_in_window(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Sign_in_window) {
    ui->setupUi(this);
    ui->balanceLabel->setText("0");
    ui->Password->setEchoMode(QLineEdit::Password);
    ui->Message->clear();
}

Sign_in_window::~Sign_in_window() { delete ui; }

void Sign_in_window::on_SIgnbutton_clicked() {
    const QString username = ui->Username->text();
    const QString password = ui->Password->text();
    for (User& user : users) {
        if (user.getName() == username && user.getPassword() == password) {
            ui->Message->setText("Signed in successfully");
            FoodMenu menu(user, this);
            menu.exec();
            ui->balanceLabel->setText(QString::number(user.getBalance()));
            return;
        }
    }
    ui->Message->setText("Invalid username or password");
}
