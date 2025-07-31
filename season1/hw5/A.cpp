#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m, tmp;
    vector<int> upper, lower;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        upper.push_back(tmp);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        lower.push_back(tmp);
    }

    int upPointer = 0, lowPointer = 0;
    int minDiff = INT_MAX;
    pair<int, int> bestPair = {0, 0};

    while (lowPointer < lower.size() && upPointer < upper.size()){

        int tmpDiff = abs(lower[lowPointer] - upper[upPointer]);

        if (tmpDiff < minDiff){
            minDiff = tmpDiff;
            bestPair = {upper[upPointer], lower[lowPointer]};
        }

        if (upper[upPointer] < lower[lowPointer]){
            upPointer++;
        }

        else{
            lowPointer++;
        }
    }

    cout << bestPair.first << " " << bestPair.second << "\n";
    

    return 0;
}