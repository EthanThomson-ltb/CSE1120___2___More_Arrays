#include <iostream>
#include <string>
#include <limits>
using namespace std;

void insertNewID(string IDarray[], int index);

int searchIDclient(string IDarray[], int sizeCount);

int searchIDloop(string IDarray[], int sizeCount);

void replaceID(string IDarray[], int sizeCount);

void deleteID(string IDarray[], int& sizeCount);

void shift(string IDarray[], int sizeCount, int index);

void displayIDarray(string IDarray[], int sizeCount);

void copyBackup(string IDarray[], string IDarrayBackup[]);

void backupDisplay(string IDarray[], string IDarrayBackup[]);

bool backupCompare(string IDarray[], string IDarrayBackup[]);


int main() {

    string IDarray[20];
    string IDarrayBackup[20];
    for (int i = 0; i <= 19; i++) {
        IDarray[i] = "EMPTY";
        IDarrayBackup[i] = "EMPTY";
    }
    int sizeCount = 0;
    cout << "----Student ID Manager----" << endl;
    bool loopCont = true;
    int action;
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
        cin >> action;
        switch (action) {
            case 1: {
                if (sizeCount == 20) {
                    cout << "Maximum number of IDs reached" << endl << "Coming soon - Upgrade to maximum of 40 IDs for only $3.99/month" << endl;
                } else {
                    insertNewID(IDarray, sizeCount);
                    sizeCount++;
                }
                break;
            }
            case 2: {
                searchIDclient(IDarray, sizeCount);
                break;
            }
            case 3: {
                replaceID(IDarray, sizeCount);
                break;
            }
            case 4: {
                deleteID(IDarray, sizeCount);
                break;
            }
            case 5: {
                displayIDarray(IDarray, sizeCount);
                break;
            }
            case 6: {
                copyBackup(IDarray, IDarrayBackup);
                break;
            }
            case 7: {
                backupDisplay(IDarray, IDarrayBackup);
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

        //Debug tool
        /*
        for (int i = 0; i < 20; i++) {
            cout << "ID" << i << ": " << IDarray[i] << endl;
        }
        */

    }
    return 0;
}

void insertNewID(string IDarray[], int index) {
    cout << "Enter new Student ID in the ( StudentID StudentName ) format" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputID;
    getline(cin, inputID);
    IDarray[index] = inputID;

}

int searchIDclient(string IDarray[], int sizeCount) {
    int index;
    int nameVsIndex;
    for (;;) {
        cout << "To search for a student entry by ID or name, input 1" << endl << "To search for a student entry by index, input 2" << endl << "To exit this action, input 0" << endl;
        cin >> nameVsIndex;
        switch (nameVsIndex) {
            case 0: {
                cout << "Exiting..." << endl;
                return -1;
            }
            case 1: {
                cout << "Searching by student ID or student Name" << endl << "Input student search:";
                index = searchIDloop(IDarray, sizeCount);
                if (index == -1) {
                    cout << "Student ID not found under this query, please try again." << endl;
                } else {
                    cout << IDarray[index] << " found at index[" << index << "]" << endl;
                    return index;
                }
                break;
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
                break;
            }
            default: {
                cout << "Invalid input, please try again." << endl;
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
    if (sizeCount == 0) {
        cout << "No stored IDs found" << endl;
        return;
    }
    cout << "Choose student ID to be replaced" << endl;
    int index = searchIDclient(IDarray, sizeCount);
    if (index == -1) {
        return;
    }
    cout << "Are your sure you want to replace index " << index << "?" << endl << "Currently stored information will be lost" << endl;
    int yvsn;
    for (;;) {
        cout << "To cancel this action, input 1" << endl << "To continue, input 2" << endl;
        cin >> yvsn;
        switch (yvsn) {
            case 1: {
                cout << "Exiting..." << endl;
                return;
            }
            case 2: {
                insertNewID(IDarray, index);
                cout << "Student ID replaced" << endl;
                return;
            }
            default: {
                cout << "Invalid input, please try again." << endl;
                break;
            }
        }
    }
}

//The majority of the code is identical to that of the replaceID function, however most of the console outputs are different so consolidating would be difficult.
void deleteID(string IDarray[], int& sizeCount) {
    if (sizeCount == 0) {
        cout << "No stored IDs found" << endl;
        return;
    }
    cout << "Choose student ID to be deleted" << endl;
    int index = searchIDclient(IDarray, sizeCount);
    if (index == -1) {
        return;
    }
    cout << "Are your sure you want to delete index " << index << "?" << endl << "Currently stored information will be lost" << endl;
    int yvsn;
    for (;;) {
        cout << "To cancel this action, input 1" << endl << "To continue, input 2" << endl;
        cin >> yvsn;
        switch (yvsn) {
            case 1: {
                cout << "Exiting..." << endl;
                return;
            }
            case 2: {
                shift(IDarray, sizeCount, index);
                sizeCount--;
                cout << "Student ID deleted" << endl;
                return;
            }
            default: {
                cout << "Invalid input, please try again." << endl;
                break;
            }
        }
    }
}

void shift(string IDarray[], int sizeCount, int index) {
    for (int i = index; i <= sizeCount; i++) {
        IDarray[i] = IDarray[i + 1];
    }
    if (sizeCount == 20) {
        IDarray[19] = "EMPTY";
    }
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

void copyBackup(string IDarray[], string IDarrayBackup[]) {
    cout << "Creating backup..." << endl;
    for (int i = 0 ; i < 20; i++) {
        IDarrayBackup[i] = IDarray[i];
    }
    cout << "Backup created" << endl;
}

void backupDisplay(string IDarray[], string IDarrayBackup[]) {
    if (backupCompare(IDarray, IDarrayBackup)) {
        cout << "Arrays are identical" << endl;
    } else {
        cout << "Arrays are different" << endl;
    }
    cout << "Display backup?" << endl;
    int yvsn;
    for (;;) {
        cout << "To continue input, input 1" << endl << "To exit this action, input 2" << endl;
        cin >> yvsn;
        switch (yvsn) {
            case 1: {
                for (int i = 0; i < 20; i++) {
                    cout << "Index[" << i << "] = " << IDarrayBackup[i] << endl;
                }
                return;
            }
            case 2: {
                cout << "Exiting..." << endl;
                return;
            }
            default: {
                cout << "Invalid input, please try again." << endl;
                break;
            }
        }
    }
}

bool backupCompare(string IDarray[], string IDarrayBackup[]) {
    for (int i = 0 ; i < 20; i++) {
        if (IDarray[i] != IDarrayBackup[i]) {
            return false;
        }
    }
    return true;
}

