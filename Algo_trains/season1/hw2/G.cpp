#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<long long> nums;
    long long num, max1 = LONG_LONG_MIN, max2 = LONG_LONG_MIN;

    while (cin >> num){
        nums.push_back(num);


        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
    }
    

    long long min1 = LONG_LONG_MAX, min2 = LONG_LONG_MAX;
    for (int x: nums){
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    if (max1 * max2 > min1 * min2)
        cout << max2 << " " << max1;
    else
        cout << min1 << " " << min2;

    return 0;
}