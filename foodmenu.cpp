#include "foodmenu.h"
#include "payment.h"
#include "ui_foodmenu.h"

#include <QSignalBlocker>
#include <limits>

FoodMenu::FoodMenu(User& user, QWidget* parent)
    : QDialog(parent), ui(new Ui::FoodMenu), user_(user) {
    ui->setupUi(this);
    ui->Alert->clear();
    refreshSummary();
}

FoodMenu::~FoodMenu() { delete ui; }

const Food* FoodMenu::selectedFood() const {
    if (selectedIndex_ < 0 || selectedIndex_ >= 3) return nullptr;
    if (category_ == Category::Chicken) return &chicken_[selectedIndex_];
    if (category_ == Category::Meat) return &meat_[selectedIndex_];
    return nullptr;
}

void FoodMenu::refreshSummary() {
    ui->iteams->setText(QString::number(cart_.size()));
    ui->Balance->setText(QString::number(user_.getBalance()));
    const Food* food = selectedFood();
    ui->priceLabel->setText(QString::number(food ? food->getPrice() : 0));
}

void FoodMenu::on_Chicken_options_currentIndexChanged(int index) {
    if (index < 1 || index > 3) {
        if (category_ == Category::Chicken) {
            category_ = Category::None;
            selectedIndex_ = -1;
            refreshSummary();
        }
        return;
    }
    {
        const QSignalBlocker blocker(ui->Meat_options);
        ui->Meat_options->setCurrentIndex(0);
    }
    category_ = Category::Chicken;
    selectedIndex_ = index - 1;
    ui->Alert->clear();
    refreshSummary();
}

void FoodMenu::on_Meat_options_currentIndexChanged(int index) {
    if (index < 1 || index > 3) {
        if (category_ == Category::Meat) {
            category_ = Category::None;
            selectedIndex_ = -1;
            refreshSummary();
        }
        return;
    }
    {
        const QSignalBlocker blocker(ui->Chicken_options);
        ui->Chicken_options->setCurrentIndex(0);
    }
    category_ = Category::Meat;
    selectedIndex_ = index - 1;
    ui->Alert->clear();
    refreshSummary();
}

void FoodMenu::on_pushButton_clicked() {
    const Food* selected = selectedFood();
    if (!selected) {
        ui->Alert->setText("Please select an item first");
        return;
    }
    if (selected->getPrice() > std::numeric_limits<int>::max() - total_) {
        ui->Alert->setText("Cart total is too large");
        return;
    }
    cart_.append(*selected);
    total_ += selected->getPrice();
    ui->Alert->clear();
    refreshSummary();
}

void FoodMenu::on_pushButton_2_clicked() {
    if (cart_.isEmpty()) {
        ui->Alert->setText("Add an item before viewing the cart");
        return;
    }
    payment dialog(user_, cart_, total_, this);
    dialog.exec();
    if (dialog.purchased()) {
        cart_.clear();
        total_ = 0;
        ui->Alert->setText("Purchase complete");
    }
    refreshSummary();
}
