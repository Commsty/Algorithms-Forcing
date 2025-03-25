#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;

        for (auto x : nums)
        {
            counts[x]++;
        }

        vector<vector<int>> frequencyBuckets(nums.size() + 1);
        for (const auto &[key, val] : counts)
        {
            frequencyBuckets[val].push_back(key);
        }

        vector<int> res;
        int cnt = 0;
        for (int i = frequencyBuckets.size() - 1; i > 0 && cnt < k; i--)
        {
            if (!frequencyBuckets[i].empty())
            {
                for (const auto x : frequencyBuckets[i])
                {
                    res.push_back(x);
                }
                cnt += frequencyBuckets[i].size();
            }
        }

        return res;
    }
};

//Heap Solution

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         if (k == nums.size())
//             return nums;

//         unordered_map<int, int> counts;
//         for (auto x : nums)
//         {
//             counts[x]++;
//         }

//         auto comparator = [&counts](int a, int b)
//         { return counts[a] > counts[b]; };
//         priority_queue<int, vector<int>, decltype(comparator)> maxFreqHeap(comparator);

//         for (const auto &x : counts)
//         {
//             maxFreqHeap.push(x.first);
//             if (maxFreqHeap.size()>k)
//                 maxFreqHeap.pop();
//         }

//         vector<int> res;
//         for (int i = 0; i < k; i++)
//         {
//             res.push_back(maxFreqHeap.top());
//             maxFreqHeap.pop();
//         }

//         return res;
//     }
// };