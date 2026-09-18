#ifndef FOODMENU_H
#define FOODMENU_H

#include "food.h"
#include "user.h"
#include <QDialog>
#include <QVector>

namespace Ui { class FoodMenu; }

class FoodMenu : public QDialog {
    Q_OBJECT
public:
    explicit FoodMenu(User& user, QWidget* parent = nullptr);
    ~FoodMenu() override;
private slots:
    void on_Chicken_options_currentIndexChanged(int index);
    void on_Meat_options_currentIndexChanged(int index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    enum class Category { None, Chicken, Meat };
    const Food* selectedFood() const;
    void refreshSummary();

    Ui::FoodMenu* ui;
    User& user_;
    Category category_ = Category::None;
    int selectedIndex_ = -1;
    QVector<Food> cart_;
    int total_ = 0;
    Food chicken_[3] = {{"Fried Chicken", 35}, {"Grilled Chicken", 40}, {"Chicken Sandwich", 30}};
    Food meat_[3] = {{"Steak", 100}, {"Burger", 45}, {"Meatball Pasta", 55}};
};
#endif
