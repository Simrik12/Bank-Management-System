#include "bank.h"

int main () {
    Bank bank;    //Creating a Bank object to manage accounts

    int choice;
    do {
        //Displaying the menu for banking operation
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Open a new account\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Check account details\n";
        cout << "5. Close an account\n";
        cout << "6. Apply Interest to all accounts\n";   
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            bank.openAccount();   //Opening a new account
            break;

            case 2:
            bank.deposit();       //Depositing money
            break;

            case 3:
            bank.withdraw();      //Withdrawing money
            break;

            case 4:
            bank.checkDetails();    //Checking the account details
            break;

            case 5:
            bank.closeAccount();     //Closing an account
            break;

            case 6:
            bank.applyIntertestToAll();
            break;

            case 7:
            cout << "Exiting the system.\n";    
            break;
        default:
            cout << "The choice is invalid! Please try again.\n";    //Handling the invalid input
    }
}  while (choice != 7);    //Continuing the loop until the user chooses to exit

return 0;
}