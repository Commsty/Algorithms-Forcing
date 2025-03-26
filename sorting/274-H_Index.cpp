#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        vector<int> counts(citations.size() + 1, 0);
        for (auto &x : citations)
        {
            counts[min(x, (int)citations.size())]++;
        }

        int papers_cited = 0;
        for (int h_index = citations.size(); h_index >= 0; h_index--)
        {
            papers_cited += counts[h_index];
            if (papers_cited >= h_index)
                return h_index;
        }
        return 0;
    }
};