#ifndef SIGN_IN_WINDOW_H
#define SIGN_IN_WINDOW_H
#include <QMainWindow>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Sign_in_window; }
QT_END_NAMESPACE

class Sign_in_window : public QMainWindow
{
    Q_OBJECT

public:
    Sign_in_window(QWidget *parent = nullptr);
    ~Sign_in_window();

private slots:
    void on_SIgnbutton_clicked();

private:
    Ui::Sign_in_window *ui;
    User users[3] = {                           //creating our array of class, users
        {"Nazeer", "892003", 300},
        {"Omar", "password", 200},
        {"Salma", "12345", 100},
    };
};
#endif // SIGN_IN_WINDOW_H
