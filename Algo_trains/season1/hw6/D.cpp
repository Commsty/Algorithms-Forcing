#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll rbinsearch(ll n, ll a, ll b, ll w, ll h){
    ll left = 0, right = max(w, h);

    while (left < right){

        ll mid = (left + right + 1) / 2;

        ll w_cnt1 = w / (a + 2*mid), w_cnt2 = w / (b + 2*mid);
        ll h_cnt1 = h / (b + 2*mid), h_cnt2 = h / (a + 2*mid);

        if (w_cnt1 * h_cnt1 >= n || w_cnt2 * h_cnt2 >= n)
            left = mid;

        else
            right = mid - 1;
    }

    return left;
}


int main(){
    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    cout << rbinsearch(n, a, b, w, h) << "\n";

    return 0;
}