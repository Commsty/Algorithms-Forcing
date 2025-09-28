#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> shifts{{1, 2}, {2, 1}};

    vector<vector<int>> table(n + 4, vector<int>(m + 4, 0));
    table[2][2] = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        for (int j = 2; j <= m + 1; j++)
        {
            for (const auto &[x, y] : shifts)
            {
                table[i + y][j + x] += table[i][j];
            }
        }
    }

    cout << table[n + 1][m + 1] << endl;

    return 0;
}