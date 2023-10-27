#ifndef FOODMENU_H
#define FOODMENU_H
#include "food.h"
#include <QDialog>

namespace Ui {
class FoodMenu;
}

class FoodMenu : public QDialog
{
    Q_OBJECT

public:
    FoodMenu(int balance, QWidget *parent = nullptr);
    ~FoodMenu(); int price; Food ordered_meat[3];
    Food ordered_chicken[3]; int i,j,i_meat,i_chicken; int num_chicken;int num_meat; int total_price;  int curr;


private slots:
    void on_Chicken_options_currentIndexChanged(int index);

    void on_Meat_options_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::FoodMenu *ui;
    Food chicken[3] = {                 //arrays to host different food types
                       {"Fried Chicken", 35},
                       {"Grilled Chicken", 40},
                       {"Chicken Sandwich", 30},
                       };
    Food meat[3] = {
                    {"Steak", 100},
                    {"Burger", 45},
                    {"Meatball Pasta", 55},
                    };
    int num_items;
};

#endif // FOODMENU_H
