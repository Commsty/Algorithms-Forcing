#include<bits/stdc++.h>
using namespace std;


int main() {
    unordered_set<long long> checker;

    string s;
    getline(cin, s);

    long long tmp;
    istringstream iss = istringstream(s);

    while (iss >> tmp) {
        checker.emplace(tmp);
    }

    int cnt = 0;
    while (cin >> tmp) {
        if (checker.count(tmp) != 0)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}