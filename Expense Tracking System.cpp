#include <iostream>
#include <fstream>   // For file handling
#include <string>
#include <limits>    // For numeric_limits
#include <iomanip>   // For formatting output

using namespace std;

void StartingMenu();
void RegisterUser();
void LoginMenu();
void AddExpense(const string& username);
void ViewExpenses(const string& username);
void DeleteExpense(const string& username);
void TotalExpenses(const string& username);
void HandleInvalidInput(int maxChoice);

void StartingMenu() {
    int choice;
    do {
        cout << "\nWELCOME TO EXPENSE TRACKING SYSTEM...\n";
        cout << "PRESS 1 : REGISTER\n";
        cout << "PRESS 2 : LOGIN\n";
        cout << "PRESS 3 : HELPLINE\n";
        cout << "PRESS 4 : EXIT\n";
        cout << "ENTER YOUR CHOICE: ";

        while (!(cin >> choice) || choice < 1 || choice > 4) {
            HandleInvalidInput(4);
        }

        switch (choice) {
            case 1:
                RegisterUser();
                break;
            case 2:
                LoginMenu();
                break;
            case 3:
                cout << "\nFOR ANY QUERIES, PLEASE CONTACT:\n";
                cout << left << setw(25) << "MR. DANIYAL ALI" << right << setw(15) << "+92 333 0276929\n";
                cout << left << setw(25) << "MS. AYESHA ZAFAR" << right << setw(15) << "+92 344 3822791\n";
                cout << left << setw(25) << "MR. SYED ABDUL MUIZ" << right << setw(15) << "+92 341 2287624\n";
                break;
            case 4:
                cout << "\nEXITING THE PROGRAM...\n";
                break;
        }
    } while (choice != 4);
}

void RegisterUser() {
    string name, password, filename;
    cout << "\n--- REGISTER NEW USER ---\n";

    cin.ignore();
    cout << "ENTER YOUR NAME: ";
    getline(cin, name);

    cout << "ENTER YOUR PASSWORD: ";
    getline(cin, password);

    filename = name + ".txt";

    ifstream checkFile(filename);
    if (checkFile.is_open()) {
        cout << "\nERROR: USER ALREADY EXISTS. PLEASE LOGIN OR USE A DIFFERENT NAME.\n";
        checkFile.close();
        return;
    }

    ofstream userFile(filename);
    if (userFile.is_open()) {
        userFile << "Name: " << name << endl;
        userFile << "Password: " << password << endl;
        userFile.close();
        cout << "\nUSER REGISTERED SUCCESSFULLY!\n";
    } else {
        cout << "\nERROR: COULD NOT CREATE FILE FOR USER.\n";
    }
}

void LoginMenu() {
    string username, password, filename;
    int choice;
    cout << "\n--- LOGIN ---\n";

    cin.ignore();
    cout << "ENTER YOUR NAME: ";
    getline(cin, username);

    cout << "ENTER YOUR PASSWORD: ";
    getline(cin, password);

    filename = username + ".txt";
    ifstream userFile(filename);
    if (userFile.is_open()) {
        string storedName, storedPassword;
        getline(userFile, storedName);
        getline(userFile, storedPassword);
        userFile.close();

        if (storedName == "Name: " + username && storedPassword == "Password: " + password) {
            cout << "\nLOGIN SUCCESSFUL! WELCOME, " << username << "!\n";
            do {
                cout << "\nPRESS 1 : ADD EXPENSE\n";
                cout << "PRESS 2 : VIEW EXPENSES\n";
                cout << "PRESS 3 : DELETE EXPENSE\n";
                cout << "PRESS 4 : TOTAL EXPENSES\n";
                cout << "PRESS 5 : LOGOUT\n";
                cout << "ENTER YOUR CHOICE: ";

                while (!(cin >> choice) || choice < 1 || choice > 5) {
                    HandleInvalidInput(5);
                }

                switch (choice) {
                    case 1:
                        AddExpense(username);
                        break;
                    case 2:
                        ViewExpenses(username);
                        break;
                    case 3:
                        DeleteExpense(username);
                        break;
                    case 4:
                        TotalExpenses(username);
                        break;
                    case 5:
                        cout << "\nLOGGING OUT...\n";
                        return;
                }
            } while (true);
        } else {
            cout << "\nERROR: INVALID CREDENTIALS.\n";
        }
    } else {
        cout << "\nERROR: USER DOES NOT EXIST. PLEASE REGISTER FIRST.\n";
    }
}

