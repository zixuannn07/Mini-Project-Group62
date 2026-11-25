#ifndef EWASTE_H
#define EWASTE_H

#include <string>
#include <vector>

using namespace std;

// Programmer: Chan Zi Xuan
// Purpose: Define the structure used to store one electronic-waste record.
struct EWasteRecord {
    string id;
    string itemName;
    double weight;
    string status;
};

// Programmer: Chan Zi Xuan
// Purpose: Display the available operations in the terminal.
void displayMenu();

// Programmer: Chan Zi Xuan
// Purpose: Read all valid records from the text data file.
vector<EWasteRecord> loadRecords(const string& filename);

// Programmer: Chan Zi Xuan
// Purpose: Save all records to the text data file, replacing its old contents.
bool saveRecords(const vector<EWasteRecord>& records, const string& filename);

// Programmer: Chan Zi Xuan
// Purpose: Find and return the position of a record using its unique ID.
int searchRecordByID(const vector<EWasteRecord>& records, const string& id);

// Programmer: Chan Zi Xuan
// Purpose: Display the details of one electronic-waste record.
void displayRecord(const EWasteRecord& record);

// Programmer: Chan Zi Xuan
// Purpose: Update a selected record's recycling status.
void updateRecyclingStatus(vector<EWasteRecord>& records, const string& filename);

// Programmer: Chan Zi Xuan
// Purpose: Ask the user to confirm whether a selected record should be deleted.
bool confirmDeletion();

// Programmer: Chan Zi Xuan
// Purpose: Delete a selected record and save the remaining records.
void deleteRecord(vector<EWasteRecord>& records, const string& filename);

// Programmer: Chan Zi Xuan
// Purpose: Calculate the combined weight of all records currently stored.
double calculateTotalWeight(const vector<EWasteRecord>& records);

// Programmer: Chan Zi Xuan
// Purpose: Display the number of records and their combined collected weight.
void displayTotalWeight(const vector<EWasteRecord>& records);

// Programmer: Chan Zi Xuan
// Purpose: Read a non-empty line of text from the user.
string getNonEmptyInput(const string& prompt);

// Programmer: Chan Zi Xuan
// Purpose: Read and validate an integer menu choice within the specified range.
int getMenuChoice(int minimum, int maximum);

// Programmer: Chan Zi Xuan
// Purpose: Run the program menu and coordinate the three e-waste modules.
void runProgram(const string& filename);

#endif
