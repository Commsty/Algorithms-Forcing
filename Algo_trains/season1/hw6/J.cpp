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
    vector<vector<int>> data(n, vector<int>(l, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < l; j++){
            cin >> data[i][j];
        }
    }


    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            cout << findMedian(data[i], data[j]) << "\n";
        }
    }
    
    return 0;
}