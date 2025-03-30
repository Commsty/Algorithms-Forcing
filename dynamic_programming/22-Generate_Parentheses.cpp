#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

        vector<string> res;

        vector<string> generateParenthesis(int n) {
            dfs(0, 0, "", n);
            return res;        
        }
    
        void dfs(int openP, int closeP, string s, int n) {
            if (openP + closeP == n * 2) {
                res.push_back(s);
                return;
            }
    
            if (openP < n) {
                dfs(openP + 1, closeP, s + "(", n);
            }
    
            if (closeP < openP) {
                dfs(openP, closeP + 1, s + ")", n);
            }
        }
    };