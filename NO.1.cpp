#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Account {
    string password;
    double balance = 0.0;
};

unordered_map<string, Account> accounts;

void createAccount() {
    string userID, password;
    cout << "Please enter your user id: ";
    cin >> userID;
    cout << "Please enter your password: ";
    cin >> password;

    if (accounts.find(userID) == accounts.end()) {
        accounts[userID] = {password, 0.0};
        cout << "Thank You! Your account has been created!" << endl;
    } else {
        cout << "Account already exists. Please try again." << endl;
    }
}

bool login(string &userID) {
    cout << "Please enter your user id: ";
    cin >> userID;
    cout << "Please enter your password: ";
    string password;
    cin >> password;

    if (accounts.find(userID) != accounts.end() && accounts[userID].password == password) {
        cout << "Access Granted!" << endl;
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***" << endl;
        return false;
    }
}

void withdrawMoney(string userID) {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;

    if (accounts[userID].balance >= amount) {
        accounts[userID].balance -= amount;
        cout << "Withdrawal successful! Your new balance is $" << accounts[userID].balance << "." << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
}

void depositMoney(string userID) {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;

    accounts[userID].balance += amount;
    cout << "Deposit successful! Your new balance is $" << accounts[userID].balance << "." << endl;
}

void requestBalance(string userID) {
    cout << "Your balance is $" << accounts[userID].balance << "." << endl;
}

int main() {
    char mainChoice, subChoice;
    string userID;

    cout << "Hi! Welcome to the ATM Machine!" << endl;

    while (true) {
        cout << "\nPlease select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cin >> mainChoice;

        if (mainChoice == 'c' || mainChoice == 'C') {
            createAccount();
        } else if (mainChoice == 'l' || mainChoice == 'L') {
            if (login(userID)) {
                while (true) {
                    cout << "\nPlease select an option from the menu below:" << endl;
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;
                    cin >> subChoice;

                    if (subChoice == 'd' || subChoice == 'D') {
                        depositMoney(userID);
                    } else if (subChoice == 'w' || subChoice == 'W') {
                        withdrawMoney(userID);
                    } else if (subChoice == 'r' || subChoice == 'R') {
                        requestBalance(userID);
                    } else if (subChoice == 'q' || subChoice == 'Q') {
                        cout << "Thank you for using the ATM. Goodbye!" << endl;
                        break;
                    } else {
                        cout << "Invalid option. Please try again." << endl;
                    }
                }
            }
        } else if (mainChoice == 'q' || mainChoice == 'Q') {
            cout << "Thank you for using the ATM. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

