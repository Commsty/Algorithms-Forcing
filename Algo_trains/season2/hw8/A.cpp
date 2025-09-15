#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;

    long long data;

    Node(long long data) : data(data), left(nullptr), right(nullptr) {};
};

Node *Add(Node *root, long long data)
{
    if (!root)
    {
        cout << "DONE\n";
        return new Node(data);
    }
    else if (data < root->data)
    {
        root->left = Add(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Add(root->right, data);
    }
    else
    {
        cout << "ALREADY\n";
    }

    return root;
}

void Search(Node *root, long long data)
{
    if (!root)
    {
        cout << "NO\n";
    }
    else if (data < root->data)
    {
        Search(root->left, data);
    }
    else if (data > root->data)
    {
        Search(root->right, data);
    }
    else
    {
        cout << "YES\n";
    }
}

void Printtree(Node *root, int deepness)
{
    if (!root)
    {
        return;
    }

    Printtree(root->left, deepness + 1);

    for (int i = 0; i < deepness; i++)
    {
        cout << ".";
    }
    cout << root->data << "\n";

    Printtree(root->right, deepness + 1);
}
int main()
{
    string tmp;
    Node *root = nullptr;

    vector<string> commands;

    while (cin >> tmp)
    {
        commands.push_back(tmp);
    }

    for (int i = 0; i < commands.size();)
    {
        if (commands[i] == "ADD")
        {
            int data = atoi(commands[i + 1].c_str());
            root = Add(root, data);
            i += 2;
        }
        else if (commands[i] == "SEARCH")
        {
            int data = atoi(commands[i + 1].c_str());
            Search(root, data);
            i += 2;
        }
        else
        {
            Printtree(root, 0);
            i++;
        }
    }

    return 0;
}