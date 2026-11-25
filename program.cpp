#include "ewaste.h"
#include <iostream>
#include <iomanip>

// Programmer: Chan Zi Xuan
// Purpose: Run the program menu and coordinate the three e-waste modules.
void runProgram(const string& filename) {
    // Assumption: A record in this independent module represents an item already collected.
    // Assumption: Total collected weight includes both Recycled and Not Recycled records.
    // Assumption: Deleting a record removes it permanently from the text file.
    vector<EWasteRecord> records = loadRecords(filename);

    cout << "Welcome to the E-Waste Tracking System.\n";
    cout << "Loaded " << records.size() << " record(s) from " << filename << ".\n";

    int choice;
    do {
        displayMenu();
        choice = getMenuChoice(0, 4);

        switch (choice) {
            case 1:
                updateRecyclingStatus(records, filename);
                break;
            case 2:
                deleteRecord(records, filename);
                break;
            case 3:
                displayTotalWeight(records);
                break;
            case 4:
                if (records.empty()) {
                    cout << "No records are currently available.\n";
                } else {
                    cout << "\n========== ALL E-WASTE RECORDS ==========\n";
                    for (const EWasteRecord& record : records) {
                        displayRecord(record);
                    }
                }
                break;
            case 0:
                cout << "Thank you for using the E-Waste Tracking System. Goodbye!\n";
                break;
        }
    } while (choice != 0);
}

