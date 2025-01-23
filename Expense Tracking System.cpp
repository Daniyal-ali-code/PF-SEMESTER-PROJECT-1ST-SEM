#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <sstream>

using namespace std;

// Storing user's dataa
struct User {
    string username;
    string password;
};

// Storing expenses
struct Expense {
    string category;
    string description;
    double amount;
    string date;
};

// Function prototypes
void registerUser();
bool loginUser();
void displayMenu();
void addExpense();
void viewExpenses();
void exportData();
void loadUsers();
void saveUsers();
void loadExpenses();
void saveExpenses();
void handleInvalidInput();

vector<User> users;
vector<Expense> expenses;
string currentUser;

// Registering users	
void registerUser() {
	User newUser;
	cout << "Enter username: ";
	cin >> newUser.username;
	cout << "Enter password: ";
	cin >>  newUser.password;

	string users.push_back(newUser);
	saveUsers();

	cout << "User registered successfully."S << endl;
}

// Loading users from the text file
void loadUsers() {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        vector<string> userData = split(line, ',');
        if (userData.size() == 2) {
            users.push_back({userData[0], userData[1]});
        }
    }
    file.close();
}
// Loading expenses from the text fiek

void loadExpenses() {
    ifstream file("expenses.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open expenses.txt for reading." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        vector<string> expenseData = split(line, ',');
        if (expenseData.size() == 4) {
            try {
                expenses.push_back({expenseData[0], expenseData[1], stod(expenseData[2]), expenseData[3]});
            } catch (const invalid_argument &e) {
                cerr << "Warning: Invalid data in expenses.txt. Skipping line." << endl;
            }
        } else {
            cerr << "Warning: Malformed data in expenses.txt. Skipping line." << endl;
        }
    }
    file.close();
}

<<<<<<< HEAD
int localCode() {
    return 1;
}

int remoteCode() {
    return 2;
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "No expenses found." << endl;
        return;
    }

    cout << left << setw(15) << "Category" << setw(20) << "Description" << setw(10) << "Amount" << setw(15) << "Date" << endl;
    cout << string(60, '-') << endl;

    for (const auto &expense : expenses) {
        cout << left << setw(15) << expense.category
             << setw(20) << expense.description
             << setw(10) << fixed << setprecision(2) << expense.amount
             << setw(15) << expense.date << endl;
    }
}

=======
>>>>>>> 9a658012cd6f40b43a5b5708bda4679eefdcebae
// Saving users in text file
void saveUsers() {
    ofstream file("users.txt");
    for (const auto &user : users) {
        file << user.username << "," << user.password << endl;
    }
    file.close();
}


struct Expense {
    string category;
    string description;
    double amount;
    string date;
};

int main() {
    try {
        loadUsers();
        loadExpenses();

        int choice;
        do {
            cout << "\nWelcome to Expense Tracker" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                handleInvalidInput();
                continue;
            }

            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    if (loginUser()) {
                        displayMenu();
                    }
                    break;
                case 3:
                    cout << "Exiting program. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 3);

    } catch (const exception &e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}
