#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string> storage;
    string tmp;

    while (cin >> tmp)
        storage.emplace(tmp);

    cout << storage.size();


    return 0;
}