#include<bits/stdc++.h>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};


int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> coors(n, {0,0});
    for (int i = 0; i < n; i++){
        cin >> coors[i].first >> coors[i].second;
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        unordered_set<pair<int, int>, pair_hash> dontUsePoints;
        vector<long long> neighbours;

        for (int j = 0; j < n; j++){
            long long x = coors[j].first - coors[i].first, y = coors[j].second - coors[i].second;
            long long len2 = x*x + y*y;
            neighbours.push_back(len2);

            if (dontUsePoints.count(make_pair(x, y)) > 0){
                ans--;
            }
            dontUsePoints.emplace(make_pair(-x, -y));
        }

        sort(neighbours.begin(), neighbours.end());
        int right = 0;
        for (int left = 0; left < neighbours.size(); left++){
            while (right < neighbours.size() && neighbours[left] == neighbours[right]){
                right++;
            }
            ans += right - left - 1;
        }
    }

    cout << ans << "\n";


    return 0;
}