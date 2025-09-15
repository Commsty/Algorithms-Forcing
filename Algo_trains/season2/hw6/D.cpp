#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lbinsearch(ll a, ll k, ll b, ll m, ll x)
{
    ll left = 1, right = 2 * x / (a + b) + 100;
    while (left < right)
    {
        ll mid = (left + right) / 2;

        ll cnt_a = (mid - mid / k) * a;
        ll cnt_b = (mid - mid / m) * b;

        if (cnt_a + cnt_b >= x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    ll a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;

    cout << lbinsearch(a, k, b, m, x) << "\n";

    return 0;
}