#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<bool> canAchieve(amount + 1, false);
        canAchieve[0] = true;

        vector<int> minSteps(amount + 1, INT_MAX);
        minSteps[0] = 0;

        for (long long i = 0; i < amount; i++)
        {
            if (canAchieve[i])
            {
                for (auto c : coins)
                {
                    if (i + c <= (long long)amount)
                    {
                        canAchieve[i + c] = true;
                        minSteps[i + c] = min(minSteps[i + c], minSteps[i] + 1);
                    }
                }
            }
        }

        return (canAchieve[amount]) ? minSteps[amount] : -1;
    }
};