#include <iostream>
using namespace std;

class Wallet {
private:
    double balance;
    double* transactions;
    int size;

public:
    Wallet(double b = 0) {
        balance = b;
        if (b != 0)
            size = 1;
        else
            size = 0;

        if (size == 1) {
            transactions = new double[1];
            transactions[0] = b;
        } else {
            transactions = nullptr;
        }
    }

    Wallet(const Wallet& w) {
        balance = w.balance;
        size = w.size;

        if (size > 0) {
            transactions = new double[size];
            for (int i = 0; i < size; i++)
                transactions[i] = w.transactions[i];
        } else {
            transactions = nullptr;
        }
    }

    ~Wallet() {
        delete[] transactions;
    }

    void addTransaction(double amount) {
        double* newArr = new double[size + 1];

        for (int i = 0; i < size; i++)
            newArr[i] = transactions[i];

        newArr[size] = amount;

        delete[] transactions;
        transactions = newArr;

        size++;
        balance += amount;
    }

    void display() const {
        cout << "Balance: " << balance << endl;
        cout << "Transactions: ";
        for (int i = 0; i < size; i++)
            cout << transactions[i] << " ";
        cout << endl;
    }

    Wallet operator+(const Wallet& w) {
        Wallet temp(balance + w.balance);

        for (int i = 0; i < size; i++)
            temp.addTransaction(transactions[i]);

        for (int i = 0; i < w.size; i++)
            temp.addTransaction(w.transactions[i]);

        return temp;
    }

    Wallet operator-(double amount) {
        Wallet temp(*this);
        temp.addTransaction(-amount);
        return temp;
    }

    Wallet& operator+=(double amount) {
        addTransaction(amount);
        return *this;
    }

    Wallet& operator-=(double amount) {
        addTransaction(-amount);
        return *this;
    }

    bool operator==(const Wallet& w) {
        return balance == w.balance;
    }

    bool operator<(const Wallet& w) {
        return balance < w.balance;
    }

    bool operator>(const Wallet& w) {
        return balance > w.balance;
    }

    bool operator&&(const Wallet& w) {
        return (balance != 0 && w.balance != 0);
    }

    bool operator||(const Wallet& w) {
        return (balance != 0 || w.balance != 0);
    }

    Wallet operator-() {
        Wallet temp(*this);
        temp.balance = -balance;
        return temp;
    }

    Wallet& operator++() {
        addTransaction(10);
        return *this;
    }

    Wallet operator++(int) {
        Wallet temp(*this);
        addTransaction(10);
        return temp;
    }

    Wallet& operator--() {
        addTransaction(-5);
        return *this;
    }

    Wallet& operator=(const Wallet& w) {
        if (this != &w) {
            delete[] transactions;

            balance = w.balance;
            size = w.size;

            if (size > 0) {
                transactions = new double[size];
                for (int i = 0; i < size; i++)
                    transactions[i] = w.transactions[i];
            } else {
                transactions = nullptr;
            }
        }
        return *this;
    }

    double operator[](int index) {
        if (index >= 0 && index < size)
            return transactions[index];
        else
            throw out_of_range("Invalid index");
    }

    friend Wallet operator+(double amount, const Wallet& w);
};

Wallet operator+(double amount, const Wallet& w) {
    Wallet temp(w);
    temp.addTransaction(amount);
    return temp;
}

int main() {
    Wallet w1(100), w2(50);

    w1 += 20;
    w2 -= 10;

    Wallet w3 = w1 + w2;

    cout << "Wallet 1:\n";
    w1.display();

    cout << "\nWallet 2:\n";
    w2.display();

    cout << "\nCombined Wallet:\n";
    w3.display();

    cout << "\nFirst transaction of w1: " << w1[0] << endl;

    return 0;
}