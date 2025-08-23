#include <bits/stdc++.h>
using namespace std;

int GetHeight(unordered_map<string, string> &tree, unordered_map<string, int> &memo, string man)
{

    if (memo.count(man) > 0)
    {
        return memo[man];
    }

    if (tree.count(man) == 0)
    {
        memo[man] = 0;
        return 0;
    }

    string parent = tree[man];

    memo[parent] = GetHeight(tree, memo, parent);
    memo[man] = memo[parent] + 1;

    return memo[man];
}

int main()
{
    int n;
    cin >> n;

    set<string> people;
    unordered_map<string, string> tree;
    unordered_map<string, int> memo;

    for (int i = 0; i < n - 1; i++)
    {
        string child, parent;
        cin >> child >> parent;

        tree[child] = parent;
        people.emplace(child);
        people.emplace(parent);
    }

    for (const auto &man : people)
    {
        cout << man << " " << GetHeight(tree, memo, man) << "\n";
    }

    return 0;
}