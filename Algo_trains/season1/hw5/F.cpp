#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n;

    vector<int> cabs(n, 0);
    for (int i = 0; i < n; i++){
        cin >> cabs[i];
    }

    cin >> m;
    vector<pair<int, int>> conds(m,{0,0});
    for (int i = 0; i < m; i++){
        cin >> conds[i].first >> conds[i].second;
    }

    vector<int> optimalPrice(1001, 1001);
    for (int i = 1; i <= 1000; i++){

        for (int j = 0; j < m; j++){

            if (conds[j].first >= i && conds[j].second < optimalPrice[i]){
                optimalPrice[i] = conds[j].second;
            }

        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += optimalPrice[cabs[i]];
    }

    cout << ans << "\n";

    return 0;
}