#include "foodmenu.h"
#include "payment.h"
#include "user.h"

#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QtTest/QtTest>

class StoreFlowTest : public QObject {
    Q_OBJECT
private slots:
    void mixedCartRechargeAndSinglePurchase() {
        User demo("Demo", "demo", 100);
        FoodMenu menu(demo);
        menu.show();
        auto* chicken = menu.findChild<QComboBox*>("Chicken_options");
        auto* meat = menu.findChild<QComboBox*>("Meat_options");
        auto* add = menu.findChild<QPushButton*>("pushButton");
        auto* view = menu.findChild<QPushButton*>("pushButton_2");
        auto* count = menu.findChild<QLabel*>("iteams");
        auto* balance = menu.findChild<QLabel*>("Balance");
        auto* alert = menu.findChild<QLabel*>("Alert");
        QVERIFY(chicken && meat && add && view && count && balance && alert);

        add->click();
        QCOMPARE(count->text(), QString("0"));
        QVERIFY(alert->text().contains("select"));
        chicken->setCurrentIndex(1); // Fried chicken: 35
        add->click();
        meat->setCurrentIndex(2); // Burger: 45
        QCOMPARE(chicken->currentIndex(), 0);
        add->click();
        QCOMPARE(count->text(), QString("2"));

        bool inspected = false;
        QTimer::singleShot(0, &menu, [&] {
            auto* dialog = qobject_cast<payment*>(QApplication::activeModalWidget());
            if (!dialog) {
                QTest::qFail("Payment dialog did not open", __FILE__, __LINE__);
                if (QApplication::activeModalWidget()) QApplication::activeModalWidget()->close();
                return;
            }
            inspected = true;
            auto* items = dialog->findChild<QPlainTextEdit*>("cartItems");
            auto* total = dialog->findChild<QLabel*>("label_7");
            auto* amount = dialog->findChild<QLineEdit*>("rech");
            auto* recharge = dialog->findChild<QPushButton*>("pushButton_2");
            auto* buy = dialog->findChild<QPushButton*>("pushButton");
            if (!items || !total || !amount || !recharge || !buy) {
                QTest::qFail("Required cart controls missing", __FILE__, __LINE__);
                dialog->reject();
                return;
            }
            QVERIFY(items->toPlainText().contains("Fried Chicken"));
            QVERIFY(items->toPlainText().contains("Burger"));
            QCOMPARE(total->text(), QString("Order total: 80"));
            amount->setText("-10");
            recharge->click();
            QCOMPARE(demo.getBalance(), 100);
            amount->setText("50");
            recharge->click();
            QCOMPARE(demo.getBalance(), 150);
            buy->click();
            QCOMPARE(demo.getBalance(), 70);
            buy->click();
            QCOMPARE(demo.getBalance(), 70); // no duplicate debit
            dialog->accept();
        });
        view->click();
        QVERIFY(inspected);
        QCOMPARE(count->text(), QString("0"));
        QCOMPARE(balance->text(), QString("70"));
        FoodMenu again(demo);
        QCOMPARE(again.findChild<QLabel*>("Balance")->text(), QString("70"));
    }
};

QTEST_MAIN(StoreFlowTest)
#include "qt_smoke.moc"
