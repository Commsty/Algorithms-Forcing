#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> dp(n + 1, 0);
    vector<int> prefixes(n + 1, 0);
    prefixes[1] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = prefixes[i-1] - ((i-k-1 > 0) ? prefixes[i-k-1] : 0);
        prefixes[i] = prefixes[i-1] + dp[i];
    }

    cout << dp[n] << endl;

    return 0;
}