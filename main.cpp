#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void insertNewID(string IDarray[], int& sizeCount);

int searchIDclient(string IDarray[], int sizeCount);

int searchIDloop(string IDarray[], int sizeCount);

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
                return 0;
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

int searchIDclient(string IDarray[], int sizeCount) {
    cout << "To search for a student entry by name, input 1" << endl << "To search for a student ID by index, input 2";
    int index;
    int nameVsIndex;
    for (;;) {
        cin >> nameVsIndex;
        switch (nameVsIndex) {
            case 1: {
                cout << "Searching by student ID or student Name" << endl << "Input student search:";
                index = searchIDloop(IDarray, sizeCount);
                if (index == -1) {
                    cout << "Student ID not found under this query, please try again." << endl;
                } else {
                    cout << IDarray[index] << " found at index[" << index << "]" << endl;
                    return index;
                }
            }
            case 2: {
                cout << "Searching student ID by index" << endl << "Student ID Index[";
                cin >> index;
                if (index < 0 || index >= sizeCount) {
                    cout << "Student ID not found at this index value, please try again." << endl;
                } else {
                    cout << endl << "Student ID Index[" << index << "] = " << IDarray[index] << endl;
                    return index;
                }
            }
            default: {
                cout << "Invalid entry, please try again." << endl;
                break;
            }
        }
    }
}

int searchIDloop(string IDarray[], int sizeCount) {

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string searchTarget;
    getline(cin, searchTarget);
    for (int i = 0; i < sizeCount; i++) {
        if (IDarray[i].find(searchTarget) != -1) {
            return i;
        }
    }
    return -1;
}

void replaceID(string IDarray[], int sizeCount) {

    cout << "Enter new student ID in the ( StudentID StudentName ) format" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputID;
    getline(cin, inputID);
    IDarray[sizeCount] = inputID;
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


