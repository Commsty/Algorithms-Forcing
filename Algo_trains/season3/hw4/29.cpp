#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n" << 0 << " " << 0 << "\n";
        return 0;
    }

    vector<long long> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    if (n == 1) {
        cout << prices[0] << "\n";
        if (prices[0] > 100) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<long long>> dp(n, vector<long long>(n+1, INT_MAX));
    if (prices[0] > 100) {
        dp[0][1] = prices[0];
    }
    else {
        dp[0][0] = prices[0];
    }

    for (int i = 1; i < n; i++)
    {

        if (prices[i] <= 100) {
            dp[i][0] = min(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        else {
            dp[i][0] = dp[i-1][1];
        }

        for (int j = 1; j < n; j++)
        {
            if (prices[i] <= 100)
            {
                dp[i][j] = min(dp[i - 1][j] + prices[i], dp[i - 1][j + 1]);
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + prices[i], dp[i - 1][j + 1]);
            }
        }

        if (prices[i] <= 100)
        {
            dp[i][n] = dp[i - 1][n] + prices[i];
        }
        else
        {
            dp[i][n] = dp[i - 1][n - 1] + prices[i];
        }
    }

    int ans = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    int k1, k2 = 0;

    for (int i = n; i >= 0; i--)
    {
        if (dp[n - 1][i] == ans)
        {
            k1 = i;
            break;
        }
    }

    int couponsNow = k1;
    vector<int> useDays;

    while (n - 1 > 0) {
        int dayPrice = prices[n-1];

        if (dayPrice <= 100) {
            if (couponsNow == n) {
                n--;
            }
            else if (dp[n-2][couponsNow] + dayPrice < dp[n-2][couponsNow+1]){
                n--;
            }
            else {
                k2++;
                useDays.push_back(n);
                n--;
                couponsNow++;
            }
        }
        else {
            if (couponsNow == 0) {
                k2++;
                useDays.push_back(n);
                couponsNow++;
                n--;
            }
            else if (couponsNow == n) {
                couponsNow--;
                n--;
            }
            else if (dp[n-2][couponsNow - 1] + dayPrice < dp[n-2][couponsNow + 1]) {
                couponsNow--;
                n--;
            }
            else {
                k2++;
                useDays.push_back(n);
                couponsNow++;
                n--;
            }
        }
    }

    cout << ans << "\n" << k1 << " " << k2 << "\n";
    for (auto it = useDays.rbegin(); it != useDays.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}