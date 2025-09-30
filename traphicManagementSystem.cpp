#include <iostream>
#include <string>
#include <fstream>       // For file handling
#include <sstream>       // For parsing CSV
#include <vector>        // For storing column names
#include <unordered_map> // For mapping column names to indices
using namespace std;

// Global column names for vehicle records
const vector<string> VEHICLE_COLUMN_NAMES = {"Owner Name", "Contact Number", "Registration Number", "Vehicle Type", "Model"};

// Global column names for challan records
const vector<string> CHALLAN_COLUMN_NAMES = {"Owner Name", "Registration Number", "Challan Name", "Fine", "Is Paid"};

class VehicleRecord
{
public:
    long registrationNo;
    long contactNo;
    string ownerName, vehicleType, model;

    VehicleRecord()
    {
        cout << "Enter the Owner Name: ";
        getline(cin, ownerName);

        cout << "Enter the Contact Number: ";
        cin >> contactNo;

        cout << "Enter Registration Number: ";
        cin >> registrationNo;

        cin.ignore();

        cout << "Enter the Vehicle Type: ";
        getline(cin, vehicleType);

        cout << "Enter the Model Name: ";
        getline(cin, model);

        // Save the data to a CSV file
        saveToCSV();
    }

    void saveToCSV()
    {
        ofstream file("VehicleRecords.csv", ios::app); // Open file in append mode
        if (file.is_open())
        {
            // Write the header if the file is empty
            file.seekp(0, ios::end);
            if (file.tellp() == 0)
            {
                for (size_t i = 0; i < VEHICLE_COLUMN_NAMES.size(); ++i)
                {
                    file << VEHICLE_COLUMN_NAMES[i];
                    if (i < VEHICLE_COLUMN_NAMES.size() - 1)
                        file << ",";
                }
                file << endl;
            }

            // Write the record
            file << ownerName << "," << contactNo << "," << registrationNo << ","
                 << vehicleType << "," << model << endl;
            file.close();
            cout << "Vehicle record saved to VehicleRecords.csv successfully!" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing!" << endl;
        }
    }

    void displayVehicle()
    {
        cout << "Owner Name: " << ownerName << endl;
        cout << "Contact of Owner: " << contactNo << endl;
        cout << "Registration Number: " << registrationNo << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Model: " << model << endl;
    }
};

class IssueTrafficChallan
{
public:
    string challanName;
    int fine;
    string isPaid;

    void searchByRegistrationNumber(long regNo)
    {
        ifstream file("VehicleRecords.csv"); // Open the file in read mode
        if (!file.is_open())
        {
            cout << "Error: Unable to open file for reading!" << endl;
            return;
        }

        string line;
        unordered_map<string, int> headerMap; // Map to store column name -> index
        bool found = false;

        // Read the header line
        if (getline(file, line))
        {
            stringstream ss(line);
            string column;
            int index = 0;

            // Map column names to their indices
            while (getline(ss, column, ','))
            {
                headerMap[column] = index++;
            }
        }

        // Check if required columns exist
        if (headerMap.find("Registration Number") == headerMap.end() ||
            headerMap.find("Owner Name") == headerMap.end())
        {
            cout << "Error: Missing required columns in the CSV file!" << endl;
            file.close();
            return;
        }

        // Read the data rows
        while (getline(file, line))
        {
            stringstream ss(line);
            string field;
            vector<string> row;

            // Split the row into fields
            while (getline(ss, field, ','))
            {
                row.push_back(field);
            }

            // Check if the registration number matches
            if (stol(row[headerMap["Registration Number"]]) == regNo)
            {
                cout << "========== Owner Info ==========" << endl;
                cout << "Record Found!" << endl;
                cout << "Owner Name: " << row[headerMap["Owner Name"]] << endl;
                cout << "Registration Number: " << row[headerMap["Registration Number"]] << endl;

                // Take challan details
                cin.ignore(); // Clear input buffer
                cout << "Enter the rule broken by " << row[headerMap["Owner Name"]] << ": ";
                getline(cin, challanName);

                cout << "Amount of fine: ";
                cin >> fine;

                cin.ignore(); // Clear input buffer
                cout << "Is the fine paid? (yes/no): ";
                getline(cin, isPaid);

                // Save the challan details to a CSV file
                saveChallanToCSV(row[headerMap["Owner Name"]], row[headerMap["Registration Number"]]);
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "No record found for Registration Number: " << regNo << endl;
        }

        file.close();
    }

    void saveChallanToCSV(const string &ownerName, const string &registrationNo)
    {
        ofstream file("TrafficChallans.csv", ios::app); // Open file in append mode
        if (file.is_open())
        {
            // Write the header if the file is empty
            file.seekp(0, ios::end);
            if (file.tellp() == 0)
            {
                for (size_t i = 0; i < CHALLAN_COLUMN_NAMES.size(); ++i)
                {
                    file << CHALLAN_COLUMN_NAMES[i];
                    if (i < CHALLAN_COLUMN_NAMES.size() - 1)
                        file << ",";
                }
                file << endl;
            }

            // Write the challan record
            file << ownerName << "," << registrationNo << "," << challanName << ","
                 << fine << "," << isPaid << endl;
            file.close();
            cout << "Challan record saved to TrafficChallans.csv successfully!" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing!" << endl;
        }
    }
};

class TrafficManagementSystem {
public:
    void displayMenu() {
        cout << "===========================================" << endl;
        cout << "          TRAFFIC MANAGEMENT SYSTEM         " << endl;
        cout << "===========================================" << endl;
        cout << "| 1. Add new vehicle Record               |" << endl;
        cout << "| 2. Issue Traffic Challan                |" << endl;
        cout << "| 3. Search Challan by Vehicle REG. No.   |" << endl;
        cout << "| 4. Search Challan by Owner Name         |" << endl;
        cout << "| 5. Display Vehicle Records              |" << endl;
        cout << "| 6. Display Traffic Challan Records      |" << endl;
        cout << "| 7. Monitor Traffic Booth                |" << endl;
        cout << "| 8. Show Emergency Information           |" << endl;
        cout << "| 9. Exit                                 |" << endl;
        cout << "===========================================" << endl;
    }

