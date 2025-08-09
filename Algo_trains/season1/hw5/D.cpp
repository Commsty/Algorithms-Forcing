
#include<bits/stdc++.h>
using namespace std;



int main(){

    int n, r;
    cin >> n >> r;
    vector<int> dist(n,0);

    for (int i = 0; i < n; i++){
        cin >> dist[i];
    }

    int left = 0, right = 1;
    long long res = 0;

    while (right < dist.size()){

        if (dist[right] - dist[left] > r){
            res += (dist.size() - right);
            left++;
        }
        else{
            right++;
        }
    }

    cout << res << "\n";


    return 0;
}