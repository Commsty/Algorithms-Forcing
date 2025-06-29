#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> tmp;
            int start_index = 0;

            combiner(result, tmp, candidates, 0, 0, target);

            return result;
            
        }

        void combiner(vector<vector<int>>& res, vector<int>& act, const vector<int>& nums, int idx, int sum, int target){
            if (sum > target || idx >= nums.size())
                return;

            if (sum == target){
                res.push_back(act);
                return;
            }

            act.push_back(nums[idx]);
            combiner(res, act, nums, idx, sum+nums[idx], target);
            act.pop_back();
            combiner(res, act, nums, idx+1, sum, target);
        }
    };