#ifndef FOOD_H
#define FOOD_H

#include <QString>

class Food {
private:
    QString name;
    int price;
public:
    Food();
    Food(QString name, int price);
    QString getName() const;
    int getPrice() const;
};

#endif // FOOD_H
