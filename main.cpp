#include <iostream>
#include <string>
using namespace std;

void insertNewID(string IDarray[], int& sizeCount);

void displayIDarray(string IDarray[], int sizeCount);


int main() {

    string IDarray[20];
    for (int i = 0; i < 20; i++) {
        IDarray[i] = "EMPTY";
    }
    int sizeCount = 0;
    insertNewID(IDarray, sizeCount);
    insertNewID(IDarray, sizeCount);

    displayIDarray(IDarray, sizeCount);

    return 0;
}

void insertNewID(string IDarray[], int& sizeCount) {
    if (sizeCount == 19) {
        cout << "Maximum number of IDs reached" << endl << "Coming soon - Upgrade to maximum of 40 IDs for only $3.99/month" << endl;
        return;
    }
    cout << "Enter new user ID in the ( UserID UserName ) format" << endl;
    string inputID;
    getline(cin, inputID);
    IDarray[sizeCount] = inputID;
    sizeCount++;
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
