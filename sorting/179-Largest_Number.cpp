#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             { return to_string(b) + to_string(a) < to_string(a) + to_string(b); });

        if (nums[0] == 0)
            return "0";

        string res = "";
        for (const auto &x : nums)
        {
            res += to_string(x);
        }
        return res;
    }
};