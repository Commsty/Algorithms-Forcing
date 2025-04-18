#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> arr;

        while (temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> result;
        int i = 0, j = arr.size() - 1;
        while (i < j)
        {
            result.push_back(arr[i++]);
            result.push_back(arr[j--]);
        }
        if (arr.size() % 2)
            result.push_back(arr[i]);

        temp = head;
        i = 0;
        while (temp)
        {
            temp->val = result[i++];
            temp = temp->next;
        }
    }
};