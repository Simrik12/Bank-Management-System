#pragma once

#include <iostream>
#include <string>
using namespace std;

//Constant to define the maximum number of accounts allowed
const int MAX_ACCOUNTS = 100;

// Class representing a bank account
class Account {
    public:
      int accountNumber;
      string name;
      string dateofbirth;
      string phoneNumber;
      double balance;
      string accounttype;

      //Default constructor
      Account();

      //Parameterized constructor to initialize an account
      Account (int accNo, string accName, string dob, string phone, double initialBalance, string accType);
    
      //Applying 2% per month for savin accounts)
      void applyInterest();
};

//Class representing the bank system
class Bank {
    private:
    Account accounts [MAX_ACCOUNTS];    //Array to store the accounts
    int nextAccountNumber;              //Variable assigning the next available account number
    int totalAccounts;                  //Keeping the track of the total number of active accounts

    public:
    //Constructor to initialize the bank data
    Bank ();
    void openAccount();     //Function to open account
    void deposit();         //Function to deposit money
    void withdraw();        //Function to withdraw money
    void checkDetails();    //Function to check the details
    void closeAccount();    //Function to close an account
    void applyIntertestToAll();  //Applying interest to all saving accounts
};
