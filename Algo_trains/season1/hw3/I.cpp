#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    unordered_set<string> all_langs;
    unordered_map<string, int> common;

    int cnt = 0;
    for (int i = 0 ; i < n; i++){
        int m;
        cin >> m;

        for (int j = 0; j < m; j++){
            string tmp;
            cin >> tmp;

            common[tmp]++;
            all_langs.emplace(tmp);
        }
    }

    for (const auto& [key, val]: common){
        if (val >= n)
            cnt++;
    }

    cout << cnt << "\n";
    for (const auto& [key, val]: common){
        if (val >= n)
            cout << key << "\n";
    }

    cout << all_langs.size() << "\n";
    for (const string& s: all_langs){
        cout << s << "\n";
    }


    return 0;
}