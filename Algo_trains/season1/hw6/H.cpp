#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rbinsearch(ll n, ll k, vector<ll>& l){
    ll left = 0, right = *max_element(l.begin(), l.end());
    while (left < right){
        ll mid = (left + right + 1) / 2;
        
        int cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += (l[i] / mid);
        }

        if (cnt >= k){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> l(n, 0);
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }

    cout << rbinsearch(n, k, l) << "\n";

    return 0;
}