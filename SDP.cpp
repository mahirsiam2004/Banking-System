#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Account {
    int accountNumber;
    string name;
    float balance;
};

vector<Account> accounts;
bool bannerShown = false;

void displayBanner() {
    if (!bannerShown) {
        cout << "======================================================\n";
        cout << "=                                                    =\n";
        cout << "=            WELCOME TO BANK MANAGEMENT SYSTEM       =\n";
        cout << "=                                                    =\n";
        cout << "=            Developed by Team:                      =\n";
        cout << "=           Mahir, Tarek, Shafayet, Abdullah, Rafi   =\n";
        cout << "=                                                    =\n";
        cout << "======================================================\n";
        cout << "               C++ PROJECT IMPLEMENTATION            \n";
        cout << "======================================================\n\n\n";
        bannerShown = true;
    }
}

void createAccount() {
    Account newAccount;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, newAccount.name);

    newAccount.accountNumber = accounts.size() + 1;
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);

    cout << "Congratulations!! Your account created successfully! Your account number is " << newAccount.accountNumber << ".\n";
}

void depositMoney() {
    int accNumber;
    float amount;
    cout << "Enter account number: ";
    cin >> accNumber;

    if (accNumber > 0 && accNumber <= accounts.size()) {
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            accounts[accNumber - 1].balance += amount;
            cout << "Successfully deposited. New balance is " << accounts[accNumber - 1].balance << ".\n";
        } else {
            cout << "Invalid amount.\n";
        }
    } else {
        cout << "Invalid account number.\n";
    }
}

void withdrawMoney() {
    int accNumber;
    float amount;
    cout << "Enter account number: ";
    cin >> accNumber;

    if (accNumber > 0 && accNumber <= accounts.size()) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= accounts[accNumber - 1].balance) {
            accounts[accNumber - 1].balance -= amount;
            cout << "Successfully withdrawn. New balance is " << accounts[accNumber - 1].balance << ".\n";
        } else {
            cout << "Invalid amount or insufficient balance.\n";
        }
    } else {
        cout << "Invalid account number.\n";
    }
}

void checkBalance() {
    int accNumber;
    cout << "Enter account number: ";
    cin >> accNumber;

    if (accNumber > 0 && accNumber <= accounts.size()) {
        cout << "Account holder: " << accounts[accNumber - 1].name << "\n";
        cout << "Balance: " << accounts[accNumber - 1].balance << "\n";
    } else {
        cout << "Invalid account number.\n";
    }
}

void deleteAccount() {
    int accNumber;
    cout << "Enter account number: ";
    cin >> accNumber;

    if (accNumber > 0 && accNumber <= accounts.size()) {
        accounts.erase(accounts.begin() + accNumber - 1);
        cout << "Account deleted successfully.\n";
    } else {
        cout << "Invalid account number.\n";
    }
}

void menu() {
    int choice;
    displayBanner();
    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Delete Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
