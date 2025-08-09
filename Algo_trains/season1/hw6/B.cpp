#include<bits/stdc++.h>
using namespace std;


long long lbinsearch(vector<long long>& arr, long long k){
    long long left = 0, right = arr.size() - 1;
    while (left < right){

        long long mid = (left + right) / 2;
        
        if (arr[mid] >= k)
            right = mid;

        else
            left = mid + 1;
    }
    return left;
}


int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> arr1(n, 0), arr2(k, 0);
    for (long long i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for (long long i = 0; i < k; i++){
        cin >> arr2[i];
    }


    for (long long i = 0; i < k; i++){

        long long index = lbinsearch(arr1, arr2[i]);

        if (index == 0)
            cout << arr1[index] << "\n";

        else if (abs(arr1[index - 1] - arr2[i]) <= abs(arr1[index] - arr2[i]))
            cout << arr1[index - 1] << "\n";

        else
            cout << arr1[index] << "\n";

    }


    return 0;
}