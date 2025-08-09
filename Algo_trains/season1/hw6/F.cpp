#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lbinsearch(ll n, ll x, ll y){

    ll left = 0, right = min(x, y) * n;

    while (left < right){

        ll mid = (left + right) / 2;
        
        if (mid / x + mid / y >= n)
            right = mid;

        else
            left = mid + 1;
    }
    return left;
}


int main(){
    ll n, x, y;
    cin >> n >> x >> y;

    if (n == 1)
        cout << min(x, y) << "\n";

    else{
        ll totalTime = min(x, y);
        n--;
        
        totalTime += lbinsearch(n, x, y);
        cout << totalTime << "\n";
    }
    return 0;
}