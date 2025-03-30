#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0], actSumm = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            actSumm=max(nums[i],actSumm+nums[i]);
            res = max(res, actSumm);
        }
        return res;
    }
};