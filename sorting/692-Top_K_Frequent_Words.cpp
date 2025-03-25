#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> counts;
        for (const auto &x : words)
        {
            counts[x]++;
        }

        auto comparator = [&counts](string a, string b)
        {
            if (counts[a] != counts[b])
                return counts[a] > counts[b];
            else
                return a < b;
        };
        priority_queue<string, vector<string>, decltype(comparator)> maxFreqHeap(comparator);

        for (const auto &x : counts)
        {
            maxFreqHeap.push(x.first);
            if (maxFreqHeap.size() > k)
                maxFreqHeap.pop();
        }

        vector<string> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(maxFreqHeap.top());
            maxFreqHeap.pop();
        }

        auto resComparator = [&counts](string a, string b)
        {
            if (counts[a]!=counts[b])
                return counts[a] > counts[b];
            else
                return a<b;
        };
        
        sort(res.begin(),res.end(),resComparator);
        return res;
    }
};