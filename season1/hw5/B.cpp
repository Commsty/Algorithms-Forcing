#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> prefixSum(n+1, 0);
    for (int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }

    unordered_map<int, int> counter = {{0, 1}};
    int cnt = 0;

    for (int i = 1; i <= n; i++){
        int neededPrefix = prefixSum[i] - k;

        if (counter.count(neededPrefix) > 0){
            cnt += counter[neededPrefix];
        }

        counter[prefixSum[i]]++;
    }

    cout << cnt << "\n";

    return 0;
}