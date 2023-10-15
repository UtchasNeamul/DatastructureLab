#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    int accountNumber;
    string accountHolderName;
    double accountBalance;
};

void createAccount(BankAccount accounts[], int &numAccounts) {
    if (numAccounts < 10) {
        BankAccount newAccount;
        cout << "Enter Account Number: ";
        cin >> newAccount.accountNumber;
        cout << "Enter Account Holder's Name: ";
        cin.ignore();
        getline(cin, newAccount.accountHolderName);
        cout << "Enter Initial Account Balance: $";
        cin >> newAccount.accountBalance;

        accounts[numAccounts] = newAccount;
        numAccounts++;
        cout << "Account created successfully!" << endl;
    } else {
        cout << "Maximum number of accounts reached." << endl;
    }
}

void depositMoney(BankAccount accounts[], int numAccounts) {
    int accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter the amount to deposit: $";
            cin >> amount;
            accounts[i].accountBalance += amount;
            cout << "Deposit successful. New balance: $" << accounts[i].accountBalance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

void withdrawMoney(BankAccount accounts[], int numAccounts) {
    int accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Enter the amount to withdraw: $";
            cin >> amount;
            if (amount <= accounts[i].accountBalance) {
                accounts[i].accountBalance -= amount;
                cout << "Withdrawal successful. New balance: $" << accounts[i].accountBalance << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

void displayAccountDetails(BankAccount accounts[], int numAccounts) {
    int accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "Account Number: " << accounts[i].accountNumber << endl;
            cout << "Account Holder's Name: " << accounts[i].accountHolderName << endl;
            cout << "Account Balance: $" << accounts[i].accountBalance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

int main() {
    BankAccount accounts[10]; // Array to store bank accounts
    int numAccounts = 0;

    while (true) {
        cout << "Options:\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Account Details\n5. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts, numAccounts);
                break;
            case 2:
                depositMoney(accounts, numAccounts);
                break;
            case 3:
                withdrawMoney(accounts, numAccounts);
                break;
            case 4:
                displayAccountDetails(accounts, numAccounts);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
