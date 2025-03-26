#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countNums(int n)
    {
        vector<int> res(10, 0);
        for (; n > 0; n /= 10)
        {
            res[n % 10]++;
        }
        return res;
    }

    bool reorderedPowerOf2(int n)
    {
        int pow2 = 1;
        auto countN = countNums(n);
        while (pow2 <= n)
        {
            if (countNums(pow2) == countN)
                return true;
            pow2 *= 2;
        }
        return false;
    }
};

vector<int> countNums(int n)
{
    vector<int> res(10, 0);
    for (; n > 0; n /= 10)
    {
        res[n % 10]++;
    }
    return res;
}

bool reorderedPowerOf2(int n)
{
    int pow2 = 1;
    auto countN = countNums(n);
    while (to_string(pow2).size() <= to_string(n).size())
    {
        if (countNums(pow2) == countN)
            return true;
        pow2 *= 2;
    }
    return false;
}

int main()
{
    for (auto x : countNums(64))
        cout << x << " ";

    return 0;
}