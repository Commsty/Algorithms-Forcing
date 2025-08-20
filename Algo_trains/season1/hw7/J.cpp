#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w, l;
    cin >> n >> w >> l;

    vector<vector<int>> events(2 * n);

    for (int i = 0; i < 2 * n; i += 2)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        events[i] = {z2, -1, (x2 - x1) * (y2 - y1), i / 2};
        events[i + 1] = {z1, 1, (x2 - x1) * (y2 - y1), i / 2};
    }

    sort(events.begin(), events.end());

    int s = w * l;
    int nowS = 0;
    int nowCnt = 0, minCnt = n + 1;

    for (const auto& event: events)
    {
        if (event[1] == -1) {
            nowS -= event[2];
            nowCnt--;
        }
        else {
            nowS += event[2];
            nowCnt++;
        }

        if (nowS == s && nowCnt < minCnt) {
            minCnt = nowCnt;
        }
    }

    if (minCnt == n+1){
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
        cout << minCnt << "\n";

        nowCnt = 0, nowS = 0;

        set<int> used;
        for (const auto& event: events) {
            if (event[1] == -1) {
                nowS -= event[2];
                nowCnt--;

                used.erase(event[3] + 1);
            }
            else {
                nowS += event[2];
                nowCnt++;

                used.emplace(event[3] + 1);
            }

            if (nowS == s && nowCnt == minCnt) {
                for (int i: used) {
                    cout << i << " ";
                }
                break;
            }
        }
    }

    return 0;
}