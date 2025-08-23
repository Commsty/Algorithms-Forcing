#include<bits/stdc++.h>
using namespace std;

int CountChildren(unordered_map<string, vector<string>>& tree, unordered_map<string, int>& memo, string parent) {

    if (tree.count(parent) == 0){
        return 0;
    }

    if (memo.count(parent) != 0) {
        return memo[parent];
    }

    int cnt = 0;
    for (const auto& child: tree[parent]) {

        memo[child] = CountChildren(tree, memo, child);
        cnt += (1 + memo[child]);
    }

    return cnt;
}


int main() {
    int n;
    cin >> n;

    set<string> people;
    unordered_map<string, vector<string>> tree;
    unordered_map<string, int> memo;

    for (int i = 0; i < n-1; i++) {
        string child, parent;
        cin >> child >> parent;

        tree[parent].push_back(child);

        people.emplace(child);
        people.emplace(parent);
    }

    for (const auto &man: people) {
        cout << man << " " << CountChildren(tree,memo, man) << "\n";
    }

    return 0;
}