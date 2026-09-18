QT += widgets testlib
CONFIG += c++17 testcase
TARGET = qt_smoke
INCLUDEPATH += ..
SOURCES += qt_smoke.cpp \
    ../food.cpp \
    ../foodmenu.cpp \
    ../payment.cpp \
    ../user.cpp
HEADERS += ../account_balance.h \
    ../food.h \
    ../foodmenu.h \
    ../payment.h \
    ../user.h
FORMS += ../foodmenu.ui \
    ../payment.ui
