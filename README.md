# Mini-Project-Group62
E-WASTE TRACKING SYSTEM - CHAN ZI XUAN
=====================================

MODULES
1. Update Recycling Status
2. Delete Records
3. Calculate Total Collected Weight

FILES
main.cpp                 Program entry point; calls runProgram only.
ewaste.h                 Record structure and function declarations.
fileHandling.cpp         Loads and saves text-file records.
inputAndMenu.cpp         Terminal menu and input validation.
recycling.cpp            Record search, display and status update.
recordManagement.cpp     Delete and confirmation functions.
weightCalculation.cpp    Total collected weight functions.
program.cpp              Main menu sequence and module coordination.
ewaste.txt               Sample data.

COMPILE
Open a terminal in this folder and run:

g++ -std=c++11 -Wall -Wextra -pedantic main.cpp fileHandling.cpp inputAndMenu.cpp recycling.cpp recordManagement.cpp weightCalculation.cpp program.cpp -o ewaste

RUN
Windows:
    ewaste.exe

Linux/macOS:
    ./ewaste

DATA FORMAT
ID|ItemName|WeightInKg|Status

Example:
E001|Laptop|2.50|Recycled

ASSUMPTIONS
- All records represent e-waste items that have already been collected.
- The total weight includes both Recycled and Not Recycled records.
- IDs are unique and case-sensitive.
- IDs and item names cannot contain the | separator.
- Weight must be greater than zero.
- Status must be Recycled or Not Recycled.
- Deleting a record permanently removes it from the text file.
- A missing data file is treated as an empty file and is created when possible.
- The sample data is for demonstration; users may add records by editing the text file.
- This independent module does not include adding new records because that is outside the three assigned functions.

IMPORTANT
Make a backup copy of ewaste.txt before testing deletion if you want to retain the original sample data.