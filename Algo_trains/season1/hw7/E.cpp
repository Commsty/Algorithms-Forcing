#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> times;
    for (int i = 0; i < n; i++)
    {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;

        h1 *= 60, h2 *= 60;

        int common1 = h1 + m1, common2 = h2 + m2;

        if (common1 >= common2)
        {
            times.push_back({common1, -1});
            times.push_back({23 * 60 + 60, 1});

            times.push_back({0, -1});
            times.push_back({common2, 1});
        }
        else
        {
            times.push_back({common1, -1});
            times.push_back({common2, 1});
        }
    }

    sort(times.begin(), times.end());

    int nowCount = 0;
    int commonTime = 0;

    for (int i = 0; i < times.size(); i++)
    {
        if (times[i][1] == -1)
        {
            nowCount++;
        }
        else
        {
            nowCount--;
        }

        if (nowCount == n)
        {
            commonTime += (times[i + 1][0] - times[i][0]);
        }
    }

    cout << commonTime << "\n";

    return 0;
}