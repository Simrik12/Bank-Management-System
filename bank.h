#pragma once

#include <iostream>
using namespace std;

//Constant to define the maximum number of accounts allowed
const int MAX_ACCOUNTS = 100;

// Account class to represent the individual bank accounts
class Account {
    public:
      int accountNumber;
      string name;
      double balance;

      //Default constructor
      Account();

      //Parameterized constructor to initialize an account
      Account (int accNo, string accName, double initialBalance);
};

//Bank class handles the operations related to the bank accounts
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
};
