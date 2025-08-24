#include<bits/stdc++.h>
using namespace std;

int main() {

    int max = INT_MIN, maxCount = 1;
    int numNow;
    
    while (cin >> numNow && numNow != 0) {
        if (numNow > max) {
            max = numNow;
            maxCount = 1;
        }

        else if (numNow == max) {
            maxCount++;
        }
    }


    cout << maxCount << "\n";

    return 0;
}