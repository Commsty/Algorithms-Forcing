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

long long getHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
}

int main()
{
    long long tmp;
    TreeNode *root = nullptr;
    
    while (cin >> tmp && tmp != 0)
    {
        root = insertNode(root, tmp);
    }
    
    cout << getHeight(root) << "\n";
    
    return 0;
}