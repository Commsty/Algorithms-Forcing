#include<bits/stdc++.h>
using namespace std;


int main(){
    int k;
    string s;
    cin >> k >> s;

    int ans = 0;
    int prevEquals = 0;

    for (int i = k; i < s.size(); i++){
        if (s[i] == s[i-k]){
            prevEquals++;
            ans += prevEquals;
        }
        else{
            prevEquals = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}