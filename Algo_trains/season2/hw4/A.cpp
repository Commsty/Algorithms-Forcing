#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int n;
    cin >> n;
    map<ll, ll> counter;

    for (int i = 0; i < n; i++)
    {
        ll di, ai;
        cin >> di >> ai;

        counter[di] += ai;
    }

    for (const auto& [key, value]: counter) {
        cout << key << " " << value << "\n";
    }


    return 0;
}