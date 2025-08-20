#include<bits/stdc++.h>
using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> parts(2 * n + m, {0,0});
    vector<int> points(m, 0);

    for (int i = 0; i < 2 * n; i += 2) {
        int left, right;
        cin >> left >> right;

        parts[i] = make_pair(min(left, right), 1);
        parts[i+1] = make_pair(max(left, right), -1);
    }
    for (int i = 2 * n; i < 2 * n + m; i++) {
        int checkpoint;
        cin >> checkpoint;
        
        parts[i] = make_pair(checkpoint, 0);
        points[i-2*n] = checkpoint;
    }


    sort(parts.begin(), parts.end(), [](pair<int,int>& a, pair<int,int>& b){
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    int nowParts = 0;
    unordered_map<int, int> ans;

    for (int i = 0; i < 2 * n + m; i++) {

        if (parts[i].second == 1){
            nowParts++;
            continue;
        }

        if (parts[i].second == 0){
            ans[parts[i].first] = nowParts;
            continue;
        }

        if (parts[i].second == -1){
            nowParts--;
        }
    }


    for (const auto& p: points) {
        cout << ans[p] << " ";
    }

    return 0;
}