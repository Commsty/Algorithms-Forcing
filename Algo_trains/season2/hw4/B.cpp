#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string tmp;
    map<string, ll> counter;
    while (cin >> tmp) {
        ll num;
        cin >> num >> ws;

        counter[tmp] += num;
    }

    for(const auto&[k, v]: counter) {
        cout << k << " " << v << "\n";
    }


    return 0;
}