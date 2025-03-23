#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> cnt;

        for (const auto &x : s)
        {
            cnt[x]++;
        }
        for (const auto &x : t)
        {
            cnt[x]--;
        }
        for (const auto &[key, val] : cnt)
        {
            if (val != 0)
                return false;
        }
        return true;
    }
};