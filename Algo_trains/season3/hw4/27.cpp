#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = table[0][0];

    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i - 1] + table[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + table[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + table[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    int cnt = n + m - 2;
    vector<string> ansReversed(n + m - 2);
    pair<int, int> now(n-1, m-1);

    while (cnt > 0) {
        cnt--;

        if (now.first == 0) {
            ansReversed.push_back("R");
            now.second--;
            continue;
        }
        if (now.second == 0) {
            ansReversed.push_back("D");
            now.first--;
            continue;
        }

        int upper = dp[now.first-1][now.second];
        int left = dp[now.first][now.second-1];

        if (upper >= left){
            ansReversed.push_back("D");
            now.first--;
        }
        else {
            ansReversed.push_back("R");
            now.second--;
        }
    }

    for (auto it = ansReversed.rbegin(); it != ansReversed.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}