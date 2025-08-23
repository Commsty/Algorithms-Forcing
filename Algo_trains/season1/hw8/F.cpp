#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    long long data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(long long data) : data(data), left(nullptr), right(nullptr) {};
};

TreeNode *insertNode(TreeNode *root, long long data)
{
    if (root == nullptr)
    {
        return new TreeNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void FindForks(TreeNode* root, vector<long long>& forks) {

    if (!root->left && !root->right) {
        return;
    }

    if (root->left)
        FindForks(root->left, forks);

    if (root->left && root->right)
        forks.push_back(root->data);

    if (root->right)
        FindForks(root->right, forks);

    return;
}

int main()
{
    long long tmp;
    TreeNode* root = nullptr;

    while (cin >> tmp && tmp != 0) {
        root = insertNode(root, tmp);
    }

    vector<long long> forks;
    FindForks(root, forks);

    for (const auto& l: forks) {
        cout << l << "\n";
    }

    return 0;
}