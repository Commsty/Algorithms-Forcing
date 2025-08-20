#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int j = 0; j < k; j++)
    {
        int n;
        cin >> n;

        vector<vector<int>> events(2 * n);
        for (int i = 0; i < 2 * n; i += 2)
        {
            int in, out;
            cin >> in >> out;

            events[i] = {in, -1, i};
            events[i + 1] = {out, 1, i};
        }

        sort(events.begin(), events.end());

        bool flag = true;
        unordered_set<int> needed, now;
        int prevTime = -1;

        for (int i = 0; i < 2 * n; i++)
        {
            if (now.size() == 0 && events[i][0] != 0)
            {
                flag = false;
                break;
            }

            if (now.size() == 1 && events[i][0] != prevTime)
            {
                for (int i : now)
                {
                    needed.emplace(i);
                }
            }

            if (events[i][1] == -1)
            {
                now.emplace(events[i][2]);
            }
            else
            {
                now.erase(events[i][2]);
            }
            prevTime = events[i][0];
        }

        if (events[events.size() - 1][0] != 10000)
        {
            flag = false;
        }

        if (flag && needed.size() == n)
        {
            cout << "Accepted\n";
        }
        else
        {
            cout << "Wrong Answer\n";
        }
    }

    return 0;
}