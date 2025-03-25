#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> counts;

        for (const auto &x : nums)
        {
            counts[x]++;
        }

        int ans0 = 0, ans1 = 0;
        for (const auto &[key, val] : counts)
        {
            ans0 += val / 2;
            ans1 += val % 2;
        }

        return {ans0, ans1};
    }
};