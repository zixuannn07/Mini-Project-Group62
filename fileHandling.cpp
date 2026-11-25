#include "ewaste.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

// Assumption: Each record is stored on one line using the | character as a separator.
// Assumption: IDs and item names must not contain the | character.
// Assumption: The data file is created automatically when the program first saves records.

// Programmer: Chan Zi Xuan
// Purpose: Read all valid records from the text data file.
vector<EWasteRecord> loadRecords(const string& filename) {
    vector<EWasteRecord> records;
    ifstream inputFile(filename);

    // A missing file means the system has no saved records yet.
    if (!inputFile.is_open()) {
        ofstream createFile(filename);
        if (!createFile.is_open()) {
            cerr << "Error: Unable to create or open " << filename << ".\n";
        }
        return records;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream stream(line);
        EWasteRecord record;
        string weightText;
        string extraField;

        if (!getline(stream, record.id, '|') ||
            !getline(stream, record.itemName, '|') ||
            !getline(stream, weightText, '|') ||
            !getline(stream, record.status, '|')) {
            cerr << "Warning: A malformed data line was skipped.\n";
            continue;
        }

        // Reject lines with unexpected extra fields.
        if (getline(stream, extraField, '|')) {
            cerr << "Warning: A data line with extra fields was skipped.\n";
            continue;
        }

        try {
            size_t parsedCharacters = 0;
            record.weight = stod(weightText, &parsedCharacters);
            if (parsedCharacters != weightText.size() ||
                record.weight <= 0.0 ||
                (record.status != "Recycled" && record.status != "Not Recycled") ||
                record.id.empty() || record.itemName.empty()) {
                cerr << "Warning: An invalid data line was skipped.\n";
                continue;
            }
        } catch (...) {
            cerr << "Warning: A data line with an invalid weight was skipped.\n";
            continue;
        }
        
        records.push_back(record);
    }

    inputFile.close();
    return records;
}

// Programmer: Chan Zi Xuan
// Purpose: Save all records to the text data file, replacing its old contents.
bool saveRecords(const vector<EWasteRecord>& records, const string& filename) {
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to write to " << filename << ".\n";
        return false;
    }

    outputFile << fixed << setprecision(2);
    for (const EWasteRecord& record : records) {
        outputFile << record.id << '|'
                   << record.itemName << '|'
                   << record.weight << '|'
                   << record.status << '\n';
    }

    outputFile.close();
    if (!outputFile) {
        cerr << "Error: A problem occurred while saving the data.\n";
        return false;
    }

    return true;
}
