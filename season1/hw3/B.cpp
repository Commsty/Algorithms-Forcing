#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    unordered_set<int> nums;
    
    while(cin >> n){
        nums.emplace(n);
        if (cin.peek() == '\n') break;
    }

    set<int> ans;
    while (cin >> n){
        if (nums.count(n) != 0){
            ans.emplace(n);
        }
    }

    for (int x: ans){
        cout << x << " ";
    }

    return 0;
}