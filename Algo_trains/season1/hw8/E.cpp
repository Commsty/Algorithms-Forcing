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

void FindLeafs(TreeNode* root, vector<long long>& leafs) {
    if (root->left != nullptr) {
        FindLeafs(root->left, leafs);
    }

    if (root->right != nullptr) {
        FindLeafs(root->right, leafs);
    }

    if (root->left == nullptr && root->right == nullptr) {
        leafs.push_back(root->data);
    }

    return;
}

int main()
{
    long long tmp;
    TreeNode* root = nullptr;

    while (cin >> tmp && tmp != 0) {
        root = insertNode(root, tmp);
    }

    vector<long long> leafs;
    FindLeafs(root, leafs);

    for (const auto& l: leafs) {
        cout << l << "\n";
    }

    return 0;
}