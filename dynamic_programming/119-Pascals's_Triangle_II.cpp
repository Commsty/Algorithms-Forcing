#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> actRow(rowIndex + 1, 0);
        actRow[0] = 1;

        for (int i = 1; i <= rowIndex; i++)
        {
            actRow[i] = 1;
            int prev = 1;
            for (int j = 1; j < i; j++){
                actRow[j] += prev;
                prev = actRow[j] - prev;
            }
        }

        return actRow;
    }
};