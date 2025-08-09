#include<bits/stdc++.h>
using namespace std;


int lbinsearch(vector<int>& arr, int k){
    int left = 0, right = arr.size() - 1;
    while (left < right){

        int mid = (left + right) / 2;
        
        if (arr[mid] >= k)
            right = mid;

        else
            left = mid + 1;
    }
    return left;
}


int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr1(n, 0), arr2(k, 0);
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for (int i = 0; i < k; i++){
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < k; i++){
        int index = lbinsearch(arr1, arr2[i]);

        if (index < n && index >= 0 && arr1[index] == arr2[i]){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }


    return 0;
}