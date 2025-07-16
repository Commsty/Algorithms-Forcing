#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_set<int> nums;
    int n;
    while (cin >> n){
        nums.emplace(n);
    }


    cout << nums.size();
    return 0;
}