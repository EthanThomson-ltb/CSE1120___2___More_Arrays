#include <iostream>
#include <string>
using namespace std;

void insertNewID(string IDarray[], int& sizeCount);

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
            }
            case 2: {

            }
            case 3: {
                replaceID(IDarray, sizeCount);
            }
            case 4: {

            }
            case 5: {
                displayIDarray(IDarray, sizeCount);
            }
            case 6: {

            }
            case 7: {

            }
            case 8: {
                loopCont = false;
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
    cout << "Enter new user ID in the ( UserID UserName ) format" << endl;
    string inputID;
    getline(cin, inputID);
    IDarray[sizeCount] = inputID;
    sizeCount++;
}

void replaceID(string IDarray[], int sizeCount) {
    cout << "Choose which user ID index to replace" << endl << "User ID Index[";
    int index;
    cin >> index;
    if (index < 0 || index >= sizeCount) {
        cout << "User ID not found at this index value" << endl;
        return;
    }
    cout << endl << "User ID Index[" << index << "] = " << IDarray[index] << endl;
    cout << "Enter new user ID in the ( UserID UserName ) format" << endl;
    string inputID;
    getline(cin, inputID);
    IDarray[index] = inputID;
    cout << "User ID replaced" << endl;
}

void displayIDarray(string IDarray[], int sizeCount) {
    if (sizeCount == 0) {
        cout << "No stored IDs found" << endl;
        return;
    }
    for (int i = 0; i < sizeCount; i++) {
        cout << "User ID Index[" << i << "] = " << IDarray[i] << endl;
    }
}


