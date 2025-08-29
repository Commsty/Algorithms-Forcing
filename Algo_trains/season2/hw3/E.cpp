#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m;
    cin >> m;

    vector<unordered_set<char>> wits(m);
    for (int i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        wits[i] = unordered_set<char>(tmp.begin(), tmp.end());
    }

    int n;
    cin >> n;

    int maxWitCnt = 0;
    vector<pair<string, int>> nums;

    for (int i = 0; i < n; i++)
    {
        string num;
        cin >> num;

        unordered_set<char> numset(num.begin(), num.end());
        int witCnt = 0;

        for (const auto &wit : wits)
        {
            bool flag = true;
            for (const auto c : wit)
            {
                if (numset.count(c) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                witCnt++;
            }
        }

        nums.push_back({num, witCnt});
        maxWitCnt = max(maxWitCnt, witCnt);
    }

    for (auto num: nums) {
        if (num.second == maxWitCnt)
            cout << num.first << "\n";
    }

    return 0;
}