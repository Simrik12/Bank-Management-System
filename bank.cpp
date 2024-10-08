#include "bank.h"

// Constructor to initialize the bank data
Bank::Bank() : nextAccountNumber(1001), totalAccounts(0) {}

// Default constructor for Account class
Account::Account() : accountNumber(0), name(""), dateofbirth (""), phoneNumber(""), balance(0.0), accounttype("Savings") {}

// Parameterized constructor for Account class
Account::Account(int accNo, string accName, string dob, string phone, double initialBalance, string accType)
    : accountNumber(accNo), name(accName), dateofbirth (dob), phoneNumber (phone), balance(initialBalance), accounttype (accType) {}

//Function to apply 2% interest to saving accounts
void Account:: applyInterest() {
    if (accounttype == "Savings") {
        balance += balance *0.02;
    }
}

// Function to open a new account
void Bank::openAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        cout << "Cannot open more accounts as maximum account limit reached. .\n";
        return;
    }

    string name, dob, phone;
    double initialDeposit;

    cout << "Enter your name: ";
    cin >> name;
    
    cout << "Enter your date of birth (dd/mm/yyyy): ";
    cin >> dob;

    cout << "Enter your phone number: ";
    cin >> phone;

    cout << "Enter your initial deposit: ";
    cin >> initialDeposit;

    //Setting the account type to "Savings" as it is only allowed
    string accounttype = "Savings";

    accounts[totalAccounts] = Account(nextAccountNumber, name, dob, phone, initialDeposit, accounttype);
    cout << "Your savings account is created successfully! Your account number is " 
         << nextAccountNumber << ".\n";

    nextAccountNumber++;  // Increment of account number for the next new account
    totalAccounts++;  // Increment of the number of accounts
}

//Function to aplly Interest to all savings accounts
void Bank:: applyIntertestToAll() {
    for (int i = 0; i <totalAccounts; i++) {
        accounts[i].applyInterest();
    }
    cout << "Interest is applied to all savings accounts!\n";
}

// Function to deposit money into an account
void Bank::deposit() {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    // Finding the account by account number
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;

            accounts[i].balance += amount;  // Adding the amount to the account balance
            cout << "The deposit was successful! Your new balance: " << accounts[i].balance << ".\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to withdraw money from an account
void Bank::withdraw() {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    // Finding the account by account number
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            // Checking if there is sufficient balance
            if (amount > accounts[i].balance) {
                cout << "Insufficient balance!\n";
            } else {
                accounts[i].balance -= amount;
                cout << "The withdrawal was successful! The new balance is: " << accounts[i].balance << ".\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to check the details of an account
void Bank::checkDetails() {
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;

    // Finding the account by account number
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account Number: " << accounts[i].accountNumber << "\n";
            cout << "Account Holder: " << accounts[i].name << "\n";
            cout << "Current Balance: " << accounts[i].balance << "\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to close an existing account
void Bank::closeAccount() {
    int accountNumber;
    cout << "Enter account number to close: ";
    cin >> accountNumber;

    // Finding the account by account number
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            // Shifting the accounts to the left to remove the closed account
            for (int j = i; j < totalAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            totalAccounts--;  // Decreasing the total number of accounts
            cout << "Account closed successfully!\n";
            return;
        }
    }
    cout << "Account not found!\n";
}