void AddExpense(const string& username) {
    string description;
    double amount;
    string filename = username + "_expenses.txt";

    cout << "\n--- ADD EXPENSE ---\n";

    cin.ignore();
    cout << "ENTER EXPENSE DESCRIPTION: ";
    getline(cin, description);

    cout << "ENTER AMOUNT: ";
    while (!(cin >> amount) || amount <= 0) {
        HandleInvalidInput(1);
        cout << "ENTER AMOUNT: ";
    }

    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << description << ":" << amount << endl;
        outFile.close();
        cout << "\nEXPENSE ADDED SUCCESSFULLY!\n";
    } else {
        cout << "\nERROR: COULD NOT SAVE EXPENSE.\n";
    }
}

void ViewExpenses(const string& username) {
    string filename = username + "_expenses.txt";
    ifstream inFile(filename);

    cout << "\n--- VIEW EXPENSES ---\n";

    if (inFile.is_open()) {
        string line;
        bool hasExpenses = false;

        cout << left << setw(30) << "DESCRIPTION" << right << setw(10) << "AMOUNT (PKR)" << endl;
        cout << string(40, '-') << endl;

        while (getline(inFile, line)) {
            size_t delimiterPos = line.find(':');
            if (delimiterPos != string::npos) {
                string description = line.substr(0, delimiterPos);
                double amount = stod(line.substr(delimiterPos + 1));
                hasExpenses = true;

                cout << left << setw(30) << description 
                     << right << setw(10) << fixed << setprecision(2) << amount << endl;
            }
        }

        inFile.close();

        if (!hasExpenses) {
            cout << "\nNO EXPENSES FOUND FOR THIS USER.\n";
        }
    } else {
        cout << "\nERROR: COULD NOT OPEN EXPENSES FILE OR NO EXPENSES FOUND.\n";
    }
}

void DeleteExpense(const string& username) {
    string filename = username + "_expenses.txt";
    ifstream inFile(filename);
    ofstream tempFile("temp.txt");

    cout << "\n--- DELETE EXPENSE ---\n";
    if (inFile.is_open() && tempFile.is_open()) {
        string line;
        string descriptionToDelete;
        cout << "ENTER EXPENSE DESCRIPTION TO DELETE: ";
        cin.ignore();
        getline(cin, descriptionToDelete);

        bool found = false;
        while (getline(inFile, line)) {
            size_t delimiterPos = line.find(':');
            if (delimiterPos != string::npos) {
                string description = line.substr(0, delimiterPos);
                if (description == descriptionToDelete) {
                    found = true;
                    cout << "DELETING EXPENSE: " << line << endl;
                    continue; // Skip writing this line to the temp file
                }
            }
            tempFile << line << endl; // Write the line to the temp file
        }

        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (found) {
            cout << "\nEXPENSE DELETED SUCCESSFULLY!\n";
        } else {
            cout << "\nNO EXPENSE FOUND WITH DESCRIPTION: " << descriptionToDelete << endl;
        }
    } else {
        cout << "\nERROR: COULD NOT OPEN EXPENSES FILE.\n";
    }
}

void TotalExpenses(const string& username) {
    string filename = username + "_expenses.txt";
    ifstream inFile(filename);
    double total = 0.0;

    cout << "\n--- TOTAL EXPENSES ---\n";

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            size_t delimiterPos = line.find(':');
            if (delimiterPos != string::npos) {
                double amount = stod(line.substr(delimiterPos + 1));
                total += amount;
            }
        }
        inFile.close();

        cout << "TOTAL EXPENSES: PKR " << fixed << setprecision(2) << total << endl;
    } else {
        cout << "\nERROR: COULD NOT OPEN EXPENSES FILE.\n";
    }
}

void HandleInvalidInput(int maxChoice) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-" << maxChoice << ".\n";
}

int main() {
    StartingMenu();
    return 0;
}
