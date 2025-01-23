#include <iostream>
#include <vector>
using namespace std;

struct User {
	string username;
	string password;
};
	
void registerUser() {
	User newUser;
	cout << "Enter username: ";
	cin >> newUser.username;
	cout << "Enter password: ";
	cin >>  newUser.password;

	users.push_back(newUser);
	saveUsers();

	cout << "User registered successfully."S << endl;
}

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

// Save users to file
void saveUsers() {
    ofstream file("users.txt");
    for (const auto &user : users) {
        file << user.username << "," << user.password << endl;
    }
    file.close();
}
void addExpense() {
    Expense newExpense;
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, newExpense.category);
    cout << "Enter description: ";
    getline(cin, newExpense.description);
    cout << "Enter amount: ";
    cin >> newExpense.amount;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> newExpense.date;

    expenses.push_back(newExpense);
    saveExpenses();

    cout << "Expense added successfully!" << endl;
}



struct Expense {
    string category;
    string description;
    double amount;
    string date;
};

int main(){
	int choice;
	do {
		cout << "Welcome" << endl;
		cout << "press 1 - Register";
		cout << "press 2 - Login";
		cout << "press 3 - Exit";
		cout << "What is your choice? Enter here: ";
		cin >> choice;
		
	}while (choice != 3);
	
	return 0;
}

