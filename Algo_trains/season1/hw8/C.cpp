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

long long MaxDFS(TreeNode* root) {
    long long ans = root->data;
    root = root->right;

    while (root != nullptr) {
        ans = root->data;
        root = root->right;
    }

    return ans;
}

long long Max2DFS(TreeNode* root, long long prev) {

    if (root->right == nullptr && root->left == nullptr){
        return prev;
    }

    if (root->right == nullptr && root->left != nullptr) {
        return MaxDFS(root->left);
    }

    return Max2DFS(root->right, root->data);
}

int main()
{
    long long tmp;
    TreeNode* root = nullptr;

    while (cin >> tmp && tmp != 0) {
        root = insertNode(root, tmp);
    }

    cout << Max2DFS(root, -1) << "\n";


    return 0;
}