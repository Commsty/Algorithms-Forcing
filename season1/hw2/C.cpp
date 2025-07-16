#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int x, diff = 100000, ans = 0;
    cin >> x;

    for (const int c : nums){
        if (abs(c - x) < diff){
            diff = abs(c - x);
            ans = c;
        }
    }

    cout << ans;

    return 0;
}