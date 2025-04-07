#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int left = 0, right = needle.length() - 1;

        while (right < haystack.size())
        {
            if (haystack[left] == needle[0] && haystack[right] == needle[needle.size() - 1])
            {
                if (haystack.substr(left, needle.size()) == needle)
                    return left;
            }
            left++;
            right++;
        }
        return -1;
    }
};