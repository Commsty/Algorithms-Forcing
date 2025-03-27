#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    stack<char> rest_symbols;

    bool isSubsequence(string s, string t)
    {
        if (s.size() > t.size())
            return false;
        if (s == "")
            return true;

        for (int i = s.size() - 1; i >= 0; i--)
            rest_symbols.emplace(s[i]);

        for (char sym : t)
        {
            if (sym == rest_symbols.top())
                rest_symbols.pop();

            if (rest_symbols.empty())
                return true;
        }

        return false;
    }
};