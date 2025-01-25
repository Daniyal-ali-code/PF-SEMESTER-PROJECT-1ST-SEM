#include <iostream>
#include <fstream>  // we use this library for file handling
#include <string>
#include <limits>   // we use this library for numeric_limits function
using namespace std;

void StartingMenu();
void RegisterUser();
void LoginMenu();
void AddExpense(const string& username);
void HandleInvalidInput(int maxChoice);

void StartingMenu() {
    int choice;
    do {
        cout << "\nWELCOME TO EXPENSE TRACKING SYSTEM..." << endl;
        cout << "PRESS 1 : REGISTER" << endl;
        cout << "PRESS 2 : LOGIN" << endl;
        cout << "PRESS 3 : EXIT" << endl;
        cout << "ENTER YOUR CHOICE: ";

        // Checking if the provided input is an integer
        if (!(cin >> choice)) {
            HandleInvalidInput(3);
        } else if (choice < 1 || choice > 3) {
            cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-3." << endl;
        } else {
            switch (choice) {
                case 1: {
                    RegisterUser();
                    break;
                }
                case 2: {
                    LoginMenu();
                    break;
                }
                case 3: {
                    cout << "\nEXITING THE PROGRAM..." << endl;
                    break;
                }
            }
        }
    } while (choice != 3);
}

void RegisterUser() {
    string name, password, filename;
    cout << "\n--- REGISTER NEW USER ---" << endl;

    cin.ignore(); // This function clears the input history
    cout << "ENTER YOUR NAME: ";
    getline(cin, name);

    cout << "ENTER YOUR PASSWORD: ";
    getline(cin, password);

    // The file that will be created will be named after the username
    filename = name + ".txt";

    // Checking if the file already exists
    ifstream checkFile(filename);
    if (checkFile.is_open()) {
        cout << "\nERROR: USER ALREADY EXISTS. PLEASE LOGIN OR USE A DIFFERENT NAME." << endl;
        checkFile.close();
        return;
    }

    // Saving user's data into file
    ofstream userFile(filename);
    if (userFile.is_open()) {
        userFile << "Name: " << name << endl;
        userFile << "Password: " << password << endl;
        userFile.close();
        cout << "\nUSER REGISTERED SUCCESSFULLY! DATA SAVED TO " << filename << endl;
    } else {
        cout << "\nERROR: COULD NOT CREATE FILE FOR USER." << endl;
    }
}

void LoginMenu() {
    string username, password, filename;
    cout << "\n--- LOGIN ---" << endl;

    cin.ignore();  // Clear input buffer
    cout << "ENTER YOUR NAME: ";
    getline(cin, username);

    cout << "ENTER YOUR PASSWORD: ";
    getline(cin, password);

    // Open the user's file to verify credentials
    filename = username + ".txt";
    ifstream userFile(filename);
    if (userFile.is_open()) {
        string storedName, storedPassword;
        getline(userFile, storedName);
        getline(userFile, storedPassword);
        userFile.close();

        // Verify credentials
        if (storedName == "Name: " + username && storedPassword == "Password: " + password) {
            cout << "\nLOGIN SUCCESSFUL! WELCOME, " << username << "!\n";
            int choice;
            do {
                cout << "\nPRESS 1 : ADD EXPENSE" << endl;
                cout << "PRESS 2 : VIEW EXPENSE" << endl;
                cout << "PRESS 3 : EXPORT DATA" << endl;
                cout << "PRESS 4 : LOGOUT" << endl;
                cout << "ENTER YOUR CHOICE: ";

                if (!(cin >> choice)) {
                    HandleInvalidInput(4);
                } else if (choice < 1 || choice > 4) {
                    cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-4." << endl;
                } else {
                    switch (choice) {
                        case 1:
                            AddExpense(username);
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            cout << "\nLOGGING OUT..." << endl;
                            return;
                    }
                }
            } while (true);
        } else {
            cout << "\nERROR: INCORRECT PASSWORD." << endl;
        }
    } else {
        cout << "\nERROR: USER DOES NOT EXIST. PLEASE REGISTER FIRST." << endl;
    }
}

void AddExpense(const string& username) {
    string description;
    double amount;
    string filename = username + "_expenses.txt";  // Creating file for storing the user's expenses

    cout << "\n--- ADD EXPENSE ---\n";

    cin.ignore();
    cout << "ENTER EXPENSE DESCRIPTION: ";
    getline(cin, description);

    cout << "ENTER AMOUNT: ";
    cin >> amount;

    if (cin.fail() || amount <= 0) {
        HandleInvalidInput(1);
        return;
    }

    // Saving the expense in the user's file
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << description << " : PKR" << amount << endl;
        outFile.close();
        cout << "\nEXPENSE ADDED SUCCESSFULLY!\n";
    } else {
        cout << "\nERROR: COULD NOT SAVE EXPENSE." << endl;
    }
}

void HandleInvalidInput(int maxChoice) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-" << maxChoice << "." << endl;
}

int main() {
    StartingMenu();
    return 0;
}
