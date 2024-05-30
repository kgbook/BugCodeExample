#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class BankAccount {
public:
    BankAccount(std::string owner, double initial_balance)
            : owner_(owner), balance_(initial_balance > 0 ? initial_balance : 0) {}

    bool Deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        balance_ += amount;
        return true;
    }

    bool Withdraw(double amount) {
        if (amount <= balance_) {
            balance_ -= amount;
            return true;
        }
        return false;
    }

    double GetBalance() const {
        return balance_;
    }

    std::string GetOwner() const {
        return owner_;
    }

private:
    std::string owner_;
    double balance_;
};

class Bank {
public:
    BankAccount* OpenAccount(std::string owner, double initial_balance) {
        accounts_.emplace_back(owner, initial_balance);
        return &accounts_.back();
    }

    bool CloseAccount(BankAccount* account) {
        for (auto it = accounts_.begin(); it != accounts_.end(); ++it) {
            if (&(*it) == account) {
                accounts_.erase(it);
                return true;
            }
        }
        return false;
    }

    double GetTotalDeposits() const {
        return std::accumulate(accounts_.begin(), accounts_.end(), 0.0,
                               [](double sum, const BankAccount& account) { return sum + account.GetBalance(); });
    }

private:
    std::vector<BankAccount> accounts_;
};

int main() {
    Bank myBank;

    auto account1 = myBank.OpenAccount("John Doe", 1000);
    auto account2 = myBank.OpenAccount("Jane Smith", 500);

    account1->Deposit(500);
    account2->Withdraw(100);

    std::cout << "Total deposits in the bank: " << myBank.GetTotalDeposits() << std::endl;

    if (myBank.CloseAccount(account1)) {
        std::cout << "Account closed for " << account1->GetOwner() << std::endl;
    } else {
        std::cout << "Error closing account for " << account1->GetOwner() << std::endl;
    }

    return 0;
}
