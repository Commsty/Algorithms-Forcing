#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int diff = (accumulate(aliceSizes.begin(), aliceSizes.end(), 0) - accumulate(bobSizes.begin(), bobSizes.end(), 0)) / 2;
        unordered_set<int> alice(aliceSizes.begin(), aliceSizes.end());
        for (int b : bobSizes)
        {
            if (alice.count(b + diff))
                return {b + diff, b};
        }
        return {};
    }
};