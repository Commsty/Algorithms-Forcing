#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() <= 3)
            return *max_element(nums.begin(), nums.end());

        // var1
        auto nums2 = nums;
        nums2[2] = max(nums2[2], nums2[1]);
        for (int i = 3; i < nums2.size(); i++)
            nums2[i] = max(nums2[i - 1], nums2[i - 2] + nums2[i]);

        //var2
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; i++)
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);

        return max(nums[nums.size() - 2], nums2[nums2.size() - 1]);
    }
};