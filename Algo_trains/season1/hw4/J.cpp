#include<bits/stdc++.h>
using namespace std;

bool isnumber(string s){

    for (const char& c: s){
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}

char makeLess(char c){
    if (islower(c))
        return c;

    else if (isupper(c))
        return c - 'A' + 'a';

    return c;
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
    string C, D;
    unordered_set<string> keywords;

    cin >> n >> C >> D;

    bool c = true, d = true;
    if (strcmp(C.c_str(), "no") == 0)
        c = false;
    if (strcmp(D.c_str(), "no") == 0)
        d = false;


    string tmp;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (!c){
            tmp = lowCopy(tmp);
        }
        keywords.emplace(tmp);
    }

    string code, line;
    while (getline(cin, line)){
        code += line + "\n"; 
    }

    for (char& sym: code){
        if (sym != '_' && !isalnum(sym)){
            sym = ' ';
        }
    }

    unordered_map<string, pair<long long, long long>> info;

    string res;
    long long maxCount = 0, minPos = LONG_LONG_MAX, pos = 0;

    istringstream S(code);
    while (S >> tmp){
        pos++;

        if (!c){
            tmp = lowCopy(tmp);
        }

        if (keywords.count(tmp) != 0)
            continue;

        else{
            if (isnumber(tmp))
                continue;

            if (isdigit(tmp[0]) && !d)
                continue;

            if (info.count(tmp) == 0){
                info[tmp] = make_pair(0, pos);
            }
            info[tmp].first++;

            if (info[tmp].first > maxCount){
                maxCount = info[tmp].first;
                res = tmp;
                minPos = info[tmp].second;
            }

            if (info[tmp].first == maxCount && info[tmp].second < minPos){
                res = tmp;
                minPos = info[tmp].second;
            }
        }
    }

    cout << res << "\n";

    return 0;
}