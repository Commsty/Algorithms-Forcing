#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        vector<vector<pair<int, int>>> endOfRides(n + 1);
        for (auto r : rides)
            endOfRides[r[1]].push_back({r[0], r[1] - r[0] + r[2]});

        vector<long long> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            
            for (auto p : endOfRides[i])
                dp[i] = max(dp[i], dp[p.first] + p.second);
        }

        return dp[n];
    }
};