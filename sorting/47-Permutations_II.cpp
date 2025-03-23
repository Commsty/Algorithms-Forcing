#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    unordered_map<int, int> noRepeatsMap;
    int n;

    void findAllPermutations(vector<int> &actPermute)
    {
        if (actPermute.size() == n)
        {
            ans.push_back(actPermute);
            return;
        }
        for (const auto &[key, val] : noRepeatsMap)
        {
            if (val > 0)
            {
                noRepeatsMap[key]--;
                actPermute.push_back(key);
                findAllPermutations(actPermute);
                actPermute.pop_back();
                noRepeatsMap[key]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            noRepeatsMap[nums[i]]++;
        }

        vector<int> permutation;
        findAllPermutations(permutation);

        return ans;
    }
};