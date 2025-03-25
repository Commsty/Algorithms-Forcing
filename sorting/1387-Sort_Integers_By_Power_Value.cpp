#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        unordered_map<int, int> powers{{1, 0}};
        vector<int> res;

        for (int i = lo; i <= hi; i++)
        {
            res.emplace_back(i);
            int actNum = i;
            while (true)
            {
                if (powers.find(actNum) != powers.end())
                {
                    powers[i] += powers[actNum];
                    break;
                }
                if (actNum % 2 == 0)
                    actNum /= 2;
                else
                    actNum = actNum * 3 + 1;
                powers[i]++;
            }
        }

        auto comparator = [&powers](int a, int b)
        {
            if (powers[a] != powers[b])
                return powers[a] < powers[b];
            else
                return a < b;
        };

        sort(res.begin(), res.end(), comparator);
        return res[k - 1];
    }
};