#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, unordered_set<int>> numMap;
        for (int i = 0; i < nums.size(); i++)
        {
            numMap[nums[i]].emplace(i);
        }

        int cnt = 0;
        for (const auto &[key, val] : numMap)
        {
            if (numMap.count(key - k))
            {
                if ((key - k == key && numMap[key - k].size() > 1) || (key - k != key)){
                    cnt++;
                }
                
            }
            if (numMap.count(key + k))
            {
                if ((key + k == key && numMap[key + k].size() > 1) || (key + k != key)){
                    cnt++;
                }
            }
        }

        return cnt/2;
    }
};