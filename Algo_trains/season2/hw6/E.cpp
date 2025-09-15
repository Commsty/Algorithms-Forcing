#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canCover(vector<ll> &s, ll len, ll k)
{
    ll segments_used = 1;
    ll current_end = s[0] + len;
    
    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] > current_end)
        {
            segments_used++;
            current_end = s[i] + len;
            
            if (segments_used > k)
            {
                return false;
            }
        }
    }
    
    return segments_used <= k;
}

ll lbinsearch(ll k, vector<ll> &arr)
{
    sort(arr.begin(), arr.end());
    ll left = 0, right = arr.back() - arr.front();

    while (left < right)
    {
        ll mid = (left + right) / 2ll;

        if (canCover(arr, mid, k))
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
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << lbinsearch(k, arr) << "\n";

    return 0;
}