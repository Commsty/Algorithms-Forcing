#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int x = 1; x <= nums.size(); x++)
        {
            count[x]++;
        }

        int doubled = 0;
        int lost = 0;
        for (auto &x : nums)
        {
            count[x]--;
        }

        for (const auto &[key, val] : count)
        {
            if (val == 1)
                lost = key;
            if (val == -1)
                doubled = key;
        }

        return {doubled, lost};
    }
};