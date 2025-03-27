#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;

        int maxProfit = 0, actBought = prices[1];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < actBought)
                actBought = prices[i];
            else if (prices[i] > actBought)
                maxProfit = max(maxProfit, prices[i] - actBought);
        }

        return maxProfit;
    }
};