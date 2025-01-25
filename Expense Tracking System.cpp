#include <iostream>
#include <fstream>  // For file handling
#include <string>
#include <limits>   // For std::numeric_limits
using namespace std;

void StartingMenu();
void RegisterUser();
void LoginMenu();
void HandleInvalidInput(int maxChoice);

void StartingMenu() {
    int choice;  // Declare 'choice' locally
    do {
        cout << "\nWELCOME TO EXPENSE TRACKING SYSTEM..." << endl;
        cout << "PRESS 1 : REGISTER" << endl;
        cout << "PRESS 2 : LOGIN" << endl;
        cout << "PRESS 3 : EXIT" << endl;
        cout << "ENTER YOUR CHOICE: ";

        // Check if input is an integer
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

    // Get user name
    cin.ignore(); // Clear input buffer
    cout << "ENTER YOUR NAME: ";
    getline(cin, name);

    // Get user password
    cout << "ENTER YOUR PASSWORD: ";
    getline(cin, password);

    // File name based on user's name
    filename = name + ".txt";

    // Check if the file already exists
    ifstream checkFile(filename);
    if (checkFile.is_open()) {
        cout << "\nERROR: USER ALREADY EXISTS. PLEASE LOGIN OR USE A DIFFERENT NAME." << endl;
		cout << "OR CONTACT MR. DANIYAL ALI ON +92 333 0276929 FOR FURTHER HELP." << endl;
        checkFile.close();
        return;
    }

    // Write user data to file
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


void HandleInvalidInput(int maxChoice) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-" << maxChoice << "." << endl;
}

int main() {
    StartingMenu();
    return 0;
}
