#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (indices.count(target - nums[i]) && indices[target - nums[i]] != i)
            {
                return {i, indices[target - nums[i]]};
            }
        }

        return {};
    }
};