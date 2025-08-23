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


int Search(TreeNode* root, long long data) {
    if (root->data == data) {
        return 1;
    }

    if (data < root->data) {
        return Search(root->left, data) + 1;
    }
    
    return Search(root->right, data) + 1;
}



int main()
{
    long long tmp;
    TreeNode* root = nullptr;
    unordered_set<long long> counter;

    while (cin >> tmp && tmp != 0) {
        if (counter.count(tmp) == 0) {
            root = insertNode(root, tmp);
            counter.emplace(tmp);
            cout << Search(root, tmp) << " ";
        }
    }

    
    return 0;
}