#include "ewaste.h"
#include <iostream>
#include <limits>
#include <cctype>

// Programmer: Chan Zi Xuan
// Purpose: Display the available operations in the terminal.
void displayMenu() {
    cout << "\n========== E-WASTE TRACKING SYSTEM ==========\n";
    cout << "1. Update Recycling Status\n";
    cout << "2. Delete Records\n";
    cout << "3. Calculate Total Collected Weight\n";
    cout << "4. Display All Records\n";
    cout << "0. Exit\n";
    cout << "==============================================\n";
}

// Programmer: Chan Zi Xuan
// Purpose: Read a non-empty line of text from the user.
string getNonEmptyInput(const string& prompt) {
    string value;

    while (true) {
        cout << prompt;
        getline(cin, value);

        if (cin.fail()) {
            cin.clear();
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        bool hasNonWhitespace = false;
        for (char character : value) {
            if (!isspace(static_cast<unsigned char>(character))) {
                hasNonWhitespace = true;
                break;
            }
        }

        if (hasNonWhitespace && value.find('|') == string::npos) {
            return value;
        }

        cout << "Input cannot be empty or contain the | character. Please try again.\n";
    }
}

// Programmer: Chan Zi Xuan
// Purpose: Read and validate an integer menu choice within the specified range.
int getMenuChoice(int minimum, int maximum) {
    int choice;

    while (true) {
        cout << "Enter your choice: ";
        if (cin >> choice && choice >= minimum && choice <= maximum) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid choice. Enter a whole number from "
             << minimum << " to " << maximum << ".\n";

        if (cin.eof()) {
            cout << "\nInput stream closed. Exiting.\n";
            return 0;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
