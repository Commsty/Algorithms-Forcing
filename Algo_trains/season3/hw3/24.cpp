#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;

        dp[i] = min(dp[i], dp[i - 1] + ai);

        if (i + 1 <= n)
        {
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + bi);
        }
        if (i + 2 <= n)
        {
            dp[i + 2] = min(dp[i + 2], dp[i - 1] + ci);
        }
    }

    cout << dp[n] << endl;

    return 0;
}