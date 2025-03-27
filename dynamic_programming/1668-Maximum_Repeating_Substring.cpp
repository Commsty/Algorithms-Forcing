#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        if (word.size() > sequence.size())
            return 0;

        int w = word.size();
        int i = 0, j = w - 1;
        int k = 0, ans = 0;

        while (j < sequence.size())
        {
            if (sequence.substr(i, j - i + 1) == word)
            {
                int nowK = 1;
                i += w, j += w;
                while (j < sequence.size() && sequence.substr(i, j - i + 1) == word)
                {
                    i += w, j += w;
                    nowK++;
                }
                ans = max(ans, nowK);
                i -= (w - 1), j -= (w - 1);
            }
            else
                i++, j++;
        }

        return ans;
    }
};