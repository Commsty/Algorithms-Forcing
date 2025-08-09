#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, string> voc1, voc2;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;

        voc1[s1] = s2;
        voc2[s2] = s1;
    }

    string s;
    cin >> s;
    
    if (voc1.count(s) != 0){
        cout << voc1[s];
        return 0;
    }

    cout << voc2[s];

    return 0;
}