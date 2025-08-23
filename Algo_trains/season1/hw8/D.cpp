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

void MaxPrintDFS(TreeNode *root)
{
    if (root == nullptr){
        return;
    }

    if (root->left != nullptr)
    {
        MaxPrintDFS(root->left);
    }

    cout << root->data << "\n";

    if (root->right != nullptr)
    {
        MaxPrintDFS(root->right);
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

    MaxPrintDFS(root);

    return 0;
}