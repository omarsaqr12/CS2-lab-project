# Qt Restaurant Ordering Demo — CS2 Lab Project

A small **C++17 / Qt Widgets coursework GUI** for choosing food, reviewing a cart and making purchases using an in-memory demo balance. The project illustrates Qt Designer forms, signals/slots, C++ classes and state passed between dialogs. It is not a real restaurant back office, secure authentication system or payment processor.

## What is implemented

- Sign in as one of **three hard-coded example users** declared in [`sign_in_window.h`](sign_in_window.h). Credentials are stored as plain text in the source and exist only for classroom demonstration; **do not reuse real passwords**.
- Choose from three chicken and three meat items, add multiple items to a cart and review each item and the total.
- Recharge an in-memory balance with a positive integer amount and buy a cart if the account has sufficient balance. Purchases debit the signed-in user once; the cart clears after a successful purchase, and the balance carries across dialogs in the same application session.

Menu prices and user accounts are compiled into the application. There is **no menu editing, account creation, password storage security, card charge, database, receipt, multi-user server or persistence after restart**. Any “payment” or “recharge” is simulated, not a financial transaction.

## Run

Requires Qt 6 with the **Qt Widgets** module, qmake and a compatible C++17 compiler. Open [`QTstore.pro`](QTstore.pro) in Qt Creator, select an installed desktop Qt 6 kit and build/run. The project uses qmake rather than CMake; no data files or network services are required.

On Linux with Qt 6/qmake installed, an out-of-source build is:

```bash
mkdir -p build/app
cd build/app
qmake6 ../../QTstore.pro
make -j2
./QTstore
```

On Windows, use Qt Creator's Build/Run actions with your matching compiler kit. The specific executable name and compiler command may differ by platform. The original Qt Creator user settings file (`QTstore.pro.user`) is machine-specific and is not needed for a fresh checkout.

## Try it

Sign in with one of the **demo accounts shown in the source**, select a chicken item and press **Add to cart**. Select a meat item and add that too; changing category clears the other dropdown selection. Select **View Cart** to see the itemized list and order total. If the simulated balance is insufficient, enter a positive recharge amount and retry. A successful purchase disables the buy button, empties the cart on return and updates the same in-memory user balance.

## Repository map and verification

| File | Role |
| --- | --- |
| [`main.cpp`](main.cpp), [`sign_in_window.*`](sign_in_window.cpp) | Qt application entry point, demo login and session entry |
| [`food.*`](food.cpp), [`foodmenu.*`](foodmenu.cpp) | Fixed menu items, category selection and cart state |
| [`user.*`](user.cpp), [`account_balance.h`](account_balance.h) | Demo user and checked balance arithmetic |
| [`payment.*`](payment.cpp) | Cart display, simulated recharge and once-only purchase |
| [`foodmenu.ui`](foodmenu.ui), [`payment.ui`](payment.ui), [`sign_in_window.ui`](sign_in_window.ui) | Qt Designer layouts used by the GUI |
| [`tests/test_account_balance.cpp`](tests/test_account_balance.cpp) | Standalone boundary checks: insufficient funds, negative/zero values and overflow |
| [`tests/qt_smoke.cpp`](tests/qt_smoke.cpp), [`tests/qt_smoke.pro`](tests/qt_smoke.pro) | Qt widget-level cart, recharge, purchase and session-state smoke test |

The standalone balance test needs only g++:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I. tests/test_account_balance.cpp -o account_test
./account_test
```

With Qt 6, build and run the widget test using a separate directory:

```bash
mkdir -p build/test
cd build/test
qmake6 ../../tests/qt_smoke.pro
make -j2
QT_QPA_PLATFORM=offscreen ./qt_smoke
```

The UI test requires the Qt Test module and the offscreen Qt platform plugin. Passing the arithmetic test alone does **not** prove that GUI behavior works. See the pull request's verification notes for which checks were actually executed.

## Scope and provenance

This is an updated demonstration of an existing coursework project, **not** evidence of a deployed or independently evaluated system. The repository does not contain a license file or a reliable breakdown of individual contributions, so no license or exclusive authorship claim is made. The original code is retained in Git history; `main (1).cpp` is an unused duplicate and is not included in the qmake build. The previously tracked Qt Creator configuration is excluded from the proposed branch because it contains local machine paths, not portable build instructions.
