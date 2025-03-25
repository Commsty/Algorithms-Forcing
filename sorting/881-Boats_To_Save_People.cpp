#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());

        int i = 0, j = people.size() - 1;
        int ans = 0;
        while (i <= j)
        {
            if (i != j && people[i] + people[j] <= limit)
            {
                i++;
                j--;
            }
            else
                j--;
            ans += 1;
        }

        return ans;
    }
};