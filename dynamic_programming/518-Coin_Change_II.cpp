#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned long long> ways(amount + 1);
        ways[0] = 1;

        for (auto c : coins)
        {
            for (int i = c; i <= amount; i++)
            {
                ways[i] += ways[i - c];
            }
        }

        return ways[amount];
    }
};