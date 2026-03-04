#include <iostream>
using namespace std;

void displayIDarray(string IDarray[], int sizeCount);


int main() {

    string IDarray[20];
    int sizeCount = 0;
    for (int i = 0; i < 20; i++) {
        IDarray[i] = "EMPTY";
    }
    cin >> sizeCount;
    displayIDarray(IDarray, sizeCount);



    return 0;
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
