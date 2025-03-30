#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        if (points.size() == 1)
            return *max_element(points[0].begin(), points[0].end());

        vector<long long> prev, act(points[0].size());

        for (long long num : points[0])
            prev.push_back(num);

        for (int row = 1; row < points.size(); row++)
        {
            vector<long long> rightMaxes(points[0].size());
            vector<long long> leftMaxes(points[0].size());

            leftMaxes[0] = prev[0];
            for (int col = 1; col < prev.size(); col++)
                leftMaxes[col] = max(leftMaxes[col - 1] - 1, prev[col]);

            rightMaxes[prev.size() - 1] = prev[prev.size() - 1];
            for (int col = prev.size() - 2; col >= 0; col--)
                rightMaxes[col] = max(rightMaxes[col + 1] - 1, prev[col]);

            for (int col = 0; col < prev.size(); col++)
                act[col] = max(leftMaxes[col], rightMaxes[col]) + points[row][col];

            prev = act;
        }

        return *max_element(act.begin(), act.end());
    }
};