#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int maxCloset = abs(nums[0] + nums[1] + nums[2] - target);
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            if (abs(nums[i] + nums[j] + nums[k] - target) < maxCloset)
            {
                maxCloset = abs(nums[i] + nums[j] + nums[k] - target);
                res = nums[i] + nums[j] + nums[k];
                j++;
                if (res == target)
                    return target;
            }
            else if (nums[i] + nums[j] + nums[k] > target)
                k--;

            else
                j++;
        }
    }
    return res;
}
};