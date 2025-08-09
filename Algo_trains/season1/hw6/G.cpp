#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rbinsearch(ll n, ll m, ll t){
    ll left = 0, right = max(n, m);
    while (left < right){
        ll mid = (left + right + 1) / 2;

        if (n * mid * 2 + (m - mid * 2) * mid * 2 <= t && m - mid * 2 > 0){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}


int main(){
    ll n, m, t;
    cin >> n >> m >> t;

    cout << rbinsearch(n, m, t) << "\n";

    return 0;
}