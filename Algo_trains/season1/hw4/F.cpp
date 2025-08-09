#include<bits/stdc++.h>
using namespace std;


int main(){
    map<string, map<string, long long>> table;
    vector<string> tmp = {};

    string s, word;
    while (getline(cin, s, '\n')){
        istringstream input(s);
        while (input >> word){
            tmp.push_back(word);
        }
        auto name = tmp[0], stuff = tmp [1];
        int amount = atoi(tmp[2].c_str());
        tmp.clear();

        table[name][stuff] += amount;
    }

    for (const auto& [consumer, buyings]: table){
        cout << consumer << ":" << "\n";
        for (const auto& [stuff, amount]: buyings){
            cout << stuff << " " << amount << "\n";
        }
    }

    return 0;
}