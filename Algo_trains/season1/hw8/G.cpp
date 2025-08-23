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

void FindSingles(TreeNode* root, vector<long long>& singles) {

    if (!root->left && !root->right){
        return;
    }

    if (root->left){
        FindSingles(root->left, singles);
    }

    if ((root->left && !root->right) || (!root->left && root->right)) {
        singles.push_back(root->data);
    }

    if (root->right){
        FindSingles(root->right, singles);
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

    vector<long long> singles;
    FindSingles(root, singles);

    for (const auto& l: singles) {
        cout << l << "\n";
    }

    return 0;
}