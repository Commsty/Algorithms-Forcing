#include<bits/stdc++.h>
using namespace std;

int lbinsearch(vector<int>& a, vector<int>& b) {
    int left = 0, right = a.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        int rest = a.size() - mid - 1;

        if (b[rest] > a[mid] && rest > 0 && b[rest - 1] <= a[mid]){
            return a[mid];
        }
        else if (b[rest] > a[mid] && rest == 0){
            return a[mid];
        }
        else if (b[rest] == a[mid]){
            return a[mid];
        }
        else if (b[rest] < a[mid]){
            right = mid - 1;
        }
        else if (b[rest] > a[mid] && rest > 0 && b[rest - 1] > a[mid]){
            left = mid + 1;
        }
    }
    return INT_MAX;
}

int findMedian(vector<int>& a, vector<int>& b){
    int tmp = lbinsearch(a, b);
    if (tmp != INT_MAX)
        return tmp;
    return lbinsearch(b, a);
}


int main(){
    int n, l;
    cin >> n >> l;
    vector<vector<int>> data(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            cin >> data[i][j];
        }
    }


    for (int i = 0; i < n; i++){
        vector<int> seq(l, 0);
        vector<int> d_i(l+1, 0);
        d_i[1] = data[i][1];
        for (int j = 2; j <= l; j++){
            d_i[j] = (data[i][2] * d_i[j-1] + data[i][3]) % data[i][4];
        }
        
        seq[0] = data[i][0];
        for (int j = 1; j < l; j++){
            seq[j] = seq[j-1] + d_i[j];
        }

        data[i] = seq;
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            cout << findMedian(data[i], data[j]) << "\n";
        }
    }
    
    return 0;
}