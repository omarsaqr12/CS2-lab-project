#include "payment.h"
#include "ui_payment.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QPlainTextEdit>
#include <QStringList>

payment::payment(User& user, const QVector<Food>& cart, int total, QWidget* parent)
    : QDialog(parent), ui(new Ui::payment), user_(user), total_(total) {
    ui->setupUi(this);
    setWindowTitle("Review demo order");
    resize(460, 360);
    ui->groupBox->setGeometry(12, 10, 435, 175);
    ui->groupBox->setTitle("Items in cart");
    for (QLabel* label : ui->groupBox->findChildren<QLabel*>()) label->hide();
    auto* items = new QPlainTextEdit(ui->groupBox);
    items->setObjectName("cartItems");
    items->setReadOnly(true);
    items->setGeometry(10, 23, 410, 140);
    QStringList descriptions;
    for (const Food& food : cart)
        descriptions << food.getName() + " - " + QString::number(food.getPrice());
    items->setPlainText(descriptions.join("\n"));

    ui->label_7->setGeometry(16, 193, 420, 22);
    ui->label_7->setText("Order total: " + QString::number(total_));
    ui->bal->setGeometry(16, 219, 420, 22);
    ui->rech->setGeometry(16, 253, 120, 25);
    ui->rech->setPlaceholderText("Recharge amount");
    ui->pushButton_2->setGeometry(144, 253, 153, 25);
    ui->pushButton->setGeometry(310, 253, 130, 25);
    ui->mes->setGeometry(16, 282, 420, 35);
    ui->mes->setWordWrap(true);
    ui->mes->clear();
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
    ui->buttonBox->setGeometry(16, 320, 420, 30);
    refreshBalance();
}

payment::~payment() { delete ui; }

void payment::refreshBalance() {
    ui->bal->setText("Demo balance: " + QString::number(user_.getBalance()));
}

void payment::on_pushButton_clicked() {
    if (purchased_) return;
    if (!user_.purchase(total_)) {
        ui->mes->setText("Insufficient balance. Recharge to continue.");
        return;
    }
    purchased_ = true;
    ui->pushButton->setEnabled(false);
    ui->mes->setText("Purchase complete. Close this dialog to return to the menu.");
    refreshBalance();
}

void payment::on_pushButton_2_clicked() {
    bool valid = false;
    const int amount = ui->rech->text().trimmed().toInt(&valid);
    if (!valid || !user_.recharge(amount)) {
        ui->mes->setText("Enter a positive amount within the supported balance range.");
        return;
    }
    ui->rech->clear();
    ui->mes->setText("Demo balance recharged.");
    refreshBalance();
}
