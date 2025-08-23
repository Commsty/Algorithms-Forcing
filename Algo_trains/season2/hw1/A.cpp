#include<bits/stdc++.h>
using namespace std;


int main() {
    int progCode, interactCode, checkerCode;
    cin >> progCode >> interactCode >> checkerCode;

    if (interactCode == 0) {
        if (progCode != 0)
            cout << 3 << "\n";
        else
            cout << checkerCode << "\n";
        return 0;
    }

    if (interactCode == 1) {
        cout << checkerCode << "\n";
        return 0;
    }

    if (interactCode == 4) {
        if (progCode != 0)
            cout << 3 << "\n";
        else
            cout << 4 << "\n";
        return 0;
    }

    if (interactCode == 6){
        cout << 0 << "\n";
        return 0;
    }

    if (interactCode == 7){
        cout << 1 << "\n";
        return 0;
    }

    cout << interactCode << "\n";

    return 0;
}