#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> counter(n);
    for (int i = 0; i < n; i++)
    {
        cin >> counter[i];
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += min(counter[i], counter[i + 1]);
    }

    cout << ans << endl;

    return 0;
}