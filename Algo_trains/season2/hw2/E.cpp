#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int sum = 0, maxi = -1;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        sum += tmp;
        maxi = max(maxi, tmp);
    }

    cout << sum - maxi << "\n";

    return 0;
}