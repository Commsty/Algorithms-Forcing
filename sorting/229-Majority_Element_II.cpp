#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> counts;

    for (auto num : nums)
    {
        if (!counts.count(num) && counts.size() == 2)
        {
            for (auto &[key, val] : counts)
                val--;
            for (auto it = counts.begin(); it != counts.end();)
            {
                if (it->second == 0)
                    it = counts.erase(it);
                else
                    ++it;
            }
        }
        else
        {
            counts[num]++;
        }
    }

    vector<int> res;
    for (auto &[key, val] : counts)
    {
        int cnt = 0;
        for (int num : nums)
        {
            if (num == key)
                cnt++;
        }
        if (cnt * 3 > nums.size())
            res.push_back(key);
    }

    return res;
}
};