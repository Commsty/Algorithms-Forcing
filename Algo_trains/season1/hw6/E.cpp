#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lbinsearch(ll a, ll b, ll c){
    ll left = 0, right = a + b + c;

    while (left < right){

        ll mid = (left + right) / 2;

        if (4*a + 6*b + 8*c + 10*mid >= 7*(a + b + c + mid))
            right = mid;

        else
            left = mid + 1;
    }

    return left;
}

int main(){
    ll a, b ,c;
    cin >> a >> b >> c;

    cout << lbinsearch( a, b, c) << "\n";

    return 0;
}