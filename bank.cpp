#include "bank.h"

//Default constructor for Account
Account::Account() : accountNumber(0), name (""), balance (0.0) {}

//Constructor for Account with parameters
Account::Account(int accNo, string accName, double initialBalance)
        : accountNumber (accNo), name (accName), balance (initialBalance) {}

//Constructor for Bank
Bank::Bank() : nextAccountNumber (1001), totalAccounts(0) {}

//Function to open a new account
void Bank::openAccount () {
    if (totalAccounts >= MAX_ACCOUNTS) {
        cout << "The bank is full so cannot open more accounts.\n";
        return;
    }

    string name;
    double initialBalance;

    cout << "Enter you name: ";
    cin >> name;
    cout << "Enter you initial deposit: ";
    cin >> initialBalance;

    accounts[totalAccounts] = Account(nextAccountNumber, name, initialBalance);
    cout << "Your account is created succesfully! Your account number is "  <<nextAccountNumber << ".\n";
    nextAccountNumber++;
    totalAccounts++;
}

//Function to deposit money
void Bank::deposit () {
    int accountNumber;
    double amount;

    cout << "Enter your account number: ";
    cin >> accountNumber;

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            accounts[i].balance += amount;
            cout << "The deposit is succesful! The new balance: "  <<accounts[i].balance << ".\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

//Function to check account details
void Bank:: checkDetails () {
    int accountNumber;

cout << "Enter account number: ";
cin >> accountNumber;

for (int i =0; i <totalAccounts; i++) {
    if (accounts[i].accountNumber == accountNumber) {
        cout << "Account Number: "  << accounts[i].accountNumber << "\n";
        cout << "Name: " << accounts[i].name << "\n";
        cout << "Blance: " << accounts[i].balance << "\n";
        return;
    }
}
  cout << "Accout not found!\n";
}

//Function to close an account
void Bank::closeAccount() {
    int accountNumber;

for (int i = 0; i < totalAccounts; i++) {
    if (accounts[i].accountNumber == accountNumber) {
        for (int j = i; j < totalAccounts -1; j++) {
            accounts[j] = accounts[j+1];
        }
        totalAccounts--;
        cout << "Account closed successfully!\n";
        return;
    }
}
   cout << "Account not found!\n";
}
