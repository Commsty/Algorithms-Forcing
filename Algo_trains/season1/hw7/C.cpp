#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> points(2 * n, {0, 0});
    vector<int> studentsToSort, studentsNoSort;

    for (int i = 0; i < 2 * n; i += 2)
    {
        int tmp;
        cin >> tmp;

        studentsToSort.push_back(tmp);
        studentsNoSort.push_back(tmp);

        points[i] = make_pair(tmp, 1);
        points[i + 1] = make_pair(tmp + d, -1);
    }

    sort(points.begin(), points.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first == b.first ? a.second > b.second : a.first < b.first; });
    sort(studentsToSort.begin(), studentsToSort.end());

    int variants = 1;
    int cnt = 0;

    for (int i = 0; i < 2 * n; i++)
    {

        if (points[i].second == 1)
        {
            cnt++;
            continue;
        }

        variants = max(variants, cnt);
        cnt--;
    }

    cout << variants << "\n";

    unordered_map<int, int> studVars;
    for (int i = 0; i < n; i++)
    {
        studVars[studentsToSort[i]] = i % variants + 1;
    }

    for (const auto &s : studentsNoSort)
    {
        cout << studVars[s] << " ";
    }

    return 0;
}