// bank.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <iomanip>

// Base class: Account (abstract-ish)
class Account {
protected:
    std::string owner;
    double balance;

public:
    Account(const std::string& owner_, double initial = 0.0)
        : owner(owner_), balance(initial) {}

    virtual ~Account() = default; // virtual so derived destructors run

    // Encapsulated accessors
    std::string getOwner() const { return owner; }
    double getBalance() const { return balance; }

    // Common operations
    virtual void deposit(double amount) {
        if (amount <= 0) throw std::invalid_argument("Deposit must be positive");
        balance += amount;
        std::cout << owner << " deposited " << amount << "\n";
    }

    // withdraw is virtual because different accounts may behave differently
    virtual void withdraw(double amount) {
        if (amount <= 0) throw std::invalid_argument("Withdraw must be positive");
        if (amount > balance) throw std::runtime_error("Insufficient funds");
        balance -= amount;
        std::cout << owner << " withdrew " << amount << "\n";
    }

    // Provide a textual summary; override in derived classes for extra info
    virtual void printSummary() const {
        std::cout << "Account owner: " << owner
                  << ", Balance: " << std::fixed << std::setprecision(2) << balance << "\n";
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate; // annual interest rate (e.g., 0.03 == 3%)

public:
    SavingsAccount(const std::string& owner_, double initial, double rate)
        : Account(owner_, initial), interestRate(rate) {}

    // Savings withdraw: allow withdrawal only if enough balance (inherited logic suffices)
    void addInterest() {
        double interest = balance * interestRate;
        balance += interest;
        std::cout << owner << " earned interest " << interest << "\n";
    }

    void printSummary() const override {
        std::cout << "SavingsAccount - Owner: " << owner
                  << ", Balance: " << std::fixed << std::setprecision(2) << balance
                  << ", Rate: " << interestRate * 100 << "%\n";
    }
};

// Derived class: CheckingAccount (with overdraft limit)
class CheckingAccount : public Account {
private:
    double overdraftLimit; // how much negative balance is allowed

public:
    CheckingAccount(const std::string& owner_, double initial, double overdraft = 0.0)
        : Account(owner_, initial), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount <= 0) throw std::invalid_argument("Withdraw must be positive");
        if (balance - amount < -overdraftLimit) throw std::runtime_error("Exceeded overdraft limit");
        balance -= amount;
        std::cout << owner << " withdrew " << amount << " (checking)\n";
    }

    void printSummary() const override {
        std::cout << "CheckingAccount - Owner: " << owner
                  << ", Balance: " << std::fixed << std::setprecision(2) << balance
                  << ", Overdraft limit: " << overdraftLimit << "\n";
    }
};

// Simple demonstration in main()
int main() {
    // Use smart pointers and polymorphism
    std::vector<std::unique_ptr<Account>> accounts;
    accounts.emplace_back(std::make_unique<SavingsAccount>("Alice", 1000.0, 0.03));
    accounts.emplace_back(std::make_unique<CheckingAccount>("Bob", 200.0, 100.0));

    // operations
    try {
        accounts[0]->deposit(200.0);           // Alice deposit
        accounts[1]->withdraw(50.0);           // Bob withdraw
        accounts[0]->printSummary();           // Savings summary

        // Downcast safely if we need derived-specific behavior (demo only)
        if (SavingsAccount* s = dynamic_cast<SavingsAccount*>(accounts[0].get())) {
            s->addInterest();
        }

        // Attempt a withdraw that uses overdraft
        accounts[1]->withdraw(350.0); // Bob: 200 - 50 - 350 = -200, within overdraft 100? -> exceeds -> throws
    }
    catch (const std::exception& ex) {
        std::cerr << "Operation failed: " << ex.what() << "\n";
    }

    std::cout << "\nFinal account summaries:\n";
    for (const auto& acc : accounts) acc->printSummary();

    return 0;
}

