#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void insertNewID(string IDarray[], int& sizeCount);

void searchID(string IDarray[], int sizeCount);

void replaceID(string IDarray[], int sizeCount);

void displayIDarray(string IDarray[], int sizeCount);


int main() {

    string IDarray[20];
    for (int i = 0; i < 20; i++) {
        IDarray[i] = "EMPTY";
    }
    int sizeCount = 0;
    cout << "----Student ID Manager----" << endl;
    bool loopCont = true;
    while (loopCont) {
        cout << endl << "----Select action----" << endl << endl;
        cout << "1. Insert ID" << endl;
        cout << "2. Search ID" << endl;
        cout << "3. Replace ID" << endl;
        cout << "4. Delete ID" << endl;
        cout << "5. Display IDs" << endl;
        cout << "6. Copy to Backup" << endl;
        cout << "7. Compare with Backup" << endl;
        cout << "8. Exit" << endl;
        cout << endl << "Enter action selection: ";
        int action;
        cin >> action;
        switch (action) {
            case 1: {
                insertNewID(IDarray, sizeCount);
                break;
            }
            case 2: {
                searchID(IDarray, sizeCount);
                break;
            }
            case 3: {
                replaceID(IDarray, sizeCount);
                break;
            }
            case 4: {

                break;
            }
            case 5: {
                displayIDarray(IDarray, sizeCount);
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                cout << endl << "Closing Program";
                loopCont = false;
                break;
            }
            default: {
                cout << "Invalid action" << endl;
                break;
            }
        }
    }
    return 0;
}

void insertNewID(string IDarray[], int& sizeCount) {
    if (sizeCount == 20) {
        cout << "Maximum number of IDs reached" << endl << "Coming soon - Upgrade to maximum of 40 IDs for only $3.99/month" << endl;
        return;
    }
    cout << "Enter new Student ID in the ( StudentID StudentName ) format" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputID;
    getline(cin, inputID);
    IDarray[sizeCount] = inputID;
    sizeCount++;
}

void searchID(string IDarray[], int sizeCount) {
    cout << "Search by student ID or student Name" << endl << "Input student search:";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string searchTarget;
    getline(cin, searchTarget);
    int index;
    for (int i = 0; i < sizeCount; i++) {
        if (IDarray[i].find(searchTarget) > 0) {
            break;
        }
        index++;
    }
    if (index == sizeCount) {
        cout << "Student ID not found under this query" << endl;
        return;
    }
    cout << IDarray[index] << " found at index[" << index << "]" << endl;
}

void replaceID(string IDarray[], int sizeCount) {
    cout << "Choose which student ID index to replace" << endl << "Student ID Index[";
    int index;
    cin >> index;
    if (index < 0 || index >= sizeCount) {
        cout << "Student ID not found at this index value" << endl;
        return;
    }
    cout << endl << "Student ID Index[" << index << "] = " << IDarray[index] << endl;
    cout << "Enter new student ID in the ( StudentID StudentName ) format" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputID;
    getline(cin, inputID);
    IDarray[index] = inputID;
    cout << "Student ID replaced" << endl;
}

void displayIDarray(string IDarray[], int sizeCount) {
    if (sizeCount == 0) {
        cout << "No stored IDs found" << endl;
        return;
    }
    for (int i = 0; i < sizeCount; i++) {
        cout << "Student ID Index[" << i << "] = " << IDarray[i] << endl;
    }
}


