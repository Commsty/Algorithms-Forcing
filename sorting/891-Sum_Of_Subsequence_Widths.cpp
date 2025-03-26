#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long mod = 1e9 + 7;
        vector<long long> powers(nums.size(), 0);
        powers[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            powers[i] = (powers[i - 1] * 2) % mod;
        }

        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += ((powers[i] - powers[nums.size() - i - 1]) * nums[i]) % mod;
        }

        return (res % mod + mod) % mod;
    }
};