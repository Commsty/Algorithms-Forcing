#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> cnt;

    int maxi = 0;
    string tmp;
    while (cin >> tmp){
        cnt[tmp]++;
        maxi=max(maxi, cnt[tmp]);
    }

    vector<string> freq;
    for (const auto& [key, val]: cnt){
        if (val == maxi){
            freq.push_back(key);
        }
    }
    
    cout << *min_element(freq.begin(), freq.end());


    return 0;
}