#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cntBuses(n + 1, 0), busesBalance(n + 1, 0);
    vector<vector<int>> events(2 * m);
    int overMidnight = 0;

    for (int i = 0; i < 2 *m; i+=2) {
        int from, to;
        string fromTimeString, toTimeString;
        cin >> from >> fromTimeString >> to >> toTimeString;

        int fromTime = atoi(fromTimeString.substr(0, 2).c_str()) * 60 + atoi(fromTimeString.substr(3, 2).c_str());
        int toTime = atoi(toTimeString.substr(0, 2).c_str()) * 60 + atoi(toTimeString.substr(3, 2).c_str());

        events[i] = {fromTime, 1, from};
        events[i+1] = {toTime, -1, to};

        if (fromTime > toTime) {
            overMidnight++;
        }

        busesBalance[to]++;
        busesBalance[from]--;
    }

    for (const auto b: busesBalance) {
        if (b != 0) {
            cout << -1 << "\n";
            return 0;
        }
    }

    sort(events.begin(), events.end());

    for (const auto& event: events) {

        if (event[1] == -1) {
            cntBuses[event[2]]++;
        }
        else {
            if (cntBuses[event[2]] > 0) {
                cntBuses[event[2]]--;
            }
        }
    }

    int ans = 0;
    for (const auto b: cntBuses) {
        ans += b;
    }

    cout << ans + overMidnight << "\n";

    return 0;
}