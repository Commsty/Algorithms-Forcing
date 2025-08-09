#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);

    int max_dist = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        max_dist = max(max_dist, nums[i]);
    }

    bool was_max_before = false;
    int vasiliy_meters = 0;
    if (nums[0] == max_dist)
        was_max_before = true;

    for (int i = 1; i < nums.size() - 1; i++){
        if (nums[i] % 10 == 5 && was_max_before && nums[i+1] < nums[i] && nums[i] > vasiliy_meters){
            vasiliy_meters = nums[i];
        }

        if (nums[i] == max_dist)
            was_max_before = true;
    }

    if (vasiliy_meters == 0){
        cout << 0 << "\n";
        return 0;
    }


    sort(nums.begin(), nums.end(), greater<int>());

    int pos = 0;
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == vasiliy_meters){
            if (nums[i-1] == nums [i])
                cout << i << "\n";
            else
                cout << i + 1 << "\n";
            return 0;
        }
    }

    return 0;
}