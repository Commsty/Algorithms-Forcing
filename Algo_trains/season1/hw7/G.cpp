#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    auto comparator = [](vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }

        if (a[1] != b[1]) {
            return a[1] > b[1];
        }

        return a[4] > b[4];
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> baloons(comparator);
    unordered_map<int, int> counter;
    vector<int> helpers;

    for (int i = 1; i <= n; i++)
    {
        int timeForBaloon, numBeforeRest, restTime;
        cin >> timeForBaloon >> numBeforeRest >> restTime;

        int numDone = 0;
        int nowTime = 0;
        baloons.push({nowTime, timeForBaloon, numDone, numBeforeRest, restTime, i});
        counter.emplace(i, 0);
        helpers.push_back(i);
    }

    int baloonsDone = 0;
    int lastTime = 0;

    while (baloonsDone < m && !baloons.empty())
    {
        baloonsDone++;

        auto action = baloons.top();
        baloons.pop();

        counter[action[5]]++;
        action[2]++;
        action[0] += action[1];

        if (action[2] == action[3])
        {
            lastTime = action[0];

            action[0] += action[4];
            action[2] = 0;

            baloons.push(action);
        }
        else
        {
            lastTime = action[0];

            baloons.push(action);
        }
    }


    cout << lastTime << "\n";
    for (const auto& h: helpers) {
        cout << counter[h] << " ";
    }
    cout << "\n";

    return 0;
}