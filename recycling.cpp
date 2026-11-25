#include "ewaste.h"
#include <iostream>

// Programmer: Chan Zi Xuan
// Purpose: Find and return the position of a record using its unique ID.
int searchRecordByID(const vector<EWasteRecord>& records, const string& id) {
    for (size_t index = 0; index < records.size(); ++index) {
        if (records[index].id == id) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

// Programmer: Chan Zi Xuan
// Purpose: Display the details of one electronic-waste record.
void displayRecord(const EWasteRecord& record) {
    cout << "\nRecord Details\n";
    cout << "ID: " << record.id << '\n';
    cout << "Item: " << record.itemName << '\n';
    cout << "Weight: " << record.weight << " kg\n";
    cout << "Recycling Status: " << record.status << '\n';
}

// Programmer: Chan Zi Xuan
// Purpose: Update a selected record's recycling status.
void updateRecyclingStatus(vector<EWasteRecord>& records, const string& filename) {
    if (records.empty()) {
        cout << "There are currently no records to update.\n";
        return;
    }

    string id = getNonEmptyInput("Enter the E-Waste ID to update: ");
    int position = searchRecordByID(records, id);

    if (position == -1) {
        cout << "Record not found. Please check the ID.\n";
        return;
    }

    displayRecord(records[position]);

    cout << "\nSelect the new recycling status:\n";
    cout << "1. Recycled\n";
    cout << "2. Not Recycled\n";
    int choice = getMenuChoice(1, 2);

    string newStatus = (choice == 1) ? "Recycled" : "Not Recycled";

    if (records[position].status == newStatus) {
        cout << "The record already has this recycling status. No change made.\n";
        return;
    }

    string oldStatus = records[position].status;
    records[position].status = newStatus;

    if (saveRecords(records, filename)) {
        cout << "Recycling status updated successfully from "
             << oldStatus << " to " << newStatus << ".\n";
    } else {
        records[position].status = oldStatus;
        cout << "Update cancelled because the file could not be saved.\n";
    }
}