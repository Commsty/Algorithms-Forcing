#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        if (nums[0] > 0)
            return {};

        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i>0 && nums[i]==nums[i-1]) continue;

            int i_num = nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (i_num + nums[j] + nums[k] == 0){
                    res.push_back({i_num, nums[j++], nums[k]});

                    while (j<k && nums[j]==nums[j-1])
                        j++;
                }
                    
                if (i_num + nums[j] + nums[k] > 0)
                    k--;
                if (i_num + nums[j] + nums[k] < 0)
                    j++;
            }
        }
        return res;
    }
};