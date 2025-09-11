#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    unordered_map<string, ll> counter;
    unordered_set<string> strStorage;
    vector<string> strVector;

    string tmp;
    while (cin >> tmp) {
        counter[tmp]++;

        if (strStorage.count(tmp) == 0) {
            strVector.push_back(tmp);
        }

        strStorage.emplace(tmp);
    }

    auto comparator = [&counter](const string& a, const string& b) {
        return counter[a] == counter[b] ? a < b: counter[a] > counter[b];
    };

    sort(strVector.begin(), strVector.end(), comparator);

    for (const auto& s: strVector) {
        cout << s << "\n";
    }

    return 0;
}