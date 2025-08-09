#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt = 0;
    unordered_map<int, unordered_set<int>> infos;

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        if (a < 0 || b < 0)
            continue;

        if (a + b + 1 != n)
            continue;

        if (infos[a].count(b) != 0)
            continue;

        cnt++;
        infos[a].emplace(b);
    }

    cout << cnt;


    return 0;
}