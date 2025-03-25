#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        unordered_map<int, unordered_set<int>> y_values;
        for (const auto &coordinates : points)
        {
            y_values[coordinates[0]].insert(coordinates[1]);
        }

        int minArea = INT_MAX;

        for (int i = 0; i < points.size() - 1; i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[j][0], y1 = points[i][1];
                int x2 = points[i][0], y2 = points[j][1];
                
                if (x1 != x2 && y1 != y2 && y_values[x1].count(y1) && y_values[x2].count(y2))
                    minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2));
            }
        }

        return (minArea != INT_MAX) ? minArea : 0;
    }
};