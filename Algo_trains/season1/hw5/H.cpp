#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;

    int left = 0, right = 0;
    unordered_map<char, int> counter;

    int resLength = -1, resStart = -1;

    while (right < n){
        counter[s[right]]++;

        if (right == n - 1 && right - left + 1 > resLength && counter[s[right]] <= k){
            resLength = right - left + 1;
            resStart = left;
        }

        if (counter[s[right]] > k){
            
            if (right - left > resLength){
                resLength = right - left;
                resStart = left;
            }

            while (counter[s[right]] > k){
                counter[s[left]]--;
                left++;
            }

            right++;
        }
        else{

            right++;

        }
    }

    cout << resLength << " " << resStart + 1 << "\n";


    return 0;
}