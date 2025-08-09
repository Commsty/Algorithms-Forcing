#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    vector<int> nums;

    while (cin >> n){
        nums.push_back(n);
    }

    int cnt = 0;
    for (int i = 1; i < nums.size() - 1; i++){
        if (nums[i] > nums[i-1] && nums[i] > nums[i+1]){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}