    void displayBoxedMessage(const string &message) {
        cout << "===========================================" << endl;
        cout << "| " << message << endl;
        cout << "===========================================" << endl;
    }

    void monitorTrafficBooth() {
        cout << "===========================================" << endl;
        cout << "          MONITORING TRAFFIC BOOTH         " << endl;
        cout << "===========================================" << endl;

        // Hardcoded values for demonstration
        int vehiclesIn = 15; // Number of vehicles entered
        int vehiclesOut = 10; // Number of vehicles exited

        cout << "| Number of vehicles entered: " << vehiclesIn << "          |" << endl;
        cout << "| Number of vehicles exited:  " << vehiclesOut << "          |" << endl;
        cout << "| Current vehicles in booth:  " << (vehiclesIn - vehiclesOut) << "          |" << endl;

        cout << "===========================================" << endl;
    }

    void searchChallanByRegNumber() {
        long regNo;
        cout << "Enter the Registration Number: ";
        cin >> regNo;

        ifstream file("TrafficChallans.csv");
        if (!file.is_open()) {
            cout << "Error: Unable to open file for reading!" << endl;
            return;
        }

        string line;
        vector<string> row;
        bool found = false;

        // Read the header line
        getline(file, line);

        // Read the data rows
        while (getline(file, line)) {
            stringstream ss(line);
            string field;
            row.clear();

            while (getline(ss, field, ',')) {
                row.push_back(field);
            }

            if (stol(row[1]) == regNo) { // Assuming column 1 is Registration Number
                cout << "Owner Name: " << row[0] << endl;
                cout << "Challan Name: " << row[2] << endl;
                cout << "Fine: " << row[3] << endl;
                cout << "Is Paid: " << row[4] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No challan found for Registration Number: " << regNo << endl;
        }

        file.close();
    }

    void searchChallanByOwnerName() {
        string ownerName;
        cin.ignore();
        cout << "Enter the Owner Name: ";
        getline(cin, ownerName);

        ifstream file("TrafficChallans.csv");
        if (!file.is_open()) {
            cout << "Error: Unable to open file for reading!" << endl;
            return;
        }

        string line;
        vector<string> row;
        bool found = false;

        // Read the header line
        getline(file, line);

        // Read the data rows
        while (getline(file, line)) {
            stringstream ss(line);
            string field;
            row.clear();

            while (getline(ss, field, ',')) {
                row.push_back(field);
            }

            if (row[0] == ownerName) { // Assuming column 0 is Owner Name
                cout << "Registration Number: " << row[1] << endl;
                cout << "Challan Name: " << row[2] << endl;
                cout << "Fine: " << row[3] << endl;
                cout << "Is Paid: " << row[4] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No challan found for Owner Name: " << ownerName << endl;
        }

        file.close();
    }

    void displayVehicleRecords() {
        ifstream file("VehicleRecords.csv");
        if (!file.is_open()) {
            cout << "Error: Unable to open file for reading!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void displayTrafficChallanRecords() {
        ifstream file("TrafficChallans.csv");
        if (!file.is_open()) {
            cout << "Error: Unable to open file for reading!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void showEmergencyInfo() {
        cout << "Emergency Contact Information:" << endl;
        cout << "Police: 100" << endl;
        cout << "Ambulance: 102" << endl;
        cout << "Fire Brigade: 101" << endl;
    }
};

int main() {
    TrafficManagementSystem tms;
    int choice;

    do {
        tms.displayMenu();

        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore();
            VehicleRecord v1;
            v1.displayVehicle();
            tms.displayBoxedMessage("Vehicle record added successfully!");
            break;
        }
        case 2: {
            long regNo;
            cout << "Enter the Registration Number to issue a challan: ";
            cin >> regNo;

            IssueTrafficChallan challan;
            challan.searchByRegistrationNumber(regNo);
            tms.displayBoxedMessage("Challan issued successfully!");
            break;
        }
        case 3:
            tms.searchChallanByRegNumber();
            tms.displayBoxedMessage("Search completed!");
            break;
        case 4:
            tms.searchChallanByOwnerName();
            tms.displayBoxedMessage("Search completed!");
            break;
        case 5:
            tms.displayVehicleRecords();
            tms.displayBoxedMessage("Vehicle records displayed!");
            break;
        case 6:
            tms.displayTrafficChallanRecords();
            tms.displayBoxedMessage("Traffic challan records displayed!");
            break;
        case 7:
            tms.monitorTrafficBooth();
            break;
        case 8:
            tms.showEmergencyInfo();
            tms.displayBoxedMessage("Emergency information displayed!");
            break;
        case 9:
            tms.displayBoxedMessage("Exiting Traffic Management System. Goodbye!");
            break;
        default:
            tms.displayBoxedMessage("Invalid choice! Please try again.");
            break;
        }
    } while (choice != 9);

    return 0;
}