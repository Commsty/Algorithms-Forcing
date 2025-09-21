#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<pair<int, int>> townPrices;
    vector<int> ans(n, -1);

    int idx = 0, tmp;
    while (n > 0)
    {
        cin >> tmp;

        while (!townPrices.empty() && tmp < townPrices.top().first)
        {
            ans[townPrices.top().second] = idx;
            townPrices.pop();
        }

        townPrices.push({tmp, idx});
        idx++;
        n--;
    }

    for (const auto& res: ans) {
        cout << res << " ";
    }

    return 0;
}