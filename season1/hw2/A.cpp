#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    vector<int> nums;

    while (cin >> num) {
        nums.push_back(num);
    }

    for (int i = 1; i < nums.size(); i++){
        if (nums[i] <= nums[i-1]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}