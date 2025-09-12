#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n;
    cin >> n;

    vector<ll> prefixes(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;

        prefixes[i] = prefixes[i-1] + tmp;
    }

    ll minSum = prefixes[0];
    ll maxSum = prefixes[1];

    for (int i = 1; i <= n; i++) {
        maxSum = max(maxSum, prefixes[i] - minSum);

        minSum = min(minSum, prefixes[i]);
    }

    cout << maxSum;

    return 0;
}