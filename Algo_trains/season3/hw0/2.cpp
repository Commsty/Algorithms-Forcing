#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string s;
    cin >> k >> s;

    if (static_cast<size_t>(k) >= s.size() || s.size() == 0u || s.size() == 1u){
        cout << s.size() << endl;
        return 0;
    }

    unordered_set<char> letters;
    for (auto x: s) {
        letters.emplace(x);
    }

    int res = k;

    for (const auto c: letters) {
    
        int left = 0, right = 0;
        int nowCount = k;
        while (left < static_cast<int>(s.size())) {
            
            while (right < s.size() && (nowCount > 0 || s[right] == c)) {
                if (s[right] != c) {
                    nowCount--;
                }
                right++;
            }

            res = max(res, right - left);
            if (s[left] != c) {
                nowCount++;
            }
            left++;
        }
    }

    cout << res << endl;

    return 0;
}