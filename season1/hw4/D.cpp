#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_map<int, int> taps;
    for (int i = 1; i <= n; i++){
        cin >> taps[i];
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        taps[tmp]--;
    }

    for (int i = 1; i <= n; i++){
        if (taps[i] < 0){
            cout << "YES" << "\n";
        }
        else
            cout << "NO" << "\n";
    }


    return 0;
}