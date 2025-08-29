#include<bits/stdc++.h>
using namespace std;


int main() {

    vector<int> nums;
    unordered_map<int, int> counter;

    int tmp;
    while (cin >> tmp) {
        nums.push_back(tmp);
        counter[tmp]++;
    }

    for (const auto& n: nums) {
        if (counter[n] == 1)
            cout << n << " ";
    }


    return 0;
}