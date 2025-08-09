#include<bits/stdc++.h>
using namespace std;

char makeLess(char c){
    if (islower(c))
        return c;

    else if (isupper(c))
        return c - 'A' + 'a';

    return -1;
}

string lowCopy(const string& s){
    string ans;

    for (const char c: s){
        ans.push_back(makeLess(c));
    }

    return ans;
}


int main(){

    int n;
    cin >> n;

    unordered_map<string, unordered_set<int>> voc;
    string tmp;


    for (int i = 0; i < n; i++){
        cin >> tmp;

        auto& marked = voc[lowCopy(tmp)];

        for (int j = 0; j < tmp.size(); j++){
            if (tmp[j] <= 'Z' && tmp[j] >= 'A'){
                marked.emplace(j);
            }
        }
    }

    int mistakes = 0;

    while (cin >> tmp){
        vector<int> pos = {};

        for (int j = 0; j < tmp.size(); j++){

            if (tmp[j] <= 'Z' && tmp[j] >= 'A'){
                pos.push_back(j);
            }
        }

        if (pos.size() != 1){
            mistakes++;
            continue;
        }

        if (voc.count(lowCopy(tmp)) == 0){
            continue;
        }

        else{
            if (voc[lowCopy(tmp)].count(pos[0]) == 1){
                continue;
            }
            else{
                mistakes++;
                continue;
            }
        }
    }

    cout << mistakes << "\n";

    return 0;
}