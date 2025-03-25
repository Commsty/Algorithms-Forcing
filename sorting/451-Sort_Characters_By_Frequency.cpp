#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> counts;
        for (const auto &x : s)
        {
            counts[x]++;
        }

        auto comparator = [&counts](char a, char b)
        { 
        if (counts[a]!=counts[b])
            return counts[a] > counts[b];
        else
            return a>b;
        };

        sort(s.begin(), s.end(), comparator);
        return s;
    }
};