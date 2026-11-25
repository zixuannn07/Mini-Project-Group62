#include "ewaste.h"
#include <iostream>
#include <iomanip>

// Programmer: Chan Zi Xuan
// Purpose: Calculate the combined weight of all records currently stored.
double calculateTotalWeight(const vector<EWasteRecord>& records) {
    double totalWeight = 0.0;

    for (const EWasteRecord& record : records) {
        totalWeight += record.weight;
    }

    return totalWeight;
}

// Programmer: Chan Zi Xuan
// Purpose: Display the number of records and their combined collected weight.
void displayTotalWeight(const vector<EWasteRecord>& records) {
    double totalWeight = calculateTotalWeight(records);

    cout << "\n========== TOTAL COLLECTED WEIGHT ==========\n";
    cout << "Total number of collected records: " << records.size() << '\n';
    cout << fixed << setprecision(2);
    cout << "Total collected weight: " << totalWeight << " kg\n";
    cout << "=============================================\n";
}

