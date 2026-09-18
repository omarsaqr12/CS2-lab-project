#ifndef ACCOUNT_BALANCE_H
#define ACCOUNT_BALANCE_H
#include <limits>
#include <stdexcept>
// Local demo-account arithmetic; no actual payment processing or persistence.
class AccountBalance {
public:
    explicit AccountBalance(int opening) : amount_(opening) {
        if (opening < 0) throw std::invalid_argument("negative opening balance");
    }
    int amount() const { return amount_; }
    bool recharge(int value) {
        if (value <= 0 || value > std::numeric_limits<int>::max() - amount_) return false;
        amount_ += value;
        return true;
    }
    bool purchase(int total) {
        if (total <= 0 || total > amount_) return false;
        amount_ -= total;
        return true;
    }
private:
    int amount_;
};
#endif
