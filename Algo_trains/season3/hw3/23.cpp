#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, {n + 1, -1});
    dp[1] = {0, 0};

    for (int i = 1; i < n; i++)
    {
        if (i * 2 <= n && dp[i][0] + 1 < dp[2 * i][0])
            dp[2 * i] = {dp[i][0] + 1, i};

        if (i * 3 <= n && dp[i][0] + 1 < dp[3 * i][0])
            dp[3 * i] = {dp[i][0] + 1, i};

        if (i + 1 <= n && dp[i][0] + 1 < dp[i + 1][0])
            dp[i + 1] = {dp[i][0] + 1, i};
    }

    cout << dp[n][0] << endl;
    vector<int> ansReversed(dp[n][0] + 1);
    ansReversed[0] = n;
    int fillIdx = 1;

    while (dp[n][0] > 0)
    {
        ansReversed[fillIdx] = dp[ansReversed[fillIdx - 1]][1];
        fillIdx++;
        dp[n][0]--;
    }

    for(auto it = ansReversed.rbegin(); it != ansReversed.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}