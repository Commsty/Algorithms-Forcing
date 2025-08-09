#include<bits/stdc++.h>
using namespace std;


int main(){
    int g, S;
    cin >> g >> S;
    
    string w, s;
    cin >> w >> s;

    long long cnt = 0;
    int equals = 0;

    unordered_map<char, int> counter, counter_seq;
    for (char c: w)
        counter[c]++;

    for (int i = 0; i < g; i++){
        counter_seq[s[i]]++;
    }

    for (const auto& [sym, cnt]: counter_seq){
        if (cnt == counter[sym])
            equals++;
    }

    if (equals == counter.size())
        cnt++;

    for (int i = g; i < S; i++){

        if (counter_seq.count(s[i-g]) == 0)
            counter_seq[s[i-g]] = 0;

        if (counter.count(s[i-g]) > 0 && counter_seq[s[i-g]] == counter[s[i-g]])
            equals--;
        
        counter_seq[s[i-g]]--;

        if (counter.count(s[i-g]) > 0 && counter_seq[s[i-g]] == counter[s[i-g]])
            equals++;

        //  

        if (counter.count(s[i]) > 0 && counter_seq[s[i]] == counter[s[i]])
            equals--;
        
        counter_seq[s[i]]++;

        if (counter.count(s[i]) > 0 && counter_seq[s[i]] == counter[s[i]])
            equals++;

        if (equals == counter.size())
            cnt++;
        
    }

    cout << cnt;

    return 0;
}