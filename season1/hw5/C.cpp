#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m, skip;
    cin >> n;
    vector<int> height(n, 0);

    for (int i = 0; i < n; i++){
        cin >> skip >> height[i];
    }

    vector<int> prefixSumToRight(n, 0), prefixSumToLeft(n, 0);
    for (int i = 1; i < n; i++){
        prefixSumToRight[i] = prefixSumToRight[i-1];
        if (height[i] > height[i-1]){
            prefixSumToRight[i] += (height[i] - height[i-1]);
        }
    }
    for (int i = n - 2; i >= 0; i--){
        prefixSumToLeft[i] = prefixSumToLeft[i+1];
        if (height[i] > height[i+1]){
            prefixSumToLeft[i] += (height[i] - height[i+1]);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        if (a <= b){
            cout << prefixSumToRight[b-1] - prefixSumToRight[a-1] << "\n";
        }

        else{
            cout << prefixSumToLeft[b-1] - prefixSumToLeft[a-1] << "\n";
        }
    }


    return 0;
}