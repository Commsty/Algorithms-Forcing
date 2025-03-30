#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> cache;

    long long findMin(vector<int> &nums, int nowPos)
    {
        if (cache[nowPos] != INT_MAX)
            return cache[nowPos];

        if (nowPos + nums[nowPos] >= nums.size() - 1)
        {
            cache[nowPos] = 1;
            return 1;
        }

        for (int i = 1; i <= nums[nowPos]; i++)
        {
            cache[nowPos] = min(cache[nowPos], 1 + findMin(nums, nowPos + i));
        }

        return cache[nowPos];
    }

    int jump(vector<int> &nums)
    {
        cache.resize(nums.size(), INT_MAX);
        cache[nums.size() - 1] = 0;
        return static_cast<int>(findMin(nums, 0));
    }
};