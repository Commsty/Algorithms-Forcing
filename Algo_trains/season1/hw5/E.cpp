#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;

    vector<int> alley(n, 0);
    unordered_map<int, int> colours;
    for (int i = 0; i < n; i++){
        cin >> alley[i];
    }

    int left = 0, right = -1;
    pair<int, int> ans = {0, INT_MAX};

    while (right < n){
        
        if (colours.size() == k){

            ans = ((right - left) < (ans.second - ans.first)) ? make_pair(left, right) : ans;

            colours[alley[left]]--;
            if (colours[alley[left]] == 0){
                colours.erase(alley[left]);
            }

            left++;
        }
        else{

            right++;
            if (right < n)
                colours[alley[right]]++;

        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << "\n";

    return 0;
}