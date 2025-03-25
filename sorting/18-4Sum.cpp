#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> find2Sum(vector<int> &nums, int leftIndex, int rightIndex, long long target)
    {
        vector<vector<int>> res;

        while (leftIndex < rightIndex)
        {
            if (nums[leftIndex] + nums[rightIndex] == target)
            {
                res.push_back({nums[leftIndex++], nums[rightIndex]});
                while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1])
                    leftIndex++;
            }

            else if (nums[leftIndex] + nums[rightIndex] > target)
                rightIndex--;
            else if (nums[leftIndex] + nums[rightIndex] < target)
                leftIndex++;
        }

        return res;
    }

    vector<vector<int>> find_K_Summ(vector<int> &nums, int leftIndex, int rightIndex, int k, long long target)
    {
        if (nums.size() < k)
            return {};

        if (k == 2)
            return find2Sum(nums, leftIndex, rightIndex, target);

        vector<vector<int>> res;
        for (int i = leftIndex; i <= rightIndex - k + 1; i++)
        {
            if (i!=leftIndex && nums[i]==nums[i-1]) continue;

            auto less_K_range = find_K_Summ(nums, i + 1, rightIndex, k - 1, target - nums[i]);

            for (auto &x : less_K_range)
            {
                x.push_back(nums[i]);
            }

            res.insert(res.end(), less_K_range.begin(), less_K_range.end());
        }

        return res;
    }

    vector<vector<int>> fourSum(vector<int> &nums, long long target)
    {
        sort(nums.begin(), nums.end());
        return find_K_Summ(nums, 0, nums.size() - 1, 4, target);
    }
};