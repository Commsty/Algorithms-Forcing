#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    unordered_set<long long> x_coor;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x_coor.emplace(x);
    }

    cout << x_coor.size();

    return 0;
}