#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        make_heap(nums.begin(),nums.end(),less<int>());
        sort_heap(nums.begin(),nums.end(),less<int>());
        return nums;
    }
};