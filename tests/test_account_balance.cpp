#include "account_balance.h"
#include <cassert>
#include <limits>
#include <stdexcept>
int main() {
    AccountBalance account(100);
    assert(account.amount() == 100);
    assert(!account.purchase(0));
    assert(!account.purchase(-10));
    assert(!account.purchase(101));
    assert(account.purchase(35));
    assert(account.amount() == 65);
    assert(!account.recharge(0));
    assert(!account.recharge(-10));
    assert(account.recharge(45));
    assert(account.amount() == 110);
    assert(account.purchase(110));
    assert(account.amount() == 0);
    assert(!account.purchase(1));
    AccountBalance maxed(std::numeric_limits<int>::max());
    assert(!maxed.recharge(1));
    assert(maxed.amount() == std::numeric_limits<int>::max());
    bool threw = false;
    try { AccountBalance invalid(-1); } catch (const std::invalid_argument&) { threw = true; }
    assert(threw);
}
