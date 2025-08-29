#include<bits/stdc++.h>
using namespace std;


int main() {

    unordered_set<long long> checker;

    long long tmp;
    while (cin >> tmp) {
        if (checker.count(tmp) == 0) {
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
        checker.emplace(tmp);
    }

    return 0;
}