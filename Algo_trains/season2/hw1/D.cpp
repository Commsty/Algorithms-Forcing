#include <bits/stdc++.h>
using namespace std;


int main() {

    long long n;
    cin >> n;

    vector<long long> coordinates(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> coordinates[i];
    }

    long long s = 0;
    for (long long i = 0; i < n; i++) {
        s += coordinates[i] - coordinates[0];
    }

    long long sBest = s, pointBest = coordinates[0];

    for (long long i = 1; i < n; i++) {
        long long distanceGone = coordinates[i] - coordinates[i-1];

        s -= (n - i + 1) * distanceGone;
        s += i * distanceGone;

        if (s < sBest) {
            sBest = s;
            pointBest = coordinates[i];
        }
    }
    
    cout << pointBest << "\n";

    return 0;
}