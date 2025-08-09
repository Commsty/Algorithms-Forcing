#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }

    vector<int> ans;

    for (int start = 0; start < nums.size(); start++) {
        int i = start;
        int j = nums.size() - 1;

        while (i <= j && nums[i] == nums[j] && j >= 0 && i < nums.size()){
            i++;
            j--;
        }

        if (i > j){
            
            for (int k = start - 1; k >= 0; k --) {
                ans.push_back(nums[k]);
            }

            break;
        }
    }
    
    cout << ans.size() << "\n";
    for (int x: ans){
        cout << x << " ";
    }


    return 0;
}