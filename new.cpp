#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Birthday {
    string name;
    int day;
    int month;
};

vector<Birthday> birthdays;

void createBirthday() {
    Birthday b;
    cout << "Enter name: ";
    getline(cin, b.name);
    cout << "Enter day (1-31): ";
    cin >> b.day;
    cout << "Enter month (1-12): ";
    cin >> b.month;
    cin.ignore();
    birthdays.push_back(b);
}

void displayBirthdays() {
    if (birthdays.empty()) {
        cout << "No birthdays added yet." << endl;
        return;
    }
    cout << "Birthdays: " << endl;
    for (const auto& b : birthdays) {
        cout << b.name << ": " << b.day << "/" << b.month << endl;
    }
}

void editBirthday() {
    if (birthdays.empty()) {
        cout << "No birthdays added yet." << endl;
        return;
    }
    string name;
    cout << "Enter name to edit: ";
    getline(cin, name);
    auto it = find_if(birthdays.begin(), birthdays.end(), [&](const Birthday& b) { return b.name == name; });
    if (it == birthdays.end()) {
        cout << "Birthday not found." << endl;
        return;
    }
    Birthday& b = *it;
    cout << "Enter new day (1-31): ";
    cin >> b.day;
    cout << "Enter new month (1-12): ";
    cin >> b.month;
    cin.ignore();
}

void searchBirthday() {
    if (birthdays.empty()) {
        cout << "No birthdays added yet." << endl;
        return;
    }
    string name;
    cout << "Enter name to search: ";
    getline(cin, name);
    auto it = find_if(birthdays.begin(), birthdays.end(), [&](const Birthday& b) { return b.name == name; });
    if (it == birthdays.end()) {
        cout << "Birthday not found." << endl;
        return;
    }
    const Birthday& b = *it;
    cout << b.name << ": " << b.day << "/" << b.month << endl;
}

void listMonthlyBirthdays() {
    if (birthdays.empty()) {
        cout << "No birthdays added yet." << endl;
        return;
    }
    int month;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Birthdays in month " << month << ":" << endl;
    for (const auto& b : birthdays) {
        if (b.month == month) {
            cout << b.name << ": " << b.day << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << endl << "Menu:" << endl;
        cout << "1. Create birthday" << endl;
        cout << "2. Display birthdays" << endl;
        cout << "3. Edit birthday" << endl;
        cout << "4. Search birthday" << endl;
        cout << "5. List monthly birthdays" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                createBirthday();
                break;
            case 2:
                displayBirthdays();
                break;
            case 3:
                editBirthday();
                break;
            case 4:
                searchBirthday();
                break;
            
            case 5:
                listMonthlyBirthdays();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
