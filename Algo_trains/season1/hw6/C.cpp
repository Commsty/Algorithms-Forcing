#include<bits/stdc++.h>
using namespace std;


long long lbinsearch(long long w, long long h, long long n){

    long long left = 0, right = max(w, h) * n;

    while (left < right){

        long long mid = (left + right) / 2;

        long long w_cnt = mid / w, h_cnt = mid / h;

        if (w_cnt * h_cnt >= n)
            right = mid;

        else
            left = mid + 1;
    }
    return left;
}


int main(){
    int w, h, n;
    cin >> w >> h >> n;

    cout << lbinsearch(w, h, n) << "\n";

    return 0;
}