#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        return size(nums) * (size(nums) + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};