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

