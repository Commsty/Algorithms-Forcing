#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> xi(n, {0, 0}), xiSort(n, {0, 0});
    vector<vector<int>> yi(m, {0, 0}), yiSort(m, {0,0});
    for (int i = 1; i <= n; i++)
    {
        cin >> xi[i-1][0];
        xi[i-1][1] = i;

        xiSort[i-1] = xi[i-1];
        
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> yi[i-1][0];
        yi[i-1][1] = i;

        yiSort[i-1] = yi[i - 1];
    }

    unordered_map<int, int> groupToAuditory;

    sort(xiSort.begin(), xiSort.end());
    sort(yiSort.begin(), yiSort.end());

    int p = 0;
    int i = 0, j = 0;

    while (j < m && i < n) {
        if (xiSort[i][0] + 1 <= yiSort[j][0]) {
            p++;
            groupToAuditory[xiSort[i][1]] = yiSort[j][1];

            i++;
            j++;
        }
        else {
            j++;
        }
    }

    for (; i < n; i++) {
        groupToAuditory[xiSort[i][1]] = 0;
    }

    cout << p << "\n";
    for (int i = 0; i < n; i++) {
        cout << groupToAuditory[xi[i][1]] << " ";
    }
    cout << "\n";

    return 0;
}