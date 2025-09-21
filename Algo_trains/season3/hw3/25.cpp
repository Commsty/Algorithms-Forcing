#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<vector<int>> dp(n + 1, {INT_MAX, INT_MAX});
    dp[0] = {0, 0}, dp[1] = {0, 0}, dp[2][1] = arr[1] - arr[0];

    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + arr[i-1] - arr[i-2];
    }

    cout << dp[n][1] << endl;

    return 0;
}