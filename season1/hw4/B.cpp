#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<string, int> counter;

    string tmp;
    while (cin >> tmp){
        if (counter.count(tmp) == 0){
            cout << 0 << " ";
            counter[tmp] = 1;
        }
        else {
            cout << counter[tmp] << " ";
            counter[tmp]++;
        }
    }
    return 0;
}