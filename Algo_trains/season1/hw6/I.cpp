#include<bits/stdc++.h>
using namespace std;

int lbinsearch(int n, int r, int c, vector<int>& h){
    int left = 0, right = h.back() - h.front();

    while (left < right){
        int mid = (left + right) / 2;

        int cnt = 0;
        int i = c - 1;
        while (i < n){
            if (h[i] - h[i - c + 1] <= mid){
                cnt++;
                i += c;
            }
            else{
                i++;
            }
        }

        if (cnt >= r){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}


int main(){
    int n, r, c;
    cin >> n >> r >> c;
    vector<int> h(n, 0);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());

    cout << lbinsearch(n, r, c, h) << "\n";

    return 0;
}