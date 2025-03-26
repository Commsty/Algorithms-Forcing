#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp{0,1,2,3};

    int climbStairs(int n)
    {
        if (n<=3)
            return dp[n];

        for (int i=4;i<=n;i++){
            dp.push_back(dp[i-1]+dp[i-2]);
        }

        return dp[n];
    }
};