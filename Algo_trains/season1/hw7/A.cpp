#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int teachersNow = 0;
    

    vector<pair<int, int>> positions(2 * m, {0, 0});
    for (int i = 0; i < 2 * m; i+=2) {
        int left, right;
        cin >> left >> right;

        positions[i] = make_pair(left, 1);
        positions[i+1] = make_pair(right,-1);
    }

    sort(positions.begin(), positions.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    int badBoys = 0;
    if (positions[0].first > 0) {
        badBoys = positions[0].first;
    }

    for (int i = 0; i < 2 * m; i++){

        if (positions[i].second == -1){
            teachersNow--;
        }
        else{
            teachersNow++;
        }

        if (teachersNow == 0) {
            if (i != 2 * m - 1) {
                badBoys += (positions[i+1].first - positions[i].first - 1);
            }
            else {
                badBoys += (n - 1 - positions[i].first);
            }
        }

    }

    cout << badBoys << "\n";

    return 0;
}