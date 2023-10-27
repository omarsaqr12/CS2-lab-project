#include "food.h"
Food::Food(){price=0;}
Food::Food(QString name, int price) : name(name), price(price) {} //definition of the constructors, the parameters

QString Food::getName() const {                                   //what the getters do
    return name;
}

int Food::getPrice() const {
    return price;
}
