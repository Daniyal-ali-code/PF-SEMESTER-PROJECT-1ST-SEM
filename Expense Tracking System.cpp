#include <iostream>
#include <limits>  // For std::numeric_limits
using namespace std;

void StartingMenu();
void HandleInvalidInput();

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
            HandleInvalidInput();
        }
		else if (choice < 1 || choice > 3) {
            // Check if the choice is within a valid range
            cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-3." << endl;
        }
        else{
	        switch(choice){
        		case 1:{
					break;
				}
				case 2:{
					break;
				}
				case 3:{
					cout << "\nEXITING THE PROGRAM...";
					break;
				}
			}
    	}
	} while (choice != 3);
}


void HandleInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nINVALID INPUT. PLEASE ENTER A CHOICE BETWEEN 1-3." << endl;
}

int main() {
    StartingMenu();
    return 0;
}
