#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int commonSum = accumulate(nums.begin(), nums.end(), 0);

        if (target > commonSum || target < -commonSum)
            return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * commonSum + 1));
        dp[0][commonSum + nums[0]] += 1, dp[0][commonSum - nums[0]] += 1;

        for (int pos = 1; pos < nums.size(); pos++)
        {
            for (int sum = -commonSum; sum <= commonSum; sum++)
            {
                { // if summarize
                    if (sum - nums[pos] >= -commonSum)
                        dp[pos][commonSum + sum] += dp[pos - 1][commonSum + sum - nums[pos]];
                }
                { // if subtract
                    if (sum + nums[pos] <= commonSum)
                        dp[pos][commonSum + sum] += dp[pos - 1][commonSum + sum + nums[pos]];
                }
            }
        }

        return dp[nums.size() - 1][commonSum + target];
    }
};

// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         unordered_map<int, int> counter;
//         counter[0] = 1;

//         for (int n : nums)
//         {
//             unordered_map<int, int> temp;

//             for (const auto &[total, count] : counter)
//             {
//                 temp[total + n] += count;
//                 temp[total - n] += count;
//             }
//             counter = temp;
//         }

//         return counter[target];
//     }
// };