#include "sign_in_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sign_in_window w;
    w.show();
    return a.exec();
}

