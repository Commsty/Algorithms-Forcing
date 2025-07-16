#include<bits/stdc++.h>
using namespace std;


int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    unordered_map<string, int> A, B;

    for (int i = 0; i < a.size() - 1; i++){
        A[a.substr(i, 2)]++;
    }
    for (int i = 0; i < b.size() - 1; i++){
        B[b.substr(i, 2)]++;
    }

    int res = 0;
    for (const auto& [key, val]: A){
        if (B.count(key) != 0)
            res += val;
    }

    cout << res;
    return 0;
}