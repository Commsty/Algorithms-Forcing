#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s1[i];
    }

    int m;
    cin >> m;
    vector<int> s2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s2[i];
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (s1[0] == s2[0])
    {
        dp[0][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (s1[i] == s2[0])
        {
            dp[0][i] = 1;
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (s1[0] == s2[i])
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (s1[j] == s2[i])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> lcs;
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (s2[i] == s1[j])
        {
            lcs.push_back(s1[j]);
            i--;
            j--;
        }
        else if (i > 0 && j > 0 && dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else if (i > 0 && j > 0 && dp[i - 1][j] < dp[i][j - 1])
        {
            j--;
        }
        else if (i > 0)
        {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    for (int x : lcs)
    {
        cout << x << " ";
    }

    return 0;
}