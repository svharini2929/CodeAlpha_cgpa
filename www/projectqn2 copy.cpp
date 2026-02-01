#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


class Transaction {
public:
    string type;
    double amount;
    string timestamp;

    Transaction(string t, double amt) : type(t), amount(amt) {
        time_t now = time(0);
        timestamp = ctime(&now);
    }
};

class Account {
private:
    int accountId;
    double balance;
    vector<Transaction> history;

public:
    Account(int id) : accountId(id), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount));
            return true;
        }
        cout << "Insufficient funds!" << endl;
        return false;
    }

    void displayHistory() {
        cout << "\n--- Transaction History for Account " << accountId << " ---" << endl;
        for (const auto& t : history) {
            cout << t.timestamp << " | " << t.type << ": $" << t.amount << endl;
        }
        cout << "Current Balance: $" << balance << endl;
    }

    double getBalance() { return balance; }
};

class Customer {
public:
    string name;
    Account userAccount;

    Customer(string n, int id) : name(n), userAccount(id) {}
};

int main() {
    Customer user1("Student", 101);
    user1.userAccount.deposit(500.0);
    user1.userAccount.withdraw(150.0);
    user1.userAccount.displayHistory();

    return 0;
}