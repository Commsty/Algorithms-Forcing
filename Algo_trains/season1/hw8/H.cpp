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

bool AVLBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }

    if (abs(getHeight(root->left) - getHeight(root->right)) > 1){
        return false;
    }

    if (!AVLBalanced(root->left) || !AVLBalanced(root->right)) {
        return false;
    }

    return true;
}

int main()
{
    long long tmp;
    TreeNode *root = nullptr;
    
    while (cin >> tmp && tmp != 0)
    {
        root = insertNode(root, tmp);
    }
    
    if (AVLBalanced(root)) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    
    return 0;
}