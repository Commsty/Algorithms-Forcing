#include<bits/stdc++.h>
using namespace std;



int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> keys;
    unordered_map<long long, long long> nums;
    for (long long i = 0; i < n; i++){
        long long tmp;
        cin >> tmp;
        nums[tmp]++;
    }
    for (const auto& [key, value]: nums){
        keys.push_back(key);
    }
    sort(keys.begin(), keys.end());

    long long right = 0, duplicates = 0;
    long long ans = 0;

    for (long long left = 0; left < keys.size(); left++){

        while (right < keys.size() && keys[left] * k >= keys[right]){
            if (nums[keys[right]] >= 2){
                duplicates++;
            }
            right++;
        }

        if (nums[keys[left]] >= 3){
            ans++;
        }

        if (nums[keys[left]] >= 2){
            ans += (right - left - 1) * 3;
        }

        ans += (right - left - 1) * (right - left - 2) * 3;

        if (nums[keys[left]] >= 2){
            duplicates--;
        }

        ans += duplicates * 3;
    }


    cout << ans << "\n"; 

    return 0;
}