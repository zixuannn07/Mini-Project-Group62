#include "ewaste.h"
#include <iostream>

// Programmer: Chan Zi Xuan
// Purpose: Ask the user to confirm whether a selected record should be deleted.
bool confirmDeletion() {
    while (true) {
        cout << "Are you sure you want to delete this record? (Y/N): ";
        string answer;
        getline(cin, answer);

        if (answer == "Y" || answer == "y") {
            return true;
        }
        if (answer == "N" || answer == "n") {
            return false;
        }

        cout << "Invalid response. Please enter Y or N.\n";
    }
}

// Programmer: Chan Zi Xuan
// Purpose: Delete a selected record and save the remaining records.
void deleteRecord(vector<EWasteRecord>& records, const string& filename) {
    if (records.empty()) {
        cout << "There are currently no records to delete.\n";
        return;
    }

    string id = getNonEmptyInput("Enter the E-Waste ID to delete: ");
    int position = searchRecordByID(records, id);

    if (position == -1) {
        cout << "Record not found. Please check the ID.\n";
        return;
    }

    cout << "\nThe following record will be deleted:\n";
    displayRecord(records[position]);

    if (!confirmDeletion()) {
        cout << "Deletion cancelled. The record was not changed.\n";
        return;
    }

    EWasteRecord deletedRecord = records[position];
    records.erase(records.begin() + position);

    if (saveRecords(records, filename)) {
        cout << "Record " << deletedRecord.id << " deleted successfully.\n";
    } else {
        // Restore the record in memory if saving the deletion fails.
        records.insert(records.begin() + position, deletedRecord);
        cout << "Deletion cancelled because the file could not be saved.\n";
    }
}

