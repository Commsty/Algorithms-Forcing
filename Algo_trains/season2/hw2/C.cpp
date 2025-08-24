#include<bits/stdc++.h>
using namespace std;


int main() {

    string s;
    cin >> s;


    int left = 0, right = s.size() - 1;
    int cntTugrics = 0;

    while (left < right) {
        if (s[left] != s[right])
            cntTugrics++;
        
        left++, right--;
    }

    cout << cntTugrics << "\n";

    return 0;
